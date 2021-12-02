/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 02:20:52 by mathmart          #+#    #+#             */
/*   Updated: 2021/11/27 16:39:15 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solong.h"

static void	*img;

static int	ft_close(int keycode, t_window *Window)
{
	if (keycode == KEY_ESCAPE)
	{
		bettermlx_destroy_window(&Window);
		exit(0);
	}
	return (0);
}

static int	ft_loop(t_window *window)
{
	// bettermlx_clean_display(window);
	bettermlx_render(window);
	mlx_do_sync(window->mlx_ptr);
	return (0);
}

int	main(void)
{
	t_window	*window;

	window = bettermlx_init_window("TEST", 1920, 1080, 1);
	// window->image = bettermlx_init_image(window, 1920, 1080);
	window->image = bettermlx_init_xpm_image(window, "./Sources/Xpm/dirt.xpm");
	img = bettermlx_init_image(window, 1920, 1080);
	// mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->image->img_ptr, 0, 0);
	bettermlx_hook(window, KEY_PRESS, ft_close, window);
	bettermlx_register_loop(window, window, ft_loop);
}