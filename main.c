/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 13:54:08 by kvilna            #+#    #+#             */
/*   Updated: 2018/01/21 13:54:10 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		*define_fractal(char c)
{
	void	*func;

	if (c == 'm')
		func = calculate_m;
	if (c == 'j')
		func = calculate_j;
	if (c == 'M')
		func = calculate_mult;
	if (c == 's')
		func = calculate_star;
	if (c == 'S')
		func = calculate_ship;
	if (c == 'b')
		func = calculate_brain;
	if (c == 'w')
		func = calculate_snowflake;
	if (c == 'd')
		func = calculate_spider;
	return (func);
}

void			threads(t_win *st)
{
	pthread_t		threads[NUM_THREADS];
	int				i;
	void			*func;

	i = 0;
	func = define_fractal(st->fract);
	while (i < NUM_THREADS)
	{
		pthread_create(&(threads[i]), NULL, func, (void*)st);
		i++;
	}
	i = 0;
	while (i < NUM_THREADS)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}

static void		set_everything(t_win *st, char *s)
{
	validate_fractal(s);
	st->win = mlx_new_window(st->mlx, WIDTH, HEIGHT, s);
	new_image(st);
	mlx(st, s);
	threads(st);
	mlx_put_image_to_window(st->mlx, st->win, st->img, 0, 0);
	mlx_hook(st->win, 2, 5, exit_func, st);
	if (st->fract == 'j')
		mlx_hook(st->win, 6, 1 << 6, changing_julia, st);
	mlx_mouse_hook(st->win, mouse_hook, st);
}

int				main(int argc, char **argv)
{
	t_mlx			st;

	if (argc != 3 && argc != 2)
		usage_message("wrong set", 2, 42);
	if (ft_strcmp(argv[1], "-help") == 0)
		help_message();
	st.mlx = mlx_init();
	st.win1.mlx = st.mlx;
	set_everything(&st.win1, argv[1]);
	if (argc == 3)
	{
		st.win2.mlx = st.mlx;
		set_everything(&st.win2, argv[2]);
	}
	mlx_loop(st.mlx);
	return (0);
}
