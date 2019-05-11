#include "fdf.h"

void		ft_draw(t_list *points, void *mlx_ptr, void *win_ptr)
{
	while (points)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, ((t_point *)(points->content))->X,
			((t_point *)(points->content))->Z, 0xFFFFFF);
		points = points->next;
	}
}
