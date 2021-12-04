/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:10:04 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/03 16:58:46 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solong.h"

bool	so_validate_map(t_map *map, int x, int y)
{
	if (x < 0 || x >= (int)map->map_width)
		return (false);
	if (y < 0 || y >= (int)map->map_height)
		return (false);
	if (map->map[y][x] == '1' || map->map[y][x] == -1)
		return (true);
	map->map[y][x] = -1;
	if (!so_validate_map(map, x + 1, y))
		return (false);
	if (!so_validate_map(map, x - 1, y))
		return (false);
	if (!so_validate_map(map, x, y + 1))
		return (false);
	if (!so_validate_map(map, x, y - 1))
		return (false);
	return (true);
}
