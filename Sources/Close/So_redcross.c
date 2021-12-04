/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_redcross.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:30:23 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/03 20:02:06 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solong.h"

int	so_redcross(t_game *game)
{
	t_window *win;

	win = game->window;
	bettermlx_destroy_window(&win);
	so_free_player(game->player);
	so_free_map(game->map);
	exit(0);
	return (0);
}