/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 22:05:48 by grgauthi          #+#    #+#             */
/*   Updated: 2019/07/15 22:31:27 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_normalize_position(double x, int size, t_move *move)
{
	return (round((size / 2
		+ fmax(0, 0.5 + 0.1 * move->m_zoom) * x * size / move->zoom)));
}

void			ft_get_win_position(t_list *param)
{
	t_point		*point;
	t_move		*move;
	t_list		*points;

	points = ft_get_points(param);
	move = ft_get_move(param);
	while (points != NULL)
	{
		point = (t_point *)(points->content);
		point->x_w = ft_normalize_position(point->x_p, W_WIN, move);
		point->z_w = ft_normalize_position(point->z_p, H_WIN, move);
		points = points->next;
	}
}

void			ft_projection_parallele_point(t_point *point)
{
	point->x_p = point->x_m;
	point->z_p = -1 * (point->z_m);
}

void			ft_perspective_projection_point(t_point *point)
{
	int			x_c;
	int			y_c;
	int			z_c;

	x_c = 0;
	y_c = 100;
	z_c = 20;
	point->x_p = -y_c * (x_c - point->x_m) / (y_c - point->y_m);
	point->z_p = -1 * (-y_c) * (z_c - point->z_m) / (y_c - point->y_m);
}

void			ft_projection(t_list *param)
{
	t_point		*point;
	t_list		*points;
	void		(*proj)(t_point *);

	points = ft_get_points(param);
	if (ft_get_move(param)->proj != 'q')
		proj = &ft_projection_parallele_point;
	else
		proj = &ft_perspective_projection_point;
	while (points != NULL)
	{
		point = (t_point *)(points->content);
		proj(point);
		points = points->next;
	}
	return ;
}
