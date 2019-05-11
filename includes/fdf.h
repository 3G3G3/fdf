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
# define H_WIN 500
// structure du paramétrage global du tracé :
// centre du dessin

typedef	struct		s_move
{
	int				t_x;
	int				t_z;
	double			theta_x;
	double			theta_z;
}					t_move;

typedef	struct		s_point
{
	double				x;
	double				y;
	double				z;
	double				x_m;
	double				y_m;
	double				z_m;
	double				x_p;
	double				z_p;
}					t_point;


t_move				*ft_get_move(t_list *param);

t_list				*ft_get_points(t_list *param);

t_list				*ft_readfile(char *filemname);

t_list				*ft_init_lst(char *name);

void				ft_center(t_list *points);

void				ft_move(t_list *param);

double				ft_parallele_proj(t_list *param);

void				ft_draw(t_list *param);

int					ft_keys(int keycode, void *param);

void				ft_exit(void *param);
#endif
