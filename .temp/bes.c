/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bes.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 16:32:25 by mathmart          #+#    #+#             */
/*   Updated: 2021/11/21 16:33:56 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Solong.h"

void    bresenham_line(t_point p0, t_point p1, t_data *data, int color)
{
	int dx =  abs (p1.x - p0.x);
	int dy = -abs (p1.y - p0.y);
	int sx = p0.x < p1.x ? 1 : -1;
	int sy = p0.y < p1.y ? 1 : -1; 
	int err = dx + dy;
	int e2 = err;

	while (1)
	{
		//Put px
		if (p0.x == p1.x && p0.y == p1.y)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			p0.x += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			p0.y += sy;
		}
	}
}
