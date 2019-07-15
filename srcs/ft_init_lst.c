/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 13:47:07 by grgauthi          #+#    #+#             */
/*   Updated: 2019/05/11 18:01:55 by grgauthi         ###   ########.fr       */
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
	res->t_z = 0;
	res->t_height = 0;
	res->theta_x = - asin(1 / sqrt(3));
	res->theta_z = M_PI / 4;
	res->m_zoom = 0;
//	res->theta_x = - M_PI / 4;
//	res->theta_z = M_PI / 4;
	return (res);
}

t_list		*ft_init_lst(char *name)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_list	*ptrs;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (NULL);
	win_ptr = mlx_new_window(mlx_ptr, W_WIN, H_WIN, name);
// clear list + perror
	if (win_ptr == NULL)
		return (NULL);
	ptrs = ft_lstnew(NULL, 0);
	if (ptrs == NULL)
		return (NULL);
// clear list + perror
	ptrs->next = ft_lstnew(NULL, 0);
	if (ptrs == NULL)
		return (NULL);
// clear list + perror
	ptrs->next->next = ft_lstnew(NULL, 0);
	if ((ptrs->next)->next == NULL)
		return (NULL);
// clear list + perror
	ptrs->content = mlx_ptr;
	(ptrs->next)->content = win_ptr;
	((ptrs->next)->next)->content = ft_move_init();
	if (((ptrs->next)->next)->content == NULL)
		return (NULL);
// clear list + perror
	return (ptrs);
}
