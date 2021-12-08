/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solong_function.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:30:54 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/08 22:43:34 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_FUNCTION_H
# define SOLONG_FUNCTION_H

#include "Solong.h"

/* CLOSE */
int		so_esc(int keycode, t_game *game);
int		so_redcross(t_game *game);

/* HOOK */
int		so_press(int keycode, t_game *game);
int		so_realese(int keycode, t_game *game);


void	so_move(t_game *game);

/* INIT */
void	so_init(t_game *game);


/* PARSING */
bool	so_parsing(t_game *game, char *path_map);
char	*get_next_line(int fd);
t_map	*so_init_map(void);
bool	so_validate_map(t_map *level, int x, int y);
bool	so_check_char(t_game *game);
void	so_get_wall_pos(t_game *game);
void	so_put_star(t_game *game);
void	so_put_exit(t_game *game);
void	so_get_star(t_game *game);
void	so_get_exit(t_game *game);
void	so_check_pos(t_game *game);


/* CAMERA */
float	get_render_x(t_game *game, float x);
float	get_render_y(t_game *game, float y);

/* MOVE */
void	so_get_right(t_game *game);
void	so_get_left(t_game *game);
void	so_get_down(t_game *game);
void	so_get_up(t_game *game);


/* ERRORS */
bool	so_parsing_errors(t_game *game, int status);
void	so_kill_open(t_game *game);

/* MEMORY */
void	so_free_map(t_map *map);
void	so_free_player(t_player *player);

#endif