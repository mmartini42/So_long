/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_get_stars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:12:56 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/08 19:39:02 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solong.h"

void	so_get_star(t_game *game)
{
	char	**map;
	size_t	y;
	size_t	x;

	y = -1;
	map = game->map->map;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'C')
			{
				game->map->star[0] = y;
				game->map->star[1] = x;
			}
		}
	}
}

void	so_put_star(t_game *game)
{
	size_t	x;
	size_t	y;

	x = game->map->star[1];
	y = game->map->star[0];
	mlx_put_image_to_window(game->window->mlx_ptr, \
		game->window->win_ptr, game->star->img_ptr, \
		get_render_x(game, x * game->star->width), \
		get_render_y(game, y * game->star->height));

}
