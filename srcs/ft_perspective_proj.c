/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perspective_proj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 16:55:15 by grgauthi          #+#    #+#             */
/*   Updated: 2019/05/11 18:48:17 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_perspective_projection_point(t_point *point, t_move *move)
{
	int			x_c;
	int			y_c;
	int			z_c;

	x_c = 0;
	y_c = 100;
	z_c = 20;
	point->x_p = ft_get_win_position(- y_c * (x_c - point->x_m) / (y_c - point->y_m), W_WIN, move);
	point->z_p = ft_get_win_position(-1 * (- y_c) * (z_c - point->z_m) / (y_c - point->y_m), H_WIN, move);
}

void			ft_perspective_proj(t_list *param)
{
	t_point		*point;
	t_list		*points;

	points = ft_get_points(param);
	point = (t_point *)(points->content);
	ft_perspective_projection_point(point, ft_get_move(param));
	points = points->next;
//	free everything
	while (points != NULL)
	{
		point = (t_point *)(points->content);
		ft_perspective_projection_point(point, ft_get_move(param));
		points = points->next;
	}

	return ;
}

// only one projection function, with projection type fonction as a paramater
