/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:55:12 by lduplain          #+#    #+#             */
/*   Updated: 2021/12/02 20:05:30 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solong.h"

t_bool	validate_map(t_map *map, int x, int y)
{
	if (x < 0 || x >= (int)map->map_width)
		return (FALSE);
	if (y < 0 || y >= (int)map->map_height)
		return (FALSE);
	if (map->map[y][x] == '1' || map->map[y][x] == -1)
		return (TRUE);
	map->map[y][x] = -1;
	if (!validate_map(map, x + 1, y))
		return (FALSE);
	if (!validate_map(map, x - 1, y))
		return (FALSE);
	if (!validate_map(map, x, y + 1))
		return (FALSE);
	if (!validate_map(map, x, y - 1))
		return (FALSE);
	return (TRUE);
}
