/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_get_stars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:12:56 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/10 14:58:09 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solong.h"

static void	so_error_star(void)
{
	ft_putstr_err("Map Error\n");
	exit(EXIT_FAILURE);
}

void	so_get_star(t_game *game)
{
	char	**map;
	size_t	y;
	size_t	x;
	int		count;

	y = -1;
	count = 0;
	map = game->map->map;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'C')
			{
				count += 1;
				if (count > 1)
					so_error_star();
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
