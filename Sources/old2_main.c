/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old2_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:58:44 by mathmart          #+#    #+#             */
/*   Updated: 2021/11/26 23:28:49 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Solong.h"
/*
static int	ft_close(int keykode, t_data *vars)
{
	if (keykode == KEY_ESC)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (1);
}

static void	ft_init(t_data *data)
{
	data->img = NULL;
	data->addr = NULL;
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->endian = 0;
	data->posx = 0;
	data->posy = 0;
	data->img = NULL;
	data->mlx = NULL;
	data->win = NULL;
	data->argb.colors = 0;
}

static void	ft_pixel_put(t_data *data, int x, int y, int color)
{
	char	*d;

	d = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)d = color;
}

static t_argb	ft_argb(size_t r, size_t g, size_t b, size_t a)
{
	t_argb	argb;

	argb.t_pxl.a = a;
	argb.t_pxl.r = r;
	argb.t_pxl.g = g;
	argb.t_pxl.b = b;
	return (argb);
}

 static void	ft_change(t_data *data, size_t width, size_t height)
{
	size_t	i;
	size_t	j;

	i = data->posx;
	while (i < height)
	{
		j = data->posy;
		while (j < width)
		{
			ft_pixel_put(data, i, j, data->argb.colors);
			j++;
		}
		i++;
	}
}

static void	ft_clear(t_data *data, size_t width, size_t height)
{
	size_t i;
	size_t j;

	i = 0;
	data->argb = ft_argb(0, 0, 0, 0);
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			ft_pixel_put(data, i, j, data->argb.colors);
			j++;
		}
		i++;
	}
	
} */

/* 
//DEplacement de base
static int	ft_move(int keycode, t_data **data)
{
	printf("\033[1;32m %d         %d\033[0m\n", keycode, (*data)->key.key_right);
	if ((*data)->key.key_right == true)
		(*data)->posx++;
	if (keycode == KEY_S)
		(*data)->posy++;
	if (keycode == KEY_W)
		(*data)->posy--;
	if (keycode == KEY_A)
		(*data)->posx--;
	return (0);
}

static int	ft_realese(int keycode, t_data *data)
{
	if (keycode == KEY_D)
		data->key.key_right = false;
	return (0);
}

static int	ft_press(int keycode, t_data *data)
{
	if (keycode == KEY_D)
	{
		data->key.key_right = true;
		ft_move(keycode, &data);
	}
	return (0);
	// if................
}

static int	ft_exec(t_data *data)
{
	data->argb = ft_argb(22, 235, 66, 0);
	mlx_hook(data->win, KeyPress, KeyPressMask, ft_press, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, ft_realese, data);
	ft_change(data, 730, 800);
	mlx_put_image_to_window(data->mlx, data->win, data->img, data->posx, data->posy);
	mlx_do_sync(data->mlx);
	return (1);
} */

/* static int	ft_red_cross(int keycode, t_data *data)
{
	(void)keycode;
	if (data == NULL)
		puts("ft_red_cross - a");
	if (data->mlx == NULL)
		puts("ft_red_cross - b");
	if (data->img == NULL)
		puts("ft_red_cross - c");
	puts("ft_red_cross - d");
	mlx_destroy_image(data->mlx, data->img);
	puts("ft_red_cross - e");
	dprintf(1,"TEGUYYTIDSASUYYXIF");
	// mlx_destroy_window(data->mlx, data->win);
	return (1);
} */

int	close_esc(int keycode, t_window *window)
{
	if (keycode == KEY_ESC)
	{
		bettermlx_destroy_window(&window);
		exit(0);
		return (0);
	}
	return (1);
}

int	close_game(t_window *window)
{
	bettermlx_destroy_window(&window);
	exit(0);
	return (0);
}

int	loop(t_window *window)
{
	// bettermlx_clean_display(window);
	// mlx_string_put(window->mlx_ptr, window->win_ptr, 1, 5, 0xff5574f, "Ceci est un test");
	bettermlx_render(window);
	// mlx_do_sync(window->win_ptr);
	return (1);
}

// static void	*image;

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

static void	put_image(t_window *data, int target_x, int target_y, t_image *image)
{
	for (int x = 0; x < data->width; x += 1)
	{
		for (int y = 0; y < data->height; y += 1)
		{
			int color = get_pixel(image->img_addr, image->size_line, image->bits_per_pixel, x, y);
			int t = (color >> (3 * 8)) & 0xff;
			if (t != 255)
				set_pixel (data->image->img_addr, image->size_line, image->bits_per_pixel, target_x + x, target_y + y, color);
		}
	}
}

int	main(void)
{
	/* t_data	data;

	ft_init(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920,  1080, "Solong");
	data.img = mlx_new_image(data.mlx, 1920,1080);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	//ft_change(&data, 730, 800);
	// mlx_put_image_to_window(data.mlx, data.win, data.img, 120, 100);
	data.posx = 120; data.posy = 200;
	// mlx_loop_hook(data.mlx, ft_exec, &data);
	mlx_hook(data.win, DestroyNotify, 1L << 5, ft_red_cross, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, ft_close, &data);
	mlx_loop(data.mlx); */
	t_window	*window;
	t_image		*text1;
	t_image		*image;

	window = bettermlx_init_window("Mon titre", 1000, 500, 1);
	image = bettermlx_init_image(window, 1920, 1080);
	text1 = bettermlx_init_xpm_image(window, "/Sources/Xpm/Marvin.xpm");
	mlx_hook(window->win_ptr, 17, 1L << 5, &close_game, window);
	put_image(window, 10, 15, image);
	bettermlx_render(window);
	bettermlx_hook(window, KEY_PRESS, &close_esc, window);
	bettermlx_register_loop(window, window, loop);
	// bettermlx_destroy_image(window, &image);
	return (0);
}