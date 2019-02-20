/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 13:54:39 by kvilna            #+#    #+#             */
/*   Updated: 2018/01/21 13:54:41 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <pthread.h>
# include <mlx.h>
# include <math.h>
# include "libft.h"
# define HEIGHT 1200
# define WIDTH 1200
# define NUM_THREADS 4
# define ZOOM_IN 4
# define ZOOM_OUT 5
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ITER_PLUS 2
# define ITER_MINUS 0
# define JULIA_IM_PLUS 38
# define JULIA_IM_MINUS 40
# define JULIA_RE_PLUS 34
# define JULIA_RE_MINUS 32
# define SPACE 49
# define CRAZY 6

typedef struct	s_complex
{
	long double		re;
	long double		im;
	long double		x;
	long double		y;
	double			angle;
}				t_com_num;

typedef struct	s_var
{
	int		iter;
	int		i;
	int		j;
	double	tmp;
	int		color;
	int		rem2;
	double	square;
	double	square2;
}				t_var;

typedef struct	s_squares
{
	double ysq;
	double xsq;
	double y2sq;
	double x2sq;
	double xysq;
}				t_squares;

typedef struct	s_win
{
	void		*win;
	void		*mlx;
	void		*img;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	char		*addr;
	long double	zoom;
	double		movex;
	double		movey;
	int			color;
	int			flag;
	int			max_iter;
	int			crazy;
	char		fract;
	t_com_num	complex;
	t_var		fractal;
}				t_win;

typedef struct	s_mlx
{
	void	*mlx;
	t_win	win1;
	t_win	win2;
}				t_mlx;

typedef struct	s_px
{
	float		r;
	float		g;
	float		b;
}				t_px;

void			*calculate_m(void *st);
void			*calculate_star(void *pt);
void			*calculate_mult(void *pt);
void			*calculate_j(void *st);
void			*calculate_ship(void *pt);
void			*calculate_brain(void *pt);
void			*calculate_snowflake(void *pt);
void			*calculate_spider(void *pt);
int				set_color(int i, int max_iter, int col, int crazy);
void			image_set_pixel(t_win *win, int x, int y, int color);
int				usage_message(char *line, int fd, int bye);
void			mlx(t_win *st, char *argv);
void			help_message(void);
void			new_image(t_win *win);
void			threads(t_win *st);
int				exit_func(int keyhook, t_win *st);
int				mouse_hook(int button, int x, int y, t_win *st);
int				changing_julia(int x, int y, t_win *st);
void			validate_fractal(char *s);
void			find_position(t_win *st, int x, int y);
void			squares(t_squares *var, t_win *st);
void			iterations_for_brain(t_win *st);
void			iterations_for_julia(t_win *st);
void			iterations_for_mandelbrot(t_win *st);
void			iterations_for_ship(t_win *st);
void			iterations_for_star(t_win *st, t_squares *var);
void			iterations_for_snowflake(t_win *st, t_squares *var);
void			iterations_for_multibrot(t_win *st, t_squares *var);
void			iterations_for_spider(t_win *st);

#endif
