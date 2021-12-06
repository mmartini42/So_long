/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_get_wall_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:30:47 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/06 17:59:37 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solong.h"

void	so_get_wall_pos(t_game *game)
{
	size_t	i;
	size_t	j;
	int	x;
	int	y;

	i = 0;
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j])
		{
			if (game->map->map[i][j] == '1'){
				y = get_render_y(game, i * game->wall->height);
				x = get_render_x(game, j * game->wall->width);
			/* 	bettermlx_put_image(game->window, game->wall, \
					get_render_x(game, j * game->wall->width), \
					get_render_y(game, i * game->wall->height)); */
				mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr, game->wall->img_ptr, x, y);}
			j++;
		}
		i++;
	}

}
