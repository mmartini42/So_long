/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_point3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:33:27 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/10 15:33:28 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	distance_point3(t_point3 point_a, t_point3 point_b)
{
	return (sqrt(distance_square_point3(point_a, point_b)));
}
