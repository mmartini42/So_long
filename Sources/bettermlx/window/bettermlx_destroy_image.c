/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_destroy_image.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:42:21 by mathmart          #+#    #+#             */
/*   Updated: 2021/11/25 20:42:22 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solong.h"

void	*bettermlx_destroy_image(t_window *window, t_image **image)
{
	if (*image != NULL)
	{
		mlx_destroy_image(window->mlx_ptr, (*image)->img_ptr);
		free(*image);
		*image = NULL;
	}
	return (NULL);
}
