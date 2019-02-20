/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:31:48 by kvilna            #+#    #+#             */
/*   Updated: 2018/02/07 13:31:50 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		help_message(void)
{
	ft_putendl("<-------------------------------->");
	ft_putendl("| Iteration plus:       [A]      |");
	ft_putendl("| Iteration minus:      [D]      |");
	ft_putendl("| Move the image:       [arrows] |");
	ft_putendl("| Different Julia sets: [J]      |");
	ft_putendl("| Different colors:     [space]  |");
	ft_putendl("| Crazy colors:         [Z]      |");
	ft_putendl("| Zoom in/zoom out:     [mouse]  |");
	ft_putendl("<-------------------------------->");
	ft_putendl("Have fun!");
	exit(0);
}

int			usage_message(char *line, int fd, int bye)
{
	if (ft_strcmp(line, "wrong set") == 0)
	{
		ft_putendl("usage: fractol fractal_name1 fractal_name2 [-help]");
		ft_putendl("<------------------->");
		ft_putendl("| Please try:");
		ft_putendl("| - julia           |\n| - mandelbrot      |");
		ft_putendl("| - star            |\n| - multibrot       |");
		ft_putendl("| - ship            |\n| - brain           |");
		ft_putendl("| - snowflake       |\n| - spider          |");
		ft_putendl("<------------------->");
	}
	else
		ft_putendl_fd(line, fd);
	exit(bye);
}

static char	define_fract(char *s)
{
	char	c;

	if (ft_strcmp(s, "mandelbrot") == 0)
		c = 'm';
	if (ft_strcmp(s, "julia") == 0)
		c = 'j';
	if (ft_strcmp(s, "star") == 0)
		c = 's';
	if (ft_strcmp(s, "multibrot") == 0)
		c = 'M';
	if (ft_strcmp(s, "ship") == 0)
		c = 'S';
	if (ft_strcmp(s, "brain") == 0)
		c = 'b';
	if (ft_strcmp(s, "snowflake") == 0)
		c = 'w';
	if (ft_strcmp(s, "spider") == 0)
		c = 'd';
	return (c);
}

void		mlx(t_win *st, char *argv)
{
	st->zoom = 0.5;
	st->movex = 0.1;
	st->movey = 0.1;
	st->color = 0xffffff;
	st->flag = 0;
	st->max_iter = 10;
	st->color = 0;
	st->crazy = 0;
	st->complex.re = -0.2856075296639;
	st->complex.im = -0.6605950131257;
	st->complex.angle = 10 * (M_PI / 180);
	st->fract = define_fract(argv);
}
