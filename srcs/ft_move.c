/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 15:34:13 by grgauthi          #+#    #+#             */
/*   Updated: 2019/07/16 16:28:36 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_rotate_x(t_point *point, t_move *move)
{
	int			y;
	int			z;

	y = point->y_m;
	z = point->z_m;
	point->y_m = cos(move->theta_x) * y - sin(move->theta_x) * z;
	point->z_m = sin(move->theta_x) * y + cos(move->theta_x) * z;
}

void			ft_rotate_z(t_point *point, t_move *move)
{
	int			x;
	int			y;

	x = point->x_m;
	y = point->y_m;
	point->x_m = cos(move->theta_z) * x - sin(move->theta_z) * y;
	point->y_m = sin(move->theta_z) * x + cos(move->theta_z) * y;
}

void			ft_rotate(t_list *points, t_move *move)
{
	t_point		*point;

	while (points)
	{
		point = (t_point *)(points->content);
		if (point->z != 0)
			point->z_m = point->z_m + move->t_height;
		else
			point->z_m = point->z_m;
		ft_rotate_z(point, move);
		ft_rotate_x(point, move);
		points = points->next;
	}
}

/*
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
		points = points->next;
	}
}
*/

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
