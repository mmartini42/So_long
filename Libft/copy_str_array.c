/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_str_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:32:47 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/10 15:32:48 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**copy_str_array(char **str_array)
{
	char	**new_array;
	size_t	index;

	new_array = NULL;
	index = 0;
	while (str_array[index])
	{
		new_array = ft_add_str_to_str_array(new_array,
				ft_strdup(str_array[index]),
				TRUE);
		index++;
	}
	return (new_array);
}
