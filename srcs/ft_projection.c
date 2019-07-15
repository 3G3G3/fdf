/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 16:55:15 by grgauthi          #+#    #+#             */
/*   Updated: 2019/05/11 18:48:17 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		point->x_w = round(W_WIN / 2
			+ fmax(0, 0.7 + 0.1 * move->m_zoom) * point->x_p * W_WIN / move->zoom);
		point->z_w = round(H_WIN / 2
			+ fmax(0, 0.7 + 0.1 * move->m_zoom) * point->z_p * H_WIN / move->zoom);
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
	point->x_p = - y_c * (x_c - point->x_m) / (y_c - point->y_m);
	point->z_p = -1 * (- y_c) * (z_c - point->z_m) / (y_c - point->y_m);
}

void			ft_projection(t_list *param)
{
	t_point		*point;
	t_list		*points;
	void		(*proj)(t_point *);

	points = ft_get_points(param);
	point = (t_point *)(points->content);
	if (ft_get_move(param)->proj != 'q')
		proj = &ft_projection_parallele_point;
//		ft_projection_parallele_point(point, ft_get_move(param));
	else
		proj = &ft_perspective_projection_point;
//		ft_perspective_projection_point(point, ft_get_move(param));
	proj(point);
	points = points->next;
	//	free everything
	while (points != NULL)
	{
		point = (t_point *)(points->content);
		proj(point);
		points = points->next;
	}

	return ;
}
