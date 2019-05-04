/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:12:29 by grgauthi          #+#    #+#             */
/*   Updated: 2019/05/04 15:43:05 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*res;

	res = (void *)malloc(size);
	if (!res)
	{
		return (NULL);
	}
	ft_memset(res, 0, size);
	return (res);
}
