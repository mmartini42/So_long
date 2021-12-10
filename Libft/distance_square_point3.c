/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_square_point3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:33:37 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/10 15:33:38 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	distance_square_point3(t_point3 point_a, t_point3 point_b)
{
	return (distance_square3(point_b.x - point_a.x, point_b.y - point_a.y,
			point_b.z - point_a.z));
}
