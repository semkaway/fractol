/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:09:57 by kvilna            #+#    #+#             */
/*   Updated: 2018/02/13 17:09:59 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		*calculate_brain(void *pt)
{
	t_win		st;
	static int	test;

	st = *(t_win*)pt;
	++test;
	if (test == 4)
		test = 0;
	st.fractal.i = 0;
	st.fractal.rem2 = test * HEIGHT / NUM_THREADS;
	while (st.fractal.i < HEIGHT / NUM_THREADS)
	{
		iterations_for_brain(&st);
		st.fractal.rem2++;
		st.fractal.i++;
	}
	return (0);
}

void		*calculate_j(void *pt)
{
	t_win		st;
	static int	test;

	st = *(t_win*)pt;
	++test;
	if (test == 4)
		test = 0;
	st.fractal.i = 0;
	st.fractal.rem2 = test * HEIGHT / NUM_THREADS;
	while (st.fractal.i < HEIGHT / NUM_THREADS)
	{
		iterations_for_julia(&st);
		st.fractal.rem2++;
		st.fractal.i++;
	}
	return (0);
}

void		*calculate_m(void *pt)
{
	t_win		st;
	static int	test;

	st = *(t_win*)pt;
	++test;
	if (test == 4)
		test = 0;
	st.fractal.i = 0;
	st.fractal.rem2 = test * HEIGHT / NUM_THREADS;
	while (st.fractal.i < HEIGHT / NUM_THREADS)
	{
		iterations_for_mandelbrot(&st);
		st.fractal.rem2++;
		st.fractal.i++;
	}
	return (0);
}

void		*calculate_ship(void *pt)
{
	t_win		st;
	static int	test;

	st.fractal.i = 0;
	st = *(t_win*)pt;
	++test;
	if (test == 4)
		test = 0;
	st.fractal.rem2 = test * HEIGHT / NUM_THREADS;
	while (st.fractal.i < HEIGHT / NUM_THREADS)
	{
		st.fractal.j = 0;
		iterations_for_ship(&st);
		st.fractal.rem2++;
		st.fractal.i++;
	}
	return (0);
}

void		*calculate_star(void *pt)
{
	t_win		st;
	t_squares	var;
	static int	test;

	st = *(t_win*)pt;
	++test;
	if (test == 4)
		test = 0;
	st.fractal.i = 0;
	st.fractal.rem2 = test * HEIGHT / NUM_THREADS;
	while (st.fractal.i < HEIGHT / NUM_THREADS)
	{
		st.fractal.j = 0;
		iterations_for_star(&st, &var);
		st.fractal.rem2++;
		st.fractal.i++;
	}
	return (0);
}
