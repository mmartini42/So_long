/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_vector_coord.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:34:15 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/10 15:34:16 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector3	div_vector_coord(	\
	t_vector3 vector,			\
	float divx,					\
	float divy,					\
	float divz)
{
	return (create_vector(vector.vx / divx, vector.vy / divy,
			vector.vz / divz));
}
