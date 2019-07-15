/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line_octantl.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 20:50:15 by grgauthi          #+#    #+#             */
/*   Updated: 2019/07/15 21:38:35 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_put_octant5(t_line *line, t_list *param)
{
	int		x;
	int		y;

	x = line->x1;
	y = line->y1;
	while (x > line->x2)
	{
		ft_draw_point(x, y, param);
		x = x - 1;
		line->e = line->e - line->dy;
		if (line->e >= 0)
		{
			y = y - 1;
			line->e = line->e + line->dx;
		}
	}
}

void		ft_put_octant4(t_line *line, t_list *param)
{
	int		x;
	int		y;

	x = line->x1;
	y = line->y1;
	while (x > line->x2)
	{
		ft_draw_point(x, y, param);
		x = x - 1;
		line->e = line->e + line->dy;
		if (line->e >= 0)
		{
			y = y + 1;
			line->e = line->e + line->dx;
		}
	}
}

void		ft_put_octant6(t_line *line, t_list *param)
{
	int		x;
	int		y;

	x = line->x1;
	y = line->y1;
	while (y > line->y2)
	{
		ft_draw_point(x, y, param);
		y = y - 1;
		line->e = line->e - line->dx;
		if (line->e >= 0)
		{
			x = x - 1;
			line->e = line->e + line->dy;
		}
	}
}

void		ft_put_octant3(t_line *line, t_list *param)
{
	int		x;
	int		y;

	x = line->x1;
	y = line->y1;
	while (y < line->y2)
	{
		ft_draw_point(x, y, param);
		y = y + 1;
		line->e = line->e + line->dx;
		if (line->e <= 0)
		{
			x = x - 1;
			line->e = line->e + line->dy;
		}
	}
}

int			ft_draw_octantl(t_point *point1, t_point *point2, t_list *param,
		t_line *line)
{
	if (ft_test_quadran(point1->z_w, point2->z_w, point2->x_w, point1->x_w)
		&& ft_test_growth(point1->x_w - point2->x_w, point2->z_w - point1->z_w))
	{
		ft_put_octant3(line, param);
		return (1);
	}
	else if (ft_test_quadran(point1->z_w, point2->z_w, point2->x_w, point1->x_w)
		&& ft_test_growth(point2->z_w - point1->z_w, point1->x_w - point2->x_w))
	{
		ft_put_octant4(line, param);
		return (1);
	}
	else if (ft_test_quadran(point2->z_w, point1->z_w, point2->x_w, point1->x_w)
		&& ft_test_growth(point1->z_w - point2->z_w, point1->x_w - point2->x_w))
	{
		ft_put_octant5(line, param);
		return (1);
	}
	else if (ft_test_quadran(point2->z_w, point1->z_w, point2->x_w, point1->x_w)
		&& ft_test_growth(point1->x_w - point2->x_w, point1->z_w - point2->z_w))
	{
		ft_put_octant6(line, param);
		return (1);
	}
	return (0);
}
