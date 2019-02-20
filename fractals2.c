/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:08:40 by kvilna            #+#    #+#             */
/*   Updated: 2018/02/16 11:08:41 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		*calculate_snowflake(void *pt)
{
	t_win		st;
	static int	test;
	t_squares	var;

	st = *(t_win*)pt;
	++test;
	if (test == 4)
		test = 0;
	st.fractal.i = 0;
	st.fractal.rem2 = test * HEIGHT / NUM_THREADS;
	while (st.fractal.i < HEIGHT / NUM_THREADS)
	{
		st.fractal.j = 0;
		iterations_for_snowflake(&st, &var);
		st.fractal.rem2++;
		st.fractal.i++;
	}
	return (0);
}

void		*calculate_mult(void *pt)
{
	t_win		st;
	static int	test;
	t_squares	var;

	st = *(t_win*)pt;
	++test;
	if (test == 4)
		test = 0;
	st.fractal.i = 0;
	st.fractal.rem2 = test * HEIGHT / NUM_THREADS;
	while (st.fractal.i < HEIGHT / NUM_THREADS)
	{
		st.fractal.j = 0;
		iterations_for_multibrot(&st, &var);
		st.fractal.rem2++;
		st.fractal.i++;
	}
	return (0);
}

void		*calculate_spider(void *pt)
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
		st.fractal.j = 0;
		iterations_for_spider(&st);
		st.fractal.rem2++;
		st.fractal.i++;
	}
	return (0);
}
