/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parallele_proj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 16:55:15 by grgauthi          #+#    #+#             */
/*   Updated: 2019/05/11 18:48:17 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point			*ft_get_extent_init(t_point *point)
{
	t_point		*extent;

	extent = (t_point *)ft_memalloc(sizeof(t_point));
	if (extent == NULL)
		return (NULL);
	extent->x_m = point->x_p;
	extent->x_p = point->x_p;
	extent->z_m = point->z_p;
	extent->z_p = point->z_p;
	return (extent);
}

void			ft_get_extent(t_point *extent, t_point *point)
{
	extent->x_m = fmin(extent->x_m, point->x_p);
	extent->x_p = fmax(extent->x_p, point->x_p);
	extent->z_m = fmin(extent->z_m, point->z_p);
	extent->z_p = fmax(extent->z_p, point->z_p);
}

double			ft_parallele_proj(t_list *param)
{
	t_point		*point;
	t_list		*points;
	t_point		*extent;

	points = ft_get_points(param);
	point = (t_point *)(points->content);
	point->x_p = point->x_m - 0.5 * point->y_m;
//	point->z_p = - point->z_m;
	point->z_p = -1 * (point->z_m - point->y_m);
	extent = ft_get_extent_init(point);
	points = points->next;
	if (extent == NULL)
		return (0);
//	free everything
	while (points != NULL)
	{
		point = (t_point *)(points->content);
		point->x_p = point->x_m - 0.5 * point->y_m;
		point->z_p = -1 * (point->z_m - point->y_m);
//		point->z_p = - point->z_m;
		ft_get_extent(extent, point);
		points = points->next;
	}
	return (fmax(fabs(extent->x_p - extent->x_m),
			fabs(extent->z_p - extent->z_m)));
}
