/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:48:45 by fcals             #+#    #+#             */
/*   Updated: 2020/03/14 12:18:12 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <SDL.h>
#include <mlx.h>

static void test_keycode(SDL_KeyboardEvent *key)
{
	SDL_Log("scancode: %x, sym: %x\n", key->keysym.scancode, key->keysym.sym);
}

static void	check_events(t_mlx_ptr *mlx_ptr)
{
	SDL_Event evt;

	SDL_PollEvent(&evt);
	if (evt.type == SDL_KEYDOWN)
	{
		test_keycode(&evt.key);
		mlx_ptr->event[2].callback(
		(int)evt.key.keysym.sym, mlx_ptr->event[2].param);
	}
	else if (evt.type == SDL_KEYUP)
	{
		test_keycode(&evt.key);
		mlx_ptr->event[3].callback(
		(int)evt.key.keysym.sym, mlx_ptr->event[3].param);
	}
	else if (evt.type == SDL_QUIT)
		mlx_ptr->event[17].callback(mlx_ptr->event[17].param);
}

int			mlx_loop(void *mlx_ptr)
{
	while (1)
	{
		check_events((t_mlx_ptr*)mlx_ptr);
		((t_mlx_ptr*)mlx_ptr)->event[0].callback(
			((t_mlx_ptr*)mlx_ptr)->event[0].param);
	}
	return (0);
}
