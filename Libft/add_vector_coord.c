/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vector_coord.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:32:31 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/10 15:32:33 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector3	add_vector_coord(	\
	t_vector3 vector,			\
	float vx,					\
	float vy,					\
	float vz)
{
	return (create_vector(vector.vx + vx, vector.vy + vy, vector.vz + vz));
}
