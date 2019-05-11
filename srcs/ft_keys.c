#include "fdf.h"

int			ft_keys(int keycode, void *param)
{
	t_move	*move;

	move = ft_get_move(param);
	ft_putnbrendl(keycode);
	if (keycode == 123)
		move->theta_z = move->theta_z + M_PI / 12;
	else if (keycode == 124)
		move->theta_z = move->theta_z - M_PI / 12;
	else if (keycode == 126)
		move->theta_x = move->theta_x + M_PI / 12;
	else if (keycode == 125)
		move->theta_x = move->theta_x - M_PI / 12;
	else if (keycode == 37)
		move->t_x = move->t_x - 1;
	else if (keycode == 15)
		move->t_x = move->t_x + 1;
	else if (keycode == 2)
		move->t_z = move->t_z - 1;
	else if (keycode == 32)
		move->t_z = move->t_z + 1;

	else if (keycode == 53)
		ft_exit(param);
	ft_draw(param);
	return (0);
}
