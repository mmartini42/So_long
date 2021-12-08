/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_gets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:13:35 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/09 00:06:34 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solong.h"

void	so_get_right(t_game *game)
{
	t_player	*player;
	char		**map;

	player = game->player;
	map = game->map->map;
	if ((map[player->pos_y / 80][(player->pos_x + \
			game->img_player->width + MOVE_SPEED) / 80] != '1'))
			player->pos_x += MOVE_SPEED;
	else
		player->pos_x = (player->pos_x + game->img_player->width + \
		MOVE_SPEED) / 80 * 80 - game->img_player->width;
	game->mov += 1;
	printf("%d\n", game->mov);
}

void	so_get_left(t_game *game)
{
	t_player	*player;
	char		**map;

	player = game->player;
	map = game->map->map;
	if (map[player->pos_y / 80][(player->pos_x - MOVE_SPEED) / 80] != '1')
		player->pos_x -= MOVE_SPEED;
	else
		player->pos_y = (player->pos_y - MOVE_SPEED) / 80 * \
			80 + game->wall->width;
	game->mov += 1;
	printf("%d\n", game->mov);
}

void	so_get_up(t_game *game)
{
	t_player	*player;
	char		**map;

	player = game->player;
	map = game->map->map;
	if (map[(player->pos_y - MOVE_SPEED) / 80][player->pos_x / 80] != '1')
		player->pos_y -= MOVE_SPEED;
	else
		player->pos_y = (player->pos_y - MOVE_SPEED) / 80 * \
			80 + game->wall->height;
	game->mov += 1;
	printf("%d\n", game->mov);
}

void	so_get_down(t_game *game)
{
	t_player	*player;
	char		**map;

	player = game->player;
	map = game->map->map;
	if (map[(player->pos_y + game->img_player->height + MOVE_SPEED) / 80] \
		[player->pos_x / 80] != '1')
		player->pos_y += MOVE_SPEED;
	else
		player->pos_y = (player->pos_y + game->img_player->height + \
		MOVE_SPEED) / 80 * 80 - game->img_player->height;
	game->mov += 1;
	printf("%d\n", game->mov);
}
