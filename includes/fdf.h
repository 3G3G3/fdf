/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:41:58 by grgauthi          #+#    #+#             */
/*   Updated: 2019/05/04 15:40:05 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <fcntl.h>

// structure du paramétrage global du tracé :
// centre du dessin

typedef	struct		s_points
{
	int				x;
	int				y;
	int				z;
	int				X;
	int				Y;
}					t_points;

t_list				*ft_readfile(char *filemname);

#endif
