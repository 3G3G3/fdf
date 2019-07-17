/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 21:59:07 by grgauthi          #+#    #+#             */
/*   Updated: 2019/07/16 14:44:16 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point				*ft_get_extent_init(t_point *point)
{
	t_point			*extent;

	extent = (t_point *)ft_memalloc(sizeof(t_point));
	if (extent == NULL)
		return (NULL);
	extent->x_m = point->x_p;
	extent->x_p = point->x_p;
	extent->z_m = point->z_p;
	extent->z_p = point->z_p;
	return (extent);
}

void				ft_get_extent_point(t_point *extent, t_point *point)
{
	extent->x_m = fmin(extent->x_m, point->x_p);
	extent->x_p = fmax(extent->x_p, point->x_p);
	extent->z_m = fmin(extent->z_m, point->z_p);
	extent->z_p = fmax(extent->z_p, point->z_p);
}

int					ft_get_extent(t_list *param)
{
	t_point		*extent;
	t_list		*points;

	points = ft_get_points(param);
	extent = ft_get_extent_init((t_point *)(points->content));
	if (extent == NULL)
		return (-1);
	points = points->next;
	while (points != NULL)
	{
		ft_get_extent_point(extent, (t_point *)(points->content));
		points = points->next;
	}
//	ft_get_move(param)->zoom = fmax(fabs(extent->x_p - extent->x_m),
//		fabs(extent->z_p - extent->z_m));
	ft_get_move(param)->zoom = fmax(fmax(fabs(extent->x_p), fabs(extent->x_m)),
		fmax(fabs(extent->z_p), fabs(extent->z_m)));
	free(extent);
	return (0);
}
