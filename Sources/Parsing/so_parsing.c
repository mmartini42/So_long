/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:37:23 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/07 18:39:02 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solong.h"

static int	so_open(t_game *game, char *path_map)
{
	int		fd1;

	fd1 = open(path_map, O_RDONLY);
	if (fd1 == -1)
		so_kill_open(game);
	game->map->my_file = ft_open_file(path_map, O_RDONLY);
	if (!read(game->map->my_file->c_fd, 0, 0))
		return (false);
	return (EXIT_SUCCESS);
}

static bool	so_check_value(t_game *game)
{
	size_t			i;
	const size_t	size = game->map->map_width;

	i = 0;
	while (game->map->map[i])
	{
		if (ft_strlen(game->map->map[i]) != size)
			return (false);
		i++;
	}
	return (true);
}

static bool	so_get_map(t_game *game)
{
	short	status;

	status = 0;
	while (ft_read_next_line(game->map->my_file) == read_success)
	{
		game->map->map_height++;
		game->map->map = ft_add_str_to_str_array(game->map->map, \
			ft_strdup(game->map->my_file->readed_line), TRUE);
		if (status == 0)
		{
			game->map->map_width = ft_strlen(game->map->map[0]);
			status = 1;
		}
	}
	game->map->map_height++;
	game->map->map = ft_add_str_to_str_array(game->map->map, \
		ft_strdup(game->map->my_file->readed_line), TRUE);
	return (so_check_value(game));
}

static bool	so_get_p_position(t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			if (game->map->map[y][x] == 'P')
			{
				game->player->pos_x = x;
				game->player->pos_y = y;
				return (true);
			}
			x++;
		}
		y++;
	}
	return (false);
}

bool	so_parsing(t_game *game, char *path_map)
{
	int		fd1;

	fd1 = open(path_map, O_DIRECTORY);
	if (fd1 != -1)
		so_kill_open(game);
	if (so_open(game, path_map) == EXIT_FAILURE)
		return (so_parsing_errors(game, OPEN_ERRORS));
	if (so_get_map(game) == false)
		return (so_parsing_errors(game, MAP_ERRORS));
	ft_close_file(game->map->my_file);
	so_get_p_position(game);
	if (so_check_char(game) == false)
		return (false);
	if (so_validate_map(game->map, game->player->pos_x, \
		game->player->pos_y) == false)
		return (false);
	close(fd1);
	return (true);
}
