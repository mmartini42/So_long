/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_get_wall_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:30:47 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/06 18:11:22 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solong.h"

void	so_get_wall_pos(t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			if (game->map->map[y][x] == '1')
			{
				mlx_put_image_to_window(game->window->mlx_ptr, \
				game->window->win_ptr, game->wall->img_ptr, \
				get_render_x(game, x * game->wall->width), \
				get_render_y(game, y * game->wall->width));
				}
			x++;
		}
		y++;
	}

}
