/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_check_last_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:45:13 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/10 19:08:03 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solong.h"

static void	so_errors_map(t_game *game)
{
	ft_destroy_string_array(&game->map->map);
	ft_putstr_errnl("Map error");
	exit(EXIT_FAILURE);
}

static	bool	so_check_line(char *map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '1')
			return (false);
		i++;
	}
	return (true);
}

void	so_check_last_line(t_game *game)
{
	size_t	x;
	size_t	y;
	char	**map;

	y = 0;
	map = game->map->map;
	while (map[y])
	{
		x = 0;
		if (!map[y + 1] || map[y + 1][x] != map[y][x])
		{
			if (so_check_line(map[y]) == false)
				so_errors_map(game);
		}
		y++;
	}
}