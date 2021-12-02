/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:33:03 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/02 00:13:35 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
# include "bettermlx_struct.h"
# include "bettermlx_func.h"
# include "../Mlx/mlx.h"
# include "X11/X.h"
# include "forms.h"

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_SPACE 49
# define true 1
# define false 0
# define MOOVE_SPEED 50

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


typedef struct	s_game
{
	t_window	*window;
	t_image		*dirt;
	t_image		*img_player;
	t_image		*wall;
	t_player	*player;
}			t_game;


int		so_esc(int keycode, t_window *Window);
int		so_redcross(t_window *window);
int		so_press(int keycode, t_game *game);
int		so_realese(int keycode, t_game *game);
void	so_move(t_game **game);
void	so_init(t_game *game);

#endif