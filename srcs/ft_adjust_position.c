/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adjust_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 17:28:16 by grgauthi          #+#    #+#             */
/*   Updated: 2019/07/16 16:26:56 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point				*ft_get_center(t_list *points)
{
	t_point			*center;
	t_move			*move;

	move = ft_get_move(points);
	points = ft_get_points(points);
	center = ft_memalloc(sizeof(t_point));
	if (center == NULL)
		return (NULL);
	center->x = 0;
	center->y = 0;
	center->z = 0;
	while (points)
	{
		center->x = fmax(center->x, ((t_point *)(points->content))->x);
		center->y = fmax(center->y, ((t_point *)(points->content))->y);
		if (((t_point *)(points->content))->z != 0)
		{
			center->z = fmax(center->z, ((t_point *)(points->content))->z
				+ move->t_height);
		}
		else
			center->z = fmax(center->z, ((t_point *)(points->content))->z);
		points = points->next;
	}
	return (center);
}

int					ft_center(t_list *points)
{
	t_point			*point;
	t_move			*move;
	t_point			*center;

	move = ft_get_move(points);
	points = ft_get_points(points);
	center = ft_get_center(points);
	if (center == NULL)
		return (-1);
	while (points != NULL)
	{
		point = (t_point *)(points->content);
		point->x_m = point->x - (center->x / 2);
		point->y_m = point->y - (center->y / 2);
		if (point->z != 0)
			point->z_m = point->z + move->t_height - (center->z / 2);
		else
			point->z_m = point->z - (center->z / 2);
		points = points->next;
	}
	free(center);
	return (0);
}
