/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:58:15 by kvilna            #+#    #+#             */
/*   Updated: 2018/02/19 16:58:16 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		squares(t_squares *var, t_win *st)
{
	var->ysq = st->complex.y * st->complex.y;
	var->xsq = st->complex.x * st->complex.x;
	var->y2sq = var->ysq * var->ysq;
	var->x2sq = var->xsq * var->xsq;
	var->xysq = var->xsq * var->ysq;
}

void		iterations_for_snowflake(t_win *st, t_squares *var)
{
	while (st->fractal.j < WIDTH)
	{
		st->complex.x = (st->fractal.j - WIDTH / 2)
		/ (0.5 * st->zoom * WIDTH) + st->movex;
		st->complex.y = (st->fractal.rem2 - HEIGHT
			/ 2) / (0.5 * st->zoom * HEIGHT) + st->movey;
		st->fractal.iter = 0;
		squares(var, st);
		while (st->fractal.iter < st->max_iter &&
			(st->complex.x * st->complex.x + st->complex.y * st->complex.y < 4))
		{
			st->complex.y = st->complex.y
			* (5 * var->x2sq - 10 * var->xysq + var->y2sq) + 0.1889;
			st->complex.x = st->complex.x
			* (var->x2sq - 10 * var->xysq + 5 * var->y2sq) - 0.7269;
			squares(var, st);
			st->fractal.iter++;
		}
		st->fractal.color = set_color(st->fractal.iter,
							st->max_iter, st->color, st->crazy);
		image_set_pixel(st, st->fractal.j, st->fractal.rem2, st->fractal.color);
		st->fractal.j++;
	}
}

void		iterations_for_multibrot(t_win *st, t_squares *var)
{
	while (st->fractal.j < WIDTH)
	{
		st->complex.x = 0.0;
		st->complex.y = 0.0;
		st->complex.re = (st->fractal.j - WIDTH / 2)
		/ (0.5 * st->zoom * WIDTH) + st->movex;
		st->complex.im = (st->fractal.rem2 - HEIGHT
			/ 2) / (0.5 * st->zoom * HEIGHT) + st->movey;
		st->fractal.iter = 0;
		squares(var, st);
		while (st->fractal.iter < st->max_iter &&
			(st->complex.x * st->complex.x + st->complex.y * st->complex.y < 4))
		{
			st->complex.y = st->complex.y
			* (5 * var->x2sq - 10 * var->xysq + var->y2sq) + st->complex.im;
			st->complex.x = st->complex.x
			* (var->x2sq - 10 * var->xysq + 5 * var->y2sq) + st->complex.re;
			squares(var, st);
			st->fractal.iter++;
		}
		st->fractal.color = set_color(st->fractal.iter,
							st->max_iter, st->color, st->crazy);
		image_set_pixel(st, st->fractal.j, st->fractal.rem2, st->fractal.color);
		st->fractal.j++;
	}
}

void		iterations_for_spider(t_win *st)
{
	while (st->fractal.j < WIDTH)
	{
		st->complex.x = 0.0;
		st->complex.y = 0.0;
		st->complex.re = (st->fractal.j - WIDTH / 2)
		/ (0.5 * st->zoom * WIDTH) + st->movex;
		st->complex.im = (st->fractal.rem2 - HEIGHT
			/ 2) / (0.5 * st->zoom * HEIGHT) + st->movey;
		st->fractal.iter = 0;
		while (st->fractal.iter < st->max_iter &&
			(st->complex.x * st->complex.x + st->complex.y * st->complex.y < 4))
		{
			st->fractal.tmp = st->complex.x * st->complex.x
			- st->complex.y * st->complex.y + st->complex.re;
			st->complex.y = 2 * st->complex.x * st->complex.y + st->complex.im;
			st->complex.x = st->fractal.tmp;
			st->complex.re = st->complex.re / 2 + st->complex.x;
			st->complex.im = st->complex.im / 2 + st->complex.y;
			st->fractal.iter++;
		}
		st->fractal.color = set_color(st->fractal.iter,
							st->max_iter, st->color, st->crazy);
		image_set_pixel(st, st->fractal.j, st->fractal.rem2, st->fractal.color);
		st->fractal.j++;
	}
}
