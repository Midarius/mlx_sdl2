/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:48:45 by fcals             #+#    #+#             */
/*   Updated: 2020/04/09 23:14:42 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <SDL.h>
#include <mlx_private.h>

static void	vector_window_foreach(t_mlx_ptr *mlx_ptr,  SDL_Event *evt, void (*f)(t_mlx_window *, SDL_Event *))
{
	unsigned int i;

	i = 0;
	while (i < mlx_ptr->windows.size)
	{
		f(mlx_ptr->windows.data[i], evt);
		i++;
	}
}

static void	window_call_button_press(t_mlx_window *win, SDL_Event *evt)
{
	if (win->button_press.set)
		win->button_press.callback((int)evt->button.button, evt->button.x,
		evt->button.y, win->button_press.param);
}

static void	window_call_button_release(t_mlx_window *win, SDL_Event *evt)
{
	if (win->button_release.set)
		win->button_release.callback((int)evt->button.button, evt->button.x,
		evt->button.y, win->button_release.param);
}

static void	window_call_keyboard_press(t_mlx_window *win, SDL_Event *evt)
{
	if (win->keyboard_press.set)
		win->keyboard_press.callback((int)evt->key.keysym.sym,
		win->keyboard_press.param);
}

static void	window_call_keyboard_release(t_mlx_window *win, SDL_Event *evt)
{
	if (win->keyboard_release.set)
		win->keyboard_release.callback((int)evt->key.keysym.sym,
		win->keyboard_release.param);
}

static void	window_call_close(t_mlx_ptr *mlx_ptr, unsigned int id)
{
	unsigned int i;

	i = 0;
	while (i < mlx_ptr->windows.size)
	{
		if (SDL_GetWindowID(mlx_ptr->windows.data[i]->window) == id)
		{
			mlx_ptr->windows.data[i]->close.callback(
				mlx_ptr->windows.data[i]->close.param);
			break;
		}
		i++;
	}
}

static void	check_events(t_mlx_ptr *mlx_ptr)
{
	SDL_Event evt;

	SDL_PollEvent(&evt);
	if (evt.type == SDL_MOUSEBUTTONDOWN)
		vector_window_foreach(mlx_ptr, &evt, window_call_button_press);
	else if (evt.type == SDL_MOUSEBUTTONUP)
		vector_window_foreach(mlx_ptr, &evt, window_call_button_release);
	else if (evt.type == SDL_KEYDOWN)
		vector_window_foreach(mlx_ptr, &evt, window_call_keyboard_press);
	else if (evt.type == SDL_KEYUP)
		vector_window_foreach(mlx_ptr, &evt, window_call_keyboard_release);
	else if (evt.type == SDL_WINDOWEVENT &&
		evt.window.event == SDL_WINDOWEVENT_CLOSE)
		window_call_close(mlx_ptr, evt.window.windowID);
}

int			mlx_loop(void *mlx_ptr)
{
	while (1)
	{
		check_events((t_mlx_ptr*)mlx_ptr);
		if (((t_mlx_ptr*)mlx_ptr)->loop.set)
			((t_mlx_ptr*)mlx_ptr)->loop.callback(
			((t_mlx_ptr*)mlx_ptr)->loop.param);
	}
	return (0);
}
