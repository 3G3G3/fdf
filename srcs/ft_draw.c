/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 20:32:22 by grgauthi          #+#    #+#             */
/*   Updated: 2019/07/16 13:27:49 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_draw_point(int x, int y, t_list *param)
{
	mlx_pixel_put(param->content, (param->next)->content, x, y, 0xFFFFFF);
}

void			ft_draw(t_list *param)
{
	t_point		*point;
	t_list		*points;

	points = ft_get_points(param);
	while (points)
	{
		point = (t_point *)(points->content);
		ft_draw_point(point->x_w, point->z_w, param);
		if (point->h_n != NULL)
			ft_draw_line(point, point->h_n, param);
		if (point->v_n != NULL)
			ft_draw_line(point, point->v_n, param);
		points = points->next;
	}
}

void			ft_print(t_list *param)
{
	t_list		*points;

	mlx_clear_window(param->content, (param->next)->content);
	points = ft_get_points(param);
	if (ft_center(points) == -1)
	{
		ft_free_param(param);
		ft_putendl("error malloc: ft_center");
		exit (-1);
	}
	ft_move(param);
	ft_projection(param);
	ft_get_win_position(param);
	ft_draw(param);
}
