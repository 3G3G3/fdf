/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsefile_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 22:40:18 by grgauthi          #+#    #+#             */
/*   Updated: 2019/07/15 22:42:59 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_neighbours(t_list *list, int j, t_list *new)
{
	while (list && ((t_point *)(list->content))->y < j - 1)
		list = list->next;
	while (list && new)
	{
		if (list->next)
		{
			((t_point *)(list->content))->h_n =
				(t_point *)((list->next)->content);
		}
		if (new->next)
		{
			((t_point *)(new->content))->h_n =
				(t_point *)((new->next)->content);
		}
		((t_point *)(list->content))->v_n = (t_point *)(new->content);
		list = list->next;
		new = new->next;
	}
}
