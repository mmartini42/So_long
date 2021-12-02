/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Put_groud.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:05:39 by mathmart          #+#    #+#             */
/*   Updated: 2021/11/27 18:05:52 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solong.h"

static int	ft_close(int keycode, t_window *Window)
{
	if (keycode == KEY_ESCAPE)
	{
		bettermlx_destroy_window(&Window);
		exit(0);
	}
	return (0);
}

static void	*image;

static int	get_pixel(void *data, int line_len, int bpx, int x, int y)
{
	size_t	offset;
	offset = line_len * y + x * (bpx / 8);
	return (*((int *)(data + offset)));
}

static void	set_pixel(void *data, int line_len, int bpx, int x, int y, int color)
{
	size_t	offset;
	offset = line_len * y + x * (bpx / 8);
	*((int *)(data + offset)) = color;
}

static void	put_image(t_window *window, void *target, int target_x, int target_y)
{
	int size_line;
	int bits_per_pixel;
	int endian;
	void	*addr = mlx_get_data_addr (target, &bits_per_pixel, &size_line, &endian);
	for (int x = 0; x < window->image->width; x += 1)
	{
		for (int y = 0; y < window->image->height; y += 1)
		{
			int color = get_pixel (window->image->img_addr, window->image->size_line, window->image->bits_per_pixel, x, y);
			int t = (color >> (3 * 8)) & 0xff;
			if (t != 255)
				set_pixel (addr, size_line, bits_per_pixel, target_x + x, target_y + y, color);
		}
	}
}

static void	put_ground(t_window *window)
{
	int	x;
	int	y;

	y = 0;
	while (y < window->height)
	{
		x = 0;
		{
			while (x < window->width)
			{
				put_image(window, image, x, y);
				x += window->image->width;
			}
			y += window->image->height;
		}
	}
}