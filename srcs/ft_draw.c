#include "fdf.h"

void			ft_draw(t_list *param)
{
	t_point		*point;
	t_list		*points;
	double		zoom;

	mlx_clear_window(param->content, (param->next)->content);
	points = ft_get_points(param);
//	ft_adjust_position(param);
	ft_center(points);
	ft_move(param);
	zoom = ft_parallele_proj(param);
	zoom = 20;
	while (points)
	{
		point = (t_point *)(points->content);
		mlx_pixel_put(param->content,
			(param->next)->content,
			W_WIN / 2 + point->x_p * 0.4 * W_WIN / zoom,
			H_WIN / 2 + point->z_p * 0.4 * H_WIN / zoom,
			0xFFFFFF);
		points = points->next;
	}
}
