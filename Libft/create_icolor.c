/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_icolor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:33:03 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/10 15:33:07 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_color	create_icolor(int a, int r, int g, int b)
{
	return (create_color((unsigned char)a, (unsigned char)r,
			(unsigned char)g, (unsigned char)b));
}
