#include "fdf.h"

void		ft_translate(int u, void *param)
{
	t_list  *points;
	t_list	*params;

	params = (t_list *)param;
	points = (params->next)->next;
	mlx_clear_window(params->content, (params->next)->content);
	while (points)
	{
		((t_point *)(points->content))->X = ((t_point *)(points->content))->X
		+ u * W_WIN / 100;
		mlx_pixel_put(params->content, (params->next)->content,
			((t_point *)(points->content))->X,
			((t_point *)(points->content))->Z,
			0xFFFFFF);
		points = points->next;
	}
//	ft_draw((params->next)->next, params->content, (params->next)->content);
}

/*
** tracer à la volée
*/
