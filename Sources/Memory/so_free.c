/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:21:25 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/03 17:41:06 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solong.h"

void	so_free_player(t_player *player)
{
	free(player);
	player = NULL;
}

void	so_free_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	map->map = NULL;
	if (map->line)
		free(map->line);
	map->line = NULL;
	free(map);
	map = NULL;
}

