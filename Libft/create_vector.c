/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:33:23 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/10 15:33:24 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector3	create_vector(float vx, float vy, float vz)
{
	t_vector3	vector;

	vector.vx = vx;
	vector.vy = vy;
	vector.vz = vz;
	return (vector);
}
