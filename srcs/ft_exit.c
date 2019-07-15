/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 20:38:44 by grgauthi          #+#    #+#             */
/*   Updated: 2019/07/15 21:39:07 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_exit(void *param)
{
	(void)param;
	ft_free_param(param);
	while (1)
		;
	exit(-1);
}

// remove while after leaks checks
