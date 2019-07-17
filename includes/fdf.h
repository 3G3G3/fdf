/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:41:58 by grgauthi          #+#    #+#             */
/*   Updated: 2019/07/16 14:00:27 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define W_WIN 1000
# define H_WIN 700

typedef	struct		s_move
{
	char			proj;
	int				t_x;
	int				t_y;
	int				t_z;
	int				t_height;
	double			theta_x;
	double			theta_z;
	int				zoom;
	int				m_zoom;
}					t_move;

typedef	struct		s_point
{
	double			x;
	double			y;
	double			z;
	double			x_m;
	double			y_m;
	double			z_m;
	double			x_p;
	double			z_p;
	int				x_w;
	int				z_w;
	struct s_point	*h_n;
	struct s_point	*v_n;
}					t_point;

typedef	struct		s_line
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				dx;
	int				dy;
	int				e;
}					t_line;


t_move				*ft_get_move(t_list *param);

t_list				*ft_get_points(t_list *param);

void				ft_set_neighbours(t_list *list, int j, t_list *new);

t_list				*ft_readfile(char *filemname);

t_list				*ft_init_lst(char *name);

int					ft_center(t_list *points);

int					ft_get_extent(t_list *param);

void				ft_move(t_list *param);

void				ft_get_win_position(t_list *param);

void				ft_projection(t_list *param);

void				ft_draw_point(int x, int y, t_list *param);

void				ft_print(t_list *param);

int					ft_test_quadran(int i, int j, int m, int n);

int					ft_test_growth(int i, int j);

int					ft_draw_octantr(t_point *point1, t_point *point2,
						t_list *param, t_line *line);

int					ft_draw_octantl(t_point *point1, t_point *point2,
						t_list *param, t_line *line);

void				ft_draw_line(t_point *point1, t_point *point2,
						t_list *param);

void				*ft_free_lst(t_list *param);

void				ft_free_param(t_list *param);

double				ft_rotate_angle(t_move *move);

int					ft_keys2(int keycode, void *param);

int					ft_keys(int keycode, void *param);

void				ft_exit(void *param);
#endif
