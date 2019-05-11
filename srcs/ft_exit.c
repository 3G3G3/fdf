#include "fdf.h"

void		ft_exit(void *param)
{
 (void)param;
	mlx_destroy_window(((t_list *)(param))->content,
		((t_list *)(((t_list *)(param))->next))->content);
	exit(-1);
}
