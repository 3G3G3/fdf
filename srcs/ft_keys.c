#include "fdf.h"

double		ft_rotate_angle(t_move *move)
{
	if (move->proj == 'i')
		return (M_PI / 2);
	return (M_PI / 12);
}

void		ft_change_proj_to_parallele(t_list *param)
{
	ft_get_move(param)->proj = 'p';
	ft_get_move(param)->theta_x = - asin(1 / sqrt(3));
	ft_get_move(param)->theta_z = M_PI / 4;
}

void		ft_change_proj_to_perspective(t_list *param)
{
	ft_get_move(param)->proj = 'q';
	ft_get_move(param)->theta_x = - asin(1 / sqrt(3));
	ft_get_move(param)->theta_z = M_PI / 4;
}

void		ft_change_proj_to_isometric(t_list *param)
{
	ft_get_move(param)->proj = 'i';
	ft_get_move(param)->theta_x = - M_PI / 4;
	ft_get_move(param)->theta_z = M_PI / 4;
}

void		ft_clear_move(t_list *param)
{
	t_move	*move;

	move = ft_get_move(param);
	move->t_x = 0;
	move->t_z = 0;
	move->t_height = 0;
	move->m_zoom = 0;
	if (move->proj == 'p')
		ft_change_proj_to_parallele(param);
	if (move->proj == 'i')
		ft_change_proj_to_isometric(param);
	if (move->proj == 'q')
		ft_change_proj_to_perspective(param);
	ft_center(ft_get_points(param));
	ft_move(param);
	ft_projection(param);
	ft_get_extent(param);
}

int			ft_keys(int keycode, void *param)
{
	t_move	*move;

	move = ft_get_move(param);
	ft_putnbrendl(keycode);
	if (keycode == 123)
		move->theta_z = move->theta_z + ft_rotate_angle(move);
	else if (keycode == 124)
		move->theta_z = move->theta_z - ft_rotate_angle(move);
	else if (keycode == 126)
		move->theta_x = move->theta_x + ft_rotate_angle(move);
	else if (keycode == 125)
		move->theta_x = move->theta_x - ft_rotate_angle(move);
	else if (keycode == 37)
		move->t_x = move->t_x - 1;
	else if (keycode == 15)
		move->t_x = move->t_x + 1;
	else if (keycode == 2)
		move->t_z = move->t_z - 1;
	else if (keycode == 32)
		move->t_z = move->t_z + 1;
	else if (keycode == 11)
		move->t_height++;
	else if (keycode == 1)
		move->t_height--;
	else if (keycode == 34)
		move->m_zoom++;
	else if (keycode == 31)
		move->m_zoom--;
	else if (keycode == 35 && ft_get_move(param)->proj != 'p')
		ft_change_proj_to_parallele(param);
	else if (keycode == 14 && ft_get_move(param)->proj != 'i')
		ft_change_proj_to_isometric(param);
	else if (keycode == 0 && ft_get_move(param)->proj != 'q')
		ft_change_proj_to_perspective(param);
	else if (keycode == 53)
		ft_exit(param);
	else if (keycode == 8)
		ft_clear_move(param);
	ft_draw(param);
	return (0);
}
