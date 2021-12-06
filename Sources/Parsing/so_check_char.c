/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_check_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:45:41 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/06 17:21:00 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solong.h"

static bool	so_error_map(t_game	*game)
{
	so_free_player(game->player);
	so_free_map(game->map);
	ft_putstr_err("Map Error2\n");
	return (false);
}

static bool	so_check_in_base(char c)
{
	const char	*base = "10CEP";
	size_t		i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (true);
		i++;
	}
	return (false);
}

static bool	so_check_char_ret(short *status, t_game *game)
{
	size_t	i;

	i = 0;
	while (i < 3)
	{
		if (status[i] != 1)
			break ;
		i++;
	}
	if (i != 3)
		return (so_error_map(game));
	return (true);
}

static bool	so_check_char_count(char **map, t_game *game)
{
	const char	*base = "CEP";
	size_t		i;
	size_t		j;
	short		status[3];

	i = -1;
	while (++i < 3)
		status[i] = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == base[0] && status[0] == 0)
				status[0] = 1;
			if (map[i][j] == base[1] && status[1] == 0)
				status[1] = 1;
			if (map[i][j] == base[2])
				status[2] += 1;
		}
	}
	return (so_check_char_ret(status, game));
}

bool	so_check_char(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j])
		{
			if (so_check_in_base(game->map->map[i][j]) == false)
				return (so_error_map(game));
			j++;
		}
		i++;
	}
	return (so_check_char_count(game->map->map, game));
}
