/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 19:40:16 by grgauthi          #+#    #+#             */
/*   Updated: 2019/07/17 19:43:16 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_normalize_position(double x, int size, t_move *move)
{
	return (round((size
		+ fmax(0, 0.7 + 0.1 * move->m_zoom) * x * size / move->zoom)) / 2);
}

void			ft_get_win_position(t_list *param)
{
	t_point		*point;
	t_move		*move;
	t_list		*points;

	points = ft_get_points(param);
	move = ft_get_move(param);
	while (points != NULL)
	{
		point = (t_point *)(points->content);
		point->x_w = ft_normalize_position(point->x_p, W_WIN, move);
		point->z_w = ft_normalize_position(point->z_p, H_WIN, move);
		points = points->next;
	}
}
