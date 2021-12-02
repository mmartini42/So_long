/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 23:30:32 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/02 19:06:55 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solong.h"

static void	so_hook(t_game *game)
{
	bettermlx_hook(game->window, KEY_PRESS, &so_press, game);
	// bettermlx_hook(game->window, KEY_PRESS, &so_esc, game->window);
	bettermlx_hook(game->window, KEY_RELEASE, &so_realese, game);
	so_move(&game);
	bettermlx_hook(game->window, DESTROY_NOTIFY, &so_redcross, game->window);
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
				bettermlx_put_image(game->window, game->dirt, x, y);
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
	so_hook(game);
	bettermlx_put_image(game->window, game->img_player,\
		game->player->pos_x, game->player->pos_y);
	bettermlx_render(game->window);
	mlx_do_sync (game->window->mlx_ptr);
	return (0);
}

static t_player	*so_init_player(void)
{
	t_player	*player;

	player = ft_calloc(1, sizeof(t_player));
	if (!player)
		return (NULL);
	//INIT les pos avec le parsing
	player->pos_x = 0;
	player->pos_y = 0;
	return (player);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		printf("Tes con ou quoi la MAPPP !!!!!\n");
		return (EXIT_FAILURE);
	}
	game.map = so_init_map();
	game.player = so_init_player();
	if (so_parsing(&game, av[1]) == false)
	{
		printf("MAPPP DE MERDEEE !!!!!!\n");
		return (EXIT_FAILURE);
	}
	so_init(&game);
	bettermlx_register_loop(game.window, &game, render_loop);
}