/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:49:44 by mathmart          #+#    #+#             */
/*   Updated: 2021/11/26 23:12:10 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Solong.h"

static void	ft_init(t_data *data)
{
	data->mlx = NULL;
	data->img = NULL;
	data->win = NULL;
	data->addr = NULL;
	data->posx = 0;
	data->posy = 0;
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->endian = 0;
	data->argb.colors = 0;
	data->img_height = 0;
	data->img_width = 0;
}

static int	ft_close(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		exit (0);
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

static void	put_image(t_data *data, void *target, int target_x, int target_y)
{
	int		line_len;
	int		bpx;
	int		endian;
	void	*addr;

	addr = mlx_get_data_addr (target, &bpx, &line_len, &endian);
	for (int x = 0; x < data->img_width; x += 1)
	{
		for (int y = 0; y < data->img_height; y += 1)
		{
			int color = get_pixel (data->addr, data->line_length, data->bits_per_pixel, x, y);
			int t = (color >> (3 * 8)) & 0xff;
			if (t != 255)
				set_pixel (addr, line_len, bpx, target_x + x, target_y + y, color);
		}
	}
}

static int	render_loop(t_data *data)
{
	put_image (data, image, 10, 10);
	put_image (data, image, 30, 35);
	mlx_put_image_to_window(data->mlx, data->win, image, 0, 0);
	mlx_do_sync (data->mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	// t_img	img;

	if (ac < 1)
		return (0);
	ft_init(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "./So_long");
 	data.img = mlx_xpm_file_to_image(data.mlx, av[1], &data.img_width, &data.img_height);
	if (data.img == NULL)
		return (0);
	image = mlx_new_image (data.mlx, 1920, 1080);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	//mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, 2, KeyPressMask, ft_close, &data);
	mlx_hook(data.win, 17, KeyPressMask, ft_close, &data);
	mlx_loop_hook(data.mlx, render_loop, &data);
	mlx_loop(data.mlx);
}
