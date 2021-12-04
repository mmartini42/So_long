/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solong_function.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:30:54 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/03 20:01:01 by mathmart         ###   ########.fr       */
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


void	so_move(t_game **game);

/* INIT */
void	so_init(t_game *game);


/* PARSING */
bool	so_parsing(t_game *game, char *path_map);
char	*get_next_line(int fd);
t_map	*so_init_map(void);
bool	so_validate_map(t_map *level, int x, int y);
bool	so_check_char(t_game *game);

/* ERRORS */
bool	so_parsing_errors(t_game *game, int status);

/* MEMORY */
void	so_free_map(t_map *map);
void	so_free_player(t_player *player);


#endif