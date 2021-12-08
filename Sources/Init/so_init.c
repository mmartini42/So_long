/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:41:07 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/09 00:21:47 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solong.h"

float	get_render_x(t_game *game, float x)
{
	return (game->window->width * 0.5 - game->player->pos_x + \
		x - game->img_player->width * 0.5);
}

float	get_render_y(t_game *game, float y)
{
	return (game->window->height * 0.5 - game->player->pos_y + \
		y - game->img_player->height * 0.5);
}

static void	so_init_player_pos(t_player *player, t_image *dirt)
{
	player->pos_x *= dirt->width;
	player->pos_y *= dirt->height;
}

t_map	*so_init_map(void)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->map_height = 0;
	map->map_width = 0;
	map->line = NULL;
	map->map = NULL;
	map->wall = NULL;
	map->p_star = true;
	map->check_if_ok = false;
	return (map);
}

void	so_init(t_game *game)
{
	game->window = bettermlx_init_window("So_long", 1280, 720, 1);
	game->dirt = bettermlx_init_xpm_image(game->window, \
		"./Sources/Xpm/bg2.xpm");
	game->img_player = bettermlx_init_xpm_image(game->window, \
		"./Sources/Xpm/Marvin80.xpm");
	so_init_player_pos(game->player, game->dirt);
	game->wall = bettermlx_init_xpm_image(game->window, \
		"./Sources/Xpm/wall1_80.xpm");
	game->exit = bettermlx_init_xpm_image(game->window, \
		"./Sources/Xpm/exit80.xpm");
	game->star = bettermlx_init_xpm_image(game->window, \
		"./Sources/Xpm/star.xpm");
	game->mov = 0;
}
