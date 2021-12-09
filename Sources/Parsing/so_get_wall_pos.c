/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_get_wall_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:30:47 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/09 19:15:40 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solong.h"

void	so_get_cons_pos(t_game	*game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			if (game->map->map[y][x] == 'C')
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

void	so_get_wall_pos(t_game *game)
{
	size_t	y;
	size_t	x;
	int		r_x;
	int		r_y;

	y = 0;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			if (game->map->map[y][x] == '1')
			{
				r_x = get_render_x(game, x * game->wall->width);
				r_y = get_render_y(game, y * game->wall->height);
				if (r_x >= -game->window->width && r_x < game->window->width \
				&& r_y >= -game->window->height && r_y < game->window->height)
					mlx_put_image_to_window(game->window->mlx_ptr, \
						game->window->win_ptr, game->wall->img_ptr, r_x, r_y);
			}
			x++;
		}
		y++;
	}
}
