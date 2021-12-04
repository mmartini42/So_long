/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_parsing_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:04:48 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/04 16:19:18 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solong.h"

static void	so_error_arguments(t_game *game)
{
	(void)game;
	ft_putstr_err("Error need more argurments\n");
	exit(EXIT_FAILURE);
}

static void	so_error_open(t_game *game)
{
	ft_close_file(game->map->my_file);
	so_free_map(game->map);
	so_free_player(game->player);
	ft_putstr_err("Map Error\n");
}

static void	so_error_map(t_game *game)
{
	ft_close_file(game->map->my_file);
	so_free_map(game->map);
	so_free_player(game->player);
	ft_putstr_err("Map Error\n");
}

static void	so_init_pars_errors(void (*so_pars_errors[3])(t_game *))
{
	so_pars_errors[0] = so_error_arguments;
	so_pars_errors[1] = so_error_open;
	so_pars_errors[2] = so_error_map;
}

bool	so_parsing_errors(t_game *game, int status)
{
	void	(*so_pars_errors[3])(t_game *);

	so_init_pars_errors(so_pars_errors);
	so_pars_errors[status](game);
	return (false);
}
