/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vector_vector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:32:36 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/10 15:32:38 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector3	add_vector_vector(	\
	t_vector3 vector,			\
	t_vector3 to_add)
{
	return (add_vector_coord(vector, to_add.vx, to_add.vy, to_add.vz));
}
