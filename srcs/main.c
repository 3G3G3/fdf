/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 19:25:39 by grgauthi          #+#    #+#             */
/*   Updated: 2019/07/17 19:59:43 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list			*ft_init(char *argv)
{
	t_list		*points;
	t_list		*res;

	points = ft_readfile(argv);
	if (points == NULL)
		return (NULL);
	res = ft_init_lst(argv);
	if (res == NULL)
		return ((t_list *)ft_free_lst(points));
	((res->next)->next)->next = points;
	if (ft_center(res) == -1)
	{
		ft_free_param(res);
		return (NULL);
	}
	ft_move(res);
	ft_projection(res);
	if (ft_get_extent(res) == -1)
	{
		ft_free_param(res);
		return (NULL);
	}
	return (res);
}

void			ft_main(int argc, char **argv)
{
	t_list		*ptrs;

	if (argc != 2)
	{
		ft_putendl("usage: one and only one file allowed");
		return ;
	}
	ptrs = ft_init(argv[1]);
	if (ptrs == NULL)
	{
		ft_putendl("error: ft_init failed");
		return ;
	}
	ft_print(ptrs);
	mlx_key_hook((ptrs->next)->content, &ft_keys, ptrs);
	mlx_loop(ptrs->content);
}

int				main(int argc, char **argv)
{
	ft_main(argc, argv);
	return (0);
}
