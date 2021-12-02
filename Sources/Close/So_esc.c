/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_esc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:27:29 by mathmart          #+#    #+#             */
/*   Updated: 2021/11/30 17:49:25 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solong.h"

int	so_esc(int keycode, t_window *Window)
{
	if (keycode == KEY_ESCAPE)
	{
		bettermlx_destroy_window(&Window);
		//Penser a free les structs
		exit(0);
	}
	return (0);
}
