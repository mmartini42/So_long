/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:33:54 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/10 15:33:55 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	distance2(float a, float b)
{
	return (sqrt(distance_square2(a, b)));
}
