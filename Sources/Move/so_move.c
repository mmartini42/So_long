/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:10:25 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/03 20:41:08 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solong.h"

void	so_move(t_game **game)
{
	int true_y;
	int true_x;
	int	p_value;

	true_y = (*game)->player->pos_y + (*game)->img_player->height;
	true_x = (*game)->player->pos_x + (((*game)->img_player->width / 4));
	p_value =  (((*game)->window->width - (*game)->img_player->width));
	if ((*game)->player->key.key_right == true)
		if (((*game)->player->pos_x) < p_value)
		{
			printf("%d           %d\n", p_value, (*game)->player->pos_x);
			(*game)->player->pos_x += MOOVE_SPEED;
		}
 	if ((*game)->player->key.key_left == true)
		if ((true_x - MOOVE_SPEED) > 0)
			(*game)->player->pos_x -= MOOVE_SPEED;
	if ((*game)->player->key.key_up == true)
		if (((*game)->player->pos_y - MOOVE_SPEED ) >= 0)
			(*game)->player->pos_y -= MOOVE_SPEED;
	if ((*game)->player->key.key_down == true)
		if ((true_y) < (*game)->window->height)
			(*game)->player->pos_y += MOOVE_SPEED;
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