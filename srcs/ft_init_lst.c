/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 13:47:07 by grgauthi          #+#    #+#             */
/*   Updated: 2019/07/17 20:08:51 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_move		*ft_move_init(void)
{
	t_move	*res;

	res = (t_move *)ft_memalloc(sizeof(t_move));
	if (res == NULL)
		return (NULL);
	res->proj = 'p';
	res->t_x = 0;
	res->t_y = 0;
	res->t_z = 0;
	res->t_height = 0;
	res->theta_x = -M_PI / 12;
	res->theta_z = M_PI / 4;
	res->m_zoom = 0;
	return (res);
}

t_list		*ft_mlx_init(void)
{
	void	*mlx_ptr;
	t_list	*ptrs;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (NULL);
	ptrs = ft_lstnew(NULL, 0);
	if (ptrs == NULL)
	{
		free(mlx_ptr);
		return (NULL);
	}
	ptrs->content = mlx_ptr;
	return (ptrs);
}

t_list		*ft_mlx_new_window(void *mlx_ptr, char *name)
{
	void	*win_ptr;
	t_list	*ptrs;

	win_ptr = mlx_new_window(mlx_ptr, W_WIN, H_WIN, name);
	if (win_ptr == NULL)
	{
		free(mlx_ptr);
		return (NULL);
	}
	ptrs = ft_lstnew(NULL, 0);
	if (ptrs == NULL)
	{
		mlx_destroy_window(mlx_ptr, win_ptr);
		return (NULL);
	}
	ptrs->content = win_ptr;
	return (ptrs);
}

t_list		*ft_init_win(char *name)
{
	t_list	*ptrs;

	ptrs = ft_mlx_init();
	if (ptrs == NULL)
		return (NULL);
	ptrs->next = ft_mlx_new_window(ptrs->content, name);
	if (ptrs->next == NULL)
	{
		free(ptrs);
		return (NULL);
	}
	return (ptrs);
}

t_list		*ft_init_lst(char *name)
{
	t_list	*ptrs;

	ptrs = ft_init_win(name);
	if (ptrs == NULL)
		return (NULL);
	ptrs->next->next = ft_lstnew(NULL, 0);
	if ((ptrs->next)->next == NULL)
	{
		ft_free_param(ptrs);
		return (NULL);
	}
	((ptrs->next)->next)->content = ft_move_init();
	if (((ptrs->next)->next)->content == NULL)
	{
		ft_free_param(ptrs);
		return (NULL);
	}
	return (ptrs);
}
