/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_check_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 22:29:16 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/10 15:12:25 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solong.h"

void	so_check_pos(t_game *game)
{
	t_player	*player;
	t_map		*map;
	int			x;
	int			y;

	player = game->player;
	map = game->map;
	x = (player->pos_x / 80);
	y = (player->pos_y / 80);
	if ((x == map->star[1]) && (y == map->star[0]))
		game->map->p_star = false;
	if (game->map->p_star == false)
		if (x == map->exit[1] && y == map->exit[0])
			so_redcross(game);
}
