/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:10:25 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/06 17:02:43 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solong.h"

bool	so_intersect(t_game *game)
{
	t_player	*player;
	t_image		*img;
	t_image		*wall;

	img = game->img_player;
	wall = game->wall;
	player = game->player;
	printf("%d  -  %d\n", (player->pos_x / 80) * 80, (player->pos_x / 80) * 80 + wall->width);
	return ((player->pos_x < (player->pos_x / 80) * 80 + wall->width)
		&& (player->pos_x + game->img_player->width > (player->pos_x / 80) * 80)
		&& (player->pos_y < (player->pos_y / 80) * 80 + wall->height)
		&& (player->pos_y + game->img_player->height > (player->pos_y / 80) * 80));
}

void	so_move(t_game *game)
{
	t_player	*player;
	char		**map;

	player = game->player;
	map = game->map->map;
	if (player->key.key_right == true)
	{
		if ((map[player->pos_y / 80][(player->pos_x + \
			game->img_player->width + MOVE_SPEED) / 80] != '1'))
			player->pos_x += MOVE_SPEED;
		else
			player->pos_x = (player->pos_x + game->img_player->width + \
			MOVE_SPEED) / 80 * 80 - game->img_player->width;
	}
	if (player->key.key_left == true) // gauche
	{
		if (map[player->pos_y / 80][(player->pos_x - MOVE_SPEED)/ 80] != '1')
			player->pos_x -= MOVE_SPEED;
		else
			player->pos_y = (player->pos_y - MOVE_SPEED) / 80 * 80 + game->wall->width;
	}
	if (player->key.key_up == true) // haut
	{
		if (map[(player->pos_y - MOVE_SPEED) / 80][player->pos_x / 80] != '1')
			player->pos_y -= MOVE_SPEED;
		else
			player->pos_y = (player->pos_y - MOVE_SPEED) / 80 * 80 + game->wall->height;
	}
	if (player->key.key_down == true) // bas
	{
		if (map[(player->pos_y + game->img_player->height + MOVE_SPEED) / 80] \
			[player->pos_x / 80] != '1')
			player->pos_y += MOVE_SPEED;
		else
			player->pos_y = (player->pos_y + game->img_player->height + \
			MOVE_SPEED) / 80 * 80 - game->img_player->height;
	}
}


int	so_realese(int keycode, t_game *game)
{
	if (keycode == KEY_D)
		game->player->key.key_right = false;
	if (keycode == KEY_W)
		game->player->key.key_up = false;
	if (keycode == KEY_A)
		game->player->key.key_left = false;
	if (keycode == KEY_S)
		game->player->key.key_down = false;
	return (0);
}

int	so_press(int keycode, t_game *game)
{
	if (keycode == KEY_D)
		game->player->key.key_right = true;
	if (keycode == KEY_W)
		game->player->key.key_up = true;
	if (keycode == KEY_A)
		game->player->key.key_left = true;
	if (keycode == KEY_S)
		game->player->key.key_down = true;
	if (keycode == KEY_ESC)
		so_esc(keycode, game);
	return (0);
}