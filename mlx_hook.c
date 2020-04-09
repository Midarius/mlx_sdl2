/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:40:11 by fcals             #+#    #+#             */
/*   Updated: 2020/04/09 22:12:27 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <mlx_private.h>

static void	add_event(t_mlx_evt *evt, int (*f)(), void *param)
{
	evt->set = 1;
	evt->callback = f;
	evt->param = param;
}

int			mlx_loop_hook(void *mlx_ptr, int (*f)(), void *param)
{
	if (mlx_ptr && f)
		add_event(&((t_mlx_ptr*)mlx_ptr)->loop, f, param);
	return (0);
}

int			mlx_key_hook(void *win_ptr, int (*f)(), void *param)
{
	if (win_ptr && f)
		add_event(&((t_mlx_window*)win_ptr)->keyboard_release, f, param);
	return (0);
}

int			mlx_mouse_hook(void *win_ptr, int (*f)(), void *param)
{
	if (win_ptr && f)
		add_event(&((t_mlx_window*)win_ptr)->button_release, f, param);
	return (0);
}

int			mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(),
	void *param)
{
	(void)x_mask;
	if (!(win_ptr) || x_event < 0 || !(funct))
		return (0);
	if (x_event == 0)
		mlx_loop_hook(((t_mlx_window*)win_ptr)->mlx_ptr, funct, param);
	else if (x_event == 2)
		add_event(&((t_mlx_window*)win_ptr)->keyboard_press, funct, param);
	else if (x_event == 3)
		mlx_key_hook(win_ptr, funct, param);
	else if (x_event == 4)
		add_event(&((t_mlx_window*)win_ptr)->button_press, funct, param);
	else if (x_event == 5)
		mlx_mouse_hook(win_ptr, funct, param);
	else if (x_event == 17)
		add_event(&((t_mlx_window*)win_ptr)->close, funct, param);
	return (0);
}
