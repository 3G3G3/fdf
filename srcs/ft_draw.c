#include "fdf.h"

void			ft_draw_point(int x, int y, t_list *param)
{
	mlx_pixel_put(param->content, (param->next)->content, x, y, 0xFFFFFF);
}

void			ft_draw(t_list *param)
{
	t_point		*point;
	t_list		*points;

	mlx_clear_window(param->content, (param->next)->content);
	points = ft_get_points(param);
	ft_center(points);
	ft_move(param);
	ft_projection(param);
	ft_get_win_position(param);
	while (points)
	{
		point = (t_point *)(points->content);
		ft_draw_point(point->x_w, point->z_w, param);
		if (point->h_n != NULL)
			ft_draw_line(point, point->h_n, param);
		if (point->v_n != NULL)
			ft_draw_line(point, point->v_n, param);
		points = points->next;
	}
}

// une fonction une action, rajouter une fonction print
