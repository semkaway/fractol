/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_and_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:23:32 by kvilna            #+#    #+#             */
/*   Updated: 2018/02/19 14:23:34 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				changing_julia(int x, int y, t_win *st)
{
	static	int		sx;
	static	int		sy;

	mlx_clear_window(st->mlx, st->win);
	ft_bzero(st->addr, ft_strlen(st->addr));
	if ((x > sx && y < HEIGHT / 2) || (x < sx && y > HEIGHT / 2))
	{
		st->complex.re = sin(st->complex.angle);
		st->complex.im = cos(st->complex.angle);
		st->complex.angle -= 0.1;
	}
	else if ((x < sx && y < HEIGHT / 2) || (x > sx && y > HEIGHT / 2))
	{
		st->complex.re = sin(st->complex.angle);
		st->complex.im = cos(st->complex.angle);
		st->complex.angle += 0.1;
	}
	threads(st);
	mlx_put_image_to_window(st->mlx, st->win, st->img, 0, 0);
	sx = x;
	sy = y;
	return (0);
}

int				mouse_hook(int button, int x, int y, t_win *st)
{
	mlx_clear_window(st->mlx, st->win);
	ft_bzero(st->addr, ft_strlen(st->addr));
	if (button == 4)
		st->zoom *= 0.8;
	if (button == 5)
		st->zoom /= 0.8;
	find_position(st, x, y);
	threads(st);
	mlx_put_image_to_window(st->mlx, st->win, st->img, 0, 0);
	return (0);
}

static void		diff_julia(t_com_num *complex)
{
	static int		i;
	double			julia_re[7];
	double			julia_im[7];

	if (i > 6)
		i = 0;
	julia_re[0] = -0.4;
	julia_im[0] = 0.6;
	julia_re[1] = 0.285;
	julia_im[1] = 0.01;
	julia_re[2] = -0.8;
	julia_im[2] = 0.156;
	julia_re[3] = -0.7269;
	julia_im[3] = 0.1889;
	julia_re[4] = -0.74543;
	julia_im[4] = 0.11301;
	julia_re[5] = -0.75;
	julia_im[5] = 0.11;
	julia_re[6] = -0.1;
	julia_im[6] = 0.651;
	complex->re = julia_re[i];
	complex->im = julia_im[i];
	i++;
}

static void		keyhooks(int keyhook, t_win *st)
{
	if (keyhook == RIGHT)
		st->movex += 0.03 / st->zoom;
	if (keyhook == LEFT)
		st->movex -= (0.03 / st->zoom);
	if (keyhook == UP)
		st->movey -= (0.03) / st->zoom;
	if (keyhook == DOWN)
		st->movey += (0.03 / st->zoom);
	if (keyhook == ITER_MINUS)
		st->max_iter -= 10;
	if (keyhook == ITER_PLUS)
		st->max_iter += 10;
	if (keyhook == JULIA_IM_PLUS && st->fract == 'j')
		diff_julia(&st->complex);
}

int				exit_func(int keyhook, t_win *st)
{
	if (keyhook == ESC)
		exit(0);
	mlx_clear_window(st->mlx, st->win);
	ft_bzero(st->addr, ft_strlen(st->addr));
	keyhooks(keyhook, st);
	if (keyhook == SPACE)
	{
		st->color++;
		if (st->color > 3)
			st->color = 0;
	}
	if (keyhook == CRAZY)
	{
		if (st->crazy == 0)
			st->crazy = 1;
		else
			st->crazy = 0;
	}
	threads(st);
	mlx_put_image_to_window(st->mlx, st->win, st->img, 0, 0);
	return (0);
}
