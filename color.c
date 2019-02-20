/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:55:26 by kvilna            #+#    #+#             */
/*   Updated: 2018/01/22 12:55:29 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_px	change_color(int i, int max_iter, int col)
{
	t_px	final_color;
	double	t;

	t = (double)i / (double)max_iter;
	if (col == 1)
	{
		final_color.b = (2 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		final_color.g = (7 * (1 - t) * (1 - t) * t * t * 255);
		final_color.r = (7 * (1 - t) * t * t * t * 255);
	}
	if (col == 2)
	{
		final_color.b = (4 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		final_color.g = (9 * (1 - t) * (1 - t) * t * t * t * 255);
		final_color.r = (13 * (1 - t) * (1 - t) * t * t * t * 255);
	}
	if (col == 3)
	{
		final_color.r = (5 * (1 - t) * t * t * t * 255);
		final_color.g = (5 * (1 - t) * t * t * t * 255);
		final_color.b = (5 * (1 - t) * t * t * t * 255);
	}
	i++;
	return (final_color);
}

int		set_color(int i, int max_iter, int col, int crazy)
{
	int		hex;
	t_px	final_color;
	double	t;

	t = (double)i / (double)max_iter;
	if (col > 0)
		final_color = change_color(i, max_iter, col);
	else
	{
		final_color.r = (5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		final_color.g = (4 * (1 - t) * (1 - t) * t * t * 255);
		final_color.b = (2 * (1 - t) * t * t * t * 255);
	}
	hex = final_color.r;
	hex *= 0x100;
	hex += final_color.g;
	hex *= 0x100;
	hex += final_color.b;
	if (crazy == 1)
		hex *= 5;
	return (hex);
}
