/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 21:48:42 by grgauthi          #+#    #+#             */
/*   Updated: 2019/08/05 19:06:44 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_key_exit(int keycode, void *param)
{
	if (keycode == 53)
		ft_exit(param);
	return (0);
}

int			ft_keys2(int keycode, void *param)
{
	t_move	*move;

	move = ft_get_move(param);
	if (keycode == 37)
		move->t_x = move->t_x - 1;
	else if (keycode == 15)
		move->t_x = move->t_x + 1;
	else if (keycode == 11)
		move->t_y = move->t_y - 1;
	else if (keycode == 3)
		move->t_y = move->t_y + 1;
	else if (keycode == 2)
		move->t_z = move->t_z - 1;
	else if (keycode == 32)
		move->t_z = move->t_z + 1;
	else if (keycode == 17)
		move->t_height++;
	else if (keycode == 1)
		move->t_height--;
	else if (keycode == 34)
		move->m_zoom++;
	else if (keycode == 31)
		move->m_zoom--;
	return (ft_key_exit(keycode, param));
}
