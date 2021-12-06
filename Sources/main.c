/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 23:30:32 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/06 18:08:00 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solong.h"

static void	so_hook(t_game *game)
{
	bettermlx_hook(game->window, KEY_PRESS, &so_press, game);
	bettermlx_hook(game->window, KEY_RELEASE, &so_realese, game);
	so_move(game);
	bettermlx_hook(game->window, DESTROY_NOTIFY, &so_redcross, game);
}

static void	so_put_ground(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->window->height)
	{
		x = 0;
		{
			while (x < game->window->width)
			{
				// bettermlx_put_image(game->window, game->img_player, x, y);
				mlx_put_image_to_window(game->window->mlx_ptr, \
				game->window->win_ptr, game->dirt->img_ptr, x, y);
				x += game->dirt->width;
			}
			y += game->dirt->height;
		}
	}
}

static int	render_loop(t_game *game)
{
	bettermlx_clean_display(game->window);
	so_put_ground(game);
	so_get_wall_pos(game);
	so_hook(game);
/* 	bettermlx_put_image(game->window, game->img_player,\
		get_render_x(game, game->player->pos_x), \
		get_render_y(game, game->player->pos_y)); */
	mlx_put_image_to_window(game->window->mlx_ptr, \
				game->window->win_ptr, game->img_player->img_ptr, \
				get_render_x(game, game->player->pos_x), \
				get_render_y(game, game->player->pos_y));
	// bettermlx_render(game->window);
	// mlx_do_sync (game->window->mlx_ptr);
	return (0);
}

static t_player	*so_init_player(void)
{
	t_player	*player;

	player = ft_calloc(1, sizeof(t_player));
	if (!player)
		return (NULL);
	player->pos_x = 0;
	player->pos_y = 0;
	return (player);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (so_parsing_errors(&game, ARGUMENT_ERRORS));
	game.map = so_init_map();
	game.player = so_init_player();
	if (so_parsing(&game, av[1]) == false)
		return (EXIT_FAILURE);
	so_init(&game);
	bettermlx_register_loop(game.window, &game, render_loop);
	// mlx_loop(game.window->mlx_ptr);
}