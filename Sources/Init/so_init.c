/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:41:07 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/02 19:05:09 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solong.h"

/* static t_player	*so_init_player(void)
{
	t_player	*player;

	player = ft_calloc(1, sizeof(t_player));
	if (!player)
		return (NULL);
	//INIT les pos avec le parsing
	player->pos_x = 0;
	player->pos_y = 0;
	return (player);
} */

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
	map->check_if_ok = false;
	return (map);
}

void	so_init(t_game *game)
{
	//game->player = so_init_player(/*ICI METTRE LA MAP POUR LA POSITION*/);
	game->window = bettermlx_init_window("test", 1080, 720, 1);
	game->dirt = bettermlx_init_xpm_image(game->window, "./Sources/Xpm/dirt.xpm");
	game->img_player = bettermlx_init_xpm_image(game->window, "./Sources/Xpm/Marvin80.xpm");
	game->wall = bettermlx_init_xpm_image(game->window, "./Sources/Xpm/wall1_80.xpm");
}
