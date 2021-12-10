/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_vector_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:34:24 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/10 15:34:25 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector3	div_vector_value(t_vector3 vector, float to_div)
{
	return (div_vector_coord(vector, to_div, to_div, to_div));
}
