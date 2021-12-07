/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_kill_open.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:49:34 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/07 18:34:52 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solong.h"

void	so_kill_open(t_game *game)
{
	so_free_map(game->map);
	so_free_player(game->player);
	ft_putstr_err("Map Error\n");
	exit(EXIT_FAILURE);
}
