/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 20:41:50 by grgauthi          #+#    #+#             */
/*   Updated: 2019/07/15 21:36:52 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_test_quadran(int i, int j, int m, int n)
{
	if (j >= i && n >= m)
		return (1);
	return (0);
}

int			ft_test_growth(int i, int j)
{
	if (j >= i)
		return (1);
	return (0);
}

t_line		*ft_define_line(t_point *point1, t_point *point2)
{
	t_line	*line;

	line = (t_line *)ft_memalloc(sizeof(t_line));
	if (line == NULL)
		return (NULL);
	line->x1 = point1->x_w;
	line->y1 = point1->z_w;
	line->x2 = point2->x_w;
	line->y2 = point2->z_w;
	line->dy = 2 * (line->y2 - line->y1);
	line->dx = 2 * (line->x2 - line->x1);
	line->e = line->x2 - line->x1;
	return (line);
}

void		ft_draw_line(t_point *point1, t_point *point2, t_list *param)
{
	t_line	*line;

	line = ft_define_line(point1, point2);
	if (line == NULL)
		return ;
	if (ft_draw_octantr(point1, point2, param, line) == 0)
		ft_draw_octantl(point1, point2, param, line);
}
