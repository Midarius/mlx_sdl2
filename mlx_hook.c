/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:40:11 by fcals             #+#    #+#             */
/*   Updated: 2020/04/09 15:45:23 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <mlx_private.h>

static void	add_event(t_mlx_ptr *mlx_ptr, int evt_id, int (*f)(),
	void *param)
{
	mlx_ptr->event[evt_id].set = 1;
	mlx_ptr->event[evt_id].callback = f;
	mlx_ptr->event[evt_id].param = param;
}

int			mlx_loop_hook(void *mlx_ptr, int (*f)(), void *param)
{
	if (mlx_ptr && f)
	{
		((t_mlx_ptr*)mlx_ptr)->loop.set = 1;
		((t_mlx_ptr*)mlx_ptr)->loop.callback = f;
		((t_mlx_ptr*)mlx_ptr)->loop.param = param;
	}
	return (0);
}

int			mlx_key_hook(void *win_ptr, int (*f)(), void *param)
{
	return (mlx_hook(win_ptr, 3, 0, f, param));
}

int			mlx_mouse_hook(void *win_ptr, int (*f)(), void *param)
{
	return (mlx_hook(win_ptr, 5, 0, f, param));
}

int			mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(),
	void *param)
{
	(void)x_mask;
	if (!(win_ptr) || x_event < 0 || !(funct))
		return (0);
	if (x_event == 0)
		mlx_loop_hook(((t_mlx_window*)win_ptr)->mlx_ptr, funct, param);
	else
		add_event(((t_mlx_window*)win_ptr)->mlx_ptr, x_event, funct, param);
	return (0);
}
