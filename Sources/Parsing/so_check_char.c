/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_check_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:45:41 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/03 18:34:53 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solong.h"

static bool	so_error_map(t_game	*game)
{
	so_free_player(game->player);
	so_free_map(game->map);
	ft_putstr_err("Map Error2");
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
	printf("%d\n", c);
	return (false);
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
	return (true);
}
