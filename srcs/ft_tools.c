/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 14:52:26 by grgauthi          #+#    #+#             */
/*   Updated: 2019/07/17 19:26:18 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_move		*ft_get_move(t_list *param)
{
	t_move	*move;

	move = (t_move *)(((param->next)->next)->content);
	return (move);
}

t_list		*ft_get_points(t_list *param)
{
	return (((param->next)->next)->next);
}
