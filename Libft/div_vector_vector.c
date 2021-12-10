/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_vector_vector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:34:38 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/10 15:34:39 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector3	div_vector_vector(t_vector3 vector, t_vector3 to_div)
{
	return (div_vector_coord(vector, to_div.vx, to_div.vy, to_div.vz));
}
