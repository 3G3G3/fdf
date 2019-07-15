/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:41:58 by grgauthi          #+#    #+#             */
/*   Updated: 2019/05/11 17:30:47 by grgauthi         ###   ########.fr       */
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
// structure du paramétrage global du tracé :
// centre du dessin

typedef	struct		s_move
{
	char			proj;
	int				t_x;
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

t_list				*ft_readfile(char *filemname);

t_list				*ft_init_lst(char *name);

void				ft_center(t_list *points);

void				ft_get_extent(t_list *param);

void				ft_move(t_list *param);

void				ft_get_win_position(t_list *param);

void				ft_projection(t_list *param);

void				ft_draw_point(int x, int y, t_list *param);

void				ft_draw(t_list *param);

void				ft_draw_line(t_point *point1, t_point *point2, t_list *param);

void				ft_free_param(t_list *param);

int					ft_keys(int keycode, void *param);

void				ft_exit(void *param);
#endif
