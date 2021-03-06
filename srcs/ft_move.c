/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 15:34:13 by grgauthi          #+#    #+#             */
/*   Updated: 2019/07/17 19:28:04 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_rotate_t(t_point *point, t_move *move)
{
	int			x;
	int			y;
	int			z;

	x = point->x_m;
	y = point->y_m;
	z = point->z_m;
	point->x_m = cos(move->theta_z) * x
		- sin(move->theta_z) * cos(move->theta_x) * y
		+ sin(move->theta_z) * sin(move->theta_x) * z;
	point->y_m = sin(move->theta_z) * x
		+ cos(move->theta_z) * cos(move->theta_x) * y
		- cos(move->theta_z) * sin(move->theta_x) * z;
	point->z_m = sin(move->theta_x) * y + cos(move->theta_x) * z;
}

void			ft_rotate(t_list *points, t_move *move)
{
	t_point		*point;

	while (points)
	{
		point = (t_point *)(points->content);
		ft_rotate_t(point, move);
		points = points->next;
	}
}

void			ft_translate(t_list *points, t_move *move)
{
	t_point		*point;

	while (points)
	{
		point = (t_point *)(points->content);
		point->x_m = point->x_m + move->t_x;
		point->y_m = point->y_m + move->t_y;
		point->z_m = point->z_m + move->t_z;
		points = points->next;
	}
}

void			ft_move(t_list *param)
{
	t_list		*points;
	t_move		*move;

	move = ft_get_move(param);
	points = ft_get_points(param);
	ft_rotate(points, move);
	ft_translate(points, move);
}
