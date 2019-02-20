/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_and_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:19:52 by kvilna            #+#    #+#             */
/*   Updated: 2018/02/19 14:19:54 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		validate_fractal(char *s)
{
	if (ft_strcmp(s, "julia") != 0 &&
		ft_strcmp(s, "mandelbrot") != 0 &&
		ft_strcmp(s, "star") != 0 &&
		ft_strcmp(s, "multibrot") != 0 &&
		ft_strcmp(s, "ship") != 0 &&
		ft_strcmp(s, "brain") != 0 &&
		ft_strcmp(s, "snowflake") != 0 &&
		ft_strcmp(s, "spider") != 0)
		usage_message("wrong set", 2, 42);
}

double		find_change(int x, int y)
{
	double	change;

	if (x >= WIDTH / 2 || y >= HEIGHT / 2)
		change = 0.3;
	if (x >= WIDTH / 3 || y >= HEIGHT / 3)
		change = 0.2;
	if (x >= WIDTH / 4 || y >= HEIGHT / 4)
		change = 0.1;
	return (change);
}

void		find_position(t_win *st, int x, int y)
{
	double	change;

	change = find_change(x, y);
	if (y <= HEIGHT / 2 && x <= WIDTH / 2)
	{
		st->movex -= (change / st->zoom);
		st->movey -= (change / st->zoom);
	}
	if (y <= HEIGHT / 2 && x > WIDTH / 2)
	{
		st->movex += (change / st->zoom);
		st->movey -= (change / st->zoom);
	}
	if (y > HEIGHT / 2 && x <= WIDTH / 2)
	{
		st->movex -= (change / st->zoom);
		st->movey += (change / st->zoom);
	}
	if (y > HEIGHT / 2 && x > WIDTH / 2)
	{
		st->movex += (change / st->zoom);
		st->movey += (change / st->zoom);
	}
}

void		new_image(t_win *win)
{
	if (!(win->img = mlx_new_image(win->mlx, WIDTH, HEIGHT)))
	{
		if (win->img)
			mlx_destroy_image(win->mlx, win->img);
		ft_memdel((void **)&win->img);
	}
	win->addr = mlx_get_data_addr(win->img, &win->bits_per_pixel,
	&win->size_line, &win->endian);
	win->bits_per_pixel /= 8;
}

void		image_set_pixel(t_win *win, int x, int y, int color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	*(int *)(win->addr + ((x + y * WIDTH) * win->bits_per_pixel)) = color;
}
