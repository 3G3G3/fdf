/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 22:05:48 by grgauthi          #+#    #+#             */
/*   Updated: 2019/07/17 20:08:32 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_parallele_projection_point(t_point *point)
{
	point->x_p = point->x_m;
	point->z_p = -1 * (point->z_m);
}

void			ft_iso_projection_point(t_point *point)
{
	point->x_p = (point->x_m + point->z_m) * cos(0.523599);
	point->z_p = -1 * (-point->y_m + (point->x_m - point->z_m) * sin(0.523599));
}

void			ft_perspective_projection_point(t_point *point)
{
	int			x_c;
	int			y_c;
	int			z_c;

	x_c = 0;
	y_c = 100;
	z_c = 0;
	point->x_p = -y_c * (x_c - point->x_m) / (y_c - point->y_m);
	point->z_p = -1 * (-y_c) * (z_c - point->z_m) / (y_c - point->y_m);
}

void			ft_projection(t_list *param)
{
	t_point		*point;
	t_list		*points;
	void		(*proj)(t_point *);

	points = ft_get_points(param);
	if (ft_get_move(param)->proj == 'p')
		proj = &ft_parallele_projection_point;
	else if (ft_get_move(param)->proj == 'i')
		proj = &ft_iso_projection_point;
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
