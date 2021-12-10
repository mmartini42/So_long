/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_interval.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:33:14 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/10 15:33:15 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_interval	create_interval(float istart, float istop)
{
	t_interval	interval;

	interval.istart = istart;
	interval.istop = istop;
	return (interval);
}
