/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 20:39:48 by grgauthi          #+#    #+#             */
/*   Updated: 2019/07/16 13:57:59 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		*ft_free_lst(t_list *param)
{
	t_list	*next;

	while (param)
	{
		next = param->next;
		free(param->content);
		free(param);
		param = next;
	}
	return (NULL);
}

void		ft_destroy_win(t_list *param)
{
	mlx_destroy_window(param->content, (param->next)->content);
}

t_list		*ft_free_head_param(t_list *param)
{
	t_list	*next;

	ft_destroy_win(param);
	next = param->next;
	free(param);
	param = next;
	next = param->next;
	free(param);
	return (next);
}

void		ft_free_param(t_list *param)
{
	param = ft_free_head_param(param);
	ft_free_lst(param);
}
