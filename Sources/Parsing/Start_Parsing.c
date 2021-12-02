
#include "Solong.h"

int	so_open(t_game *game, char *path_map)
{
	int		fd1;
	int		fd2;

	fd1 = open(path_map, O_DIRECTORY);
	fd2 = open(path_map, O_RDONLY);
	if ((fd1 == -1) && (fd2 != -1))
	{
		close(fd1);
		close(fd2);
		puts(path_map);
		game->map->my_file = ft_open_file(path_map, O_RDONLY);
		return (EXIT_SUCCESS);
	}
	close(fd1);
	close(fd2);
	return (EXIT_FAILURE);
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

	status	= 0;
	while (ft_read_next_line(game->map->my_file) == read_success)
	{
		game->map->map_height++;
		game->map->map = ft_add_str_to_str_array(game->map->map, ft_strdup(game->map->my_file->readed_line), TRUE);
		if (status == 0)
		{
			game->map->map_width = ft_strlen(game->map->map[0]);
			status = 1;
		}
	}
	game->map->map_height++;
	game->map->map = ft_add_str_to_str_array(game->map->map, ft_strdup(game->map->my_file->readed_line), TRUE);
	return (so_check_value(game));
}

/* bool	so_pars_fist_or_last_line(char *line)
{
	int	i;

	i = -1;
	while (line[++i] != NULL)
	{
		if (line[i] != '1')
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
} */

/* bool	autorised_char(t_game *game, int i)
{
	if (i == '1' || i == '0')
		return (EXIT_SUCCESS);
	else if (i == 'C')
		.
	i == 'E' || i == 'P')
}

bool	so_check_other_line(char **map, int pos_y)
{
	int index_line;

	index_line = 0;
	i = 1;
	size_first_line = game->map->map[0];
	so_pars_fist_or_last_line(game->map->map[0]);
	while (game->map->map[i])
	{
		if (size_first_line != ft_strlen(game->map->map[i]))
			return (EXIT_FAILURE);
		if (i == game->map->map_height)
			if (so_pars_fist_or_last_line(game->map->map[i]) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		else if (so_check_other_line(game->map->map, i) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
} */

static bool so_get_p_position(t_game *game)
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
	if (so_open(game, path_map) == EXIT_FAILURE)
		return (false);
	if (so_get_map(game) == false)
		return (false);
	so_get_p_position(game);
	if (validate_map(game->map, game->player->pos_x, game->player->pos_y) == FALSE)
		return (false);
	puts("OK");
/* 	if (so_check_size_line(game) == EXIT_FAILURE)
		return (EXIT_FAILURE); */
	return (true);
}