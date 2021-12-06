/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:29:33 by mathmart          #+#    #+#             */
/*   Updated: 2021/11/22 15:53:49 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Bouton croix rouge == event 

#include "../Includes/Solong.h"

int	key_hook(int keycode, t_vars *vars)
{
	// printf("Hello from key_hook! hook nb = %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		// printf("NIKAGGEE DE MEREEEEE\n");
		exit(0);
		return (0);
	}
	return (0);
}

int	ft_close(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
	{
		// mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
		return (0);
	}
	return (0);
}

void	ft_pixel_put(t_data *data, int x, int y, int color)
{
	char	*d;

	d = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)d = color;
}

static t_argb	ft_argb(int r, int g, int b, int a)
{
	t_argb argb;

	argb.t_pxl.r = r;
	argb.t_pxl.g = g;
	argb.t_pxl.b = b;
	argb.t_pxl.a = a;
	return (argb);
}

static void	ft_display_square(t_data *data)
{
	size_t	i;
	size_t	j;

	i = data->square.up_l;
	while (i < data->square.down_r)
	{
		j = data->square.up_l;
		while (j < data->square.up_r)
		{
			ft_pixel_put(data, i, j, data->argb.colors);
			j++;
		}
		i++;
	}
}

static void ft_display_hori_line(t_data *data)
{
	size_t	i;

	i = data->line.start;
	while (i < data->line.stop)
	{
		ft_pixel_put(data, i, data->line.y, data->argb.colors);
		i++;
	}
}

static void	ft_display_triangle_rect(t_data *data)
{
	size_t	i;

	i = data->square.up_l;
	while (i < data->square.down_r)
	{
		data->line.start = i;
		data->line.y = i;
		data->line.stop = data->square.down_r;
		ft_display_hori_line(data);
		i++;
	}
}

static void	ft_display_vert_line(t_data *data)
{
	size_t	i;

	i = data->line.start;
	while (i < data->line.stop)
	{
		ft_pixel_put(data, data->line.x , i, data->argb.colors);
		i++;
	}
}

static void	ft_empty_rect(t_data *data)
{
	data->line.start = data->rect.x_left;
	data->line.stop = data->rect.x_right;
	data->line.y = data->rect.y_up;
	ft_display_hori_line(data);
	data->line.y = data->rect.y_down;
	ft_display_hori_line(data);
	data->line.start = data->rect.y_up;
	data->line.stop = data->rect.y_down;
	data->line.x = data->rect.x_left;
	ft_display_vert_line(data);
	data->line.x = data->rect.x_right;
	ft_display_vert_line(data);
}

/* static void	ft_draw_circle(t_data *data)
{
	const float	angle = M_PI * 2.f / data->cirlce.steps;

} */

static void	ft_draw_line(t_data *data)
{
	size_t	i;
	size_t	j;

	i = data->line.start;
	j = data->line.y;
	while (i < data->line.stop)
	{
		ft_pixel_put(data, i, j, data->argb.colors);
		if (data->line.x != j)
			j++;
		i++;
	}
}

void	ft_bresenham_line(t_data *data)
{
	int dx =  abs(data->bes.x_1 - data->bes.x_0);
	int dy = -abs(data->bes.y_1 - data->bes.y_0);
	int sx = data->bes.x_0 < data->bes.x_1 ? 1 : -1;
	int sy = data->bes.y_0 < data->bes.y_1  ? 1 : -1; 
	int err = dx + dy;
	int e2 = err;

	while (1)
	{
		ft_pixel_put(data, data->bes.x_0, data->bes.y_0, data->argb.colors);
		if (data->bes.x_0 == data->bes.x_1 && data->bes.y_0 == data->bes.y_1)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			data->bes.x_0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			data->bes.y_0 += sy;
		}
	}
}

int	main(void)
{
	t_data	data;
	t_vars	vars;
	
	//int offset = (y * line_length + x * (bits_per_pixel / 8));

	vars.mlx = mlx_init(); // Lance la lib
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Ceci est un test"); // creation d'une fenetre
	data.img = mlx_new_image(vars.mlx, 1920, 1080); //INIT D'UNE IMAGE
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	// ft_pixel_put(&data, 210, 200, argb.colors);
	/* CARRE */
	data.argb = ft_argb(255, 0, 0, 0);
	data.square.up_r = 400; data.square.up_l = 200; data.square.down_l = 200; data.square.down_r = 400;
	ft_display_square(&data);

	/* LIGNE  */
	data.argb = ft_argb(0, 255, 0, 0);
	data.line.start = 500; data.line.stop = 600; data.line.y = 200;
	ft_display_hori_line(&data);

	/* TRIANGLE RECTANGLE */
	data.argb = ft_argb(0, 0, 255, 0);
	data.square.up_l = 410; data.square.down_r = 500;
	ft_display_triangle_rect(&data);
	
	/* CARRE VIDE */
	data.rect.x_left = 600; data.rect.y_up = 400;
	data.rect.x_right = 800; data.rect.y_down = 600;
	data.argb = ft_argb(255, 255, 255, 0);
	ft_empty_rect(&data);

	/* OTHER LINE */
	data.line.start = 100; data.line.stop = 800;
	data.line.x = 12; data.line.y = 80;
	data.argb = ft_argb(200, 200, 20, 0);
	ft_draw_line(&data);

	/* TRIANGLE */

	/* BES LINE */
	data.argb = ft_argb(8, 255, 0, 0);
	data.bes.x_0 = 600; data.bes.x_1 = 800;
	data.bes.y_0 = 500; data.bes.y_1 = 600;
	ft_bresenham_line(&data);

	/* Phrase */
	data.argb = ft_argb(255, 255, 255, 0);
	mlx_string_put(vars.mlx, vars.win, 800, 800, data.argb.colors, "Ceci est un test");

	/* Display function */
	mlx_put_image_to_window(vars.mlx, vars.win, data.img, 0, 0);


	/* KILL PROCESS */
	mlx_hook(vars.win, 2, KeyPressMask, ft_close, &vars);
	//mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx); //Boucle qui permet la vie du programme
	return (0);
}
