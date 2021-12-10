/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_get_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:40:02 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/10 15:11:23 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solong.h"

static void	so_errors(void)
{
	ft_putstr_err("Map Error\n");
	exit(EXIT_FAILURE);
}

void	so_get_exit(t_game *game)
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
			if (map[y][x] == 'E')
			{
				count += 1;
				if (count > 1)
					so_errors();
				game->map->exit[0] = y;
				game->map->exit[1] = x;
			}
		}
	}
}

void	so_put_exit(t_game *game)
{
	size_t	x;
	size_t	y;

	x = game->map->exit[1];
	y = game->map->exit[0];
	mlx_put_image_to_window(game->window->mlx_ptr, \
		game->window->win_ptr, game->exit->img_ptr, \
		get_render_x(game, x * game->exit->width), \
		get_render_y(game, y * game->exit->height));
}
