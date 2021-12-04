/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solong_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:26:03 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/03 17:13:45 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCT_H
# define SO_LONG_STRUCT_H

#include "Solong.h"

typedef union u_argb
{
	uint32_t colors;

	struct s_pxl
	{
		uint8_t b;
		uint8_t g;
		uint8_t r;
		uint8_t a;
	} t_pxl;

}			t_argb;

typedef struct s_keybool
{
	t_bool key_left;
	t_bool key_right;
	t_bool key_up;
	t_bool key_down;
}				t_keybool;

typedef	struct s_player
{
	int			pos_x;
	int			pos_y;
	t_keybool	key;
}				t_player;

typedef	struct s_map
{
	t_file *my_file;
	size_t	map_width;
	size_t	map_height;
	char	**map;
	char	*line;
	bool	check_if_ok;
}				t_map;

typedef enum	e_pars_errors
{
	ARGUMENT_ERRORS,
	OPEN_ERRORS,
	MAP_ERRORS,
	MAP_VALID_ERRORS,
}				t_pars_errors;

typedef struct	s_game
{
	t_window	*window;
	t_image		*dirt;
	t_image		*img_player;
	t_image		*wall;
	t_player	*player;
	t_map		*map;
}			t_game;

#endif