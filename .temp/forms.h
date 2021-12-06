/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forms.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:19:42 by mathmart          #+#    #+#             */
/*   Updated: 2021/11/24 18:20:28 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMS_H
# define FORMS_H

#include <stdlib.h>

typedef struct s_line
{
	size_t	start;
	size_t	stop;
	size_t	y;
	size_t	x;
}				t_line;

typedef struct	s_bes
{
	int	x_0;
	int	x_1;
	int	y_0;
	int	y_1;
	
}				t_bes;

typedef struct	s_circle
{
	float	center;
	float	x_pos;
	float	y_pos;
	size_t	steps;
	float	r;
}				t_circle;

typedef struct s_rect
{
	size_t	x_left;
	size_t	x_right;
	size_t	y_up;
	size_t	y_down;
}				t_rect;

typedef struct s_squ
{
	size_t	up_l;
	size_t	down_l;
	size_t	up_r;
	size_t	down_r;
}				t_squ;

#endif
