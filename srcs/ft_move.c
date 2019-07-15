/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 15:34:13 by grgauthi          #+#    #+#             */
/*   Updated: 2019/05/11 18:21:51 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double			ft_rotate_y(double x, double y, double z, t_move *move)
{
	return (cos(move->theta_x) * sin(move->theta_z) * x
		+ cos(move->theta_x) * cos(move->theta_z) * y
		- sin(move->theta_x) * z);
}

double			ft_rotate_z(double x, double y, double z, t_move *move)
{

	return (sin(move->theta_x) * sin(move->theta_z) * x
		+ sin(move->theta_x) * cos(move->theta_z) * y
		+ cos(move->theta_x) * z);
}

void			ft_rotate(t_list *points, t_move *move)
{
	t_point		*point;
	double		x;
	double		y;
	double		z;

	while (points)
	{
		point = (t_point *)(points->content);
		x = point->x_m;
		y = point->y_m;
		if (point->z != 0)
			z = point->z_m + move->t_height;
		else
			z = point->z_m;
		point->x_m = cos(move->theta_z) * x - sin(move->theta_z) * y;
		point->y_m = ft_rotate_y(x, y, z, move);
		point->z_m = ft_rotate_z(x, y, z, move);
//		point->x_m = cos(move->theta_z) * x - sin(move->theta_z) * y;
//		point->y_m = sin(move->theta_z) * x + cos(move->theta_z) * y;
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
