/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:10:25 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/06 18:19:01 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solong.h"

void	so_move(t_game *game)
{
	t_player	*player;
	char		**map;

	player = game->player;
	map = game->map->map;
	if (player->key.key_right == true)
		so_get_right(game);
	if (player->key.key_left == true)
		so_get_left(game);
	if (player->key.key_up == true)
		so_get_up(game);
	if (player->key.key_down == true)
		so_get_down(game);
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