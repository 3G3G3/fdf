/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:41:58 by grgauthi          #+#    #+#             */
/*   Updated: 2019/05/04 15:40:05 by grgauthi         ###   ########.fr       */
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

typedef	struct		s_point
{
	double				x;
	double				y;
	double				z;
	double				X;
	double				Z;
}					t_point;

t_list				*ft_readfile(char *filemname);

void				ft_center(t_list *points);

void				ft_draw(t_list *points, void *mlx_ptr, void *win_ptr);

void				ft_parallele_draw(t_list *points, void *mlx_ptr, void *win_ptr);

void				ft_parallele_rotate(t_list *param, double theta_x, double theta_z);

void				ft_translate(int u, void *param);

int					ft_keys(int keycode, void *param);

void				ft_exit(void *param);
#endif
