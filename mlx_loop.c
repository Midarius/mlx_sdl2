/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:48:45 by fcals             #+#    #+#             */
/*   Updated: 2020/03/15 17:01:07 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <SDL.h>
#include <mlx_private.h>

static void	check_events(t_mlx_ptr *mlx_ptr)
{
	SDL_Event evt;

	SDL_PollEvent(&evt);
	if (evt.type == SDL_MOUSEBUTTONDOWN && mlx_ptr->event[4].set)
		mlx_ptr->event[4].callback((int)evt.button.button, evt.button.x,
		evt.button.y, mlx_ptr->event[4].param);
	else if (evt.type == SDL_MOUSEBUTTONUP && mlx_ptr->event[5].set)
		mlx_ptr->event[5].callback((int)evt.button.button, evt.button.x,
		evt.button.y, mlx_ptr->event[5].param);
	else if (evt.type == SDL_KEYDOWN && mlx_ptr->event[2].set)
		mlx_ptr->event[2].callback(
		(int)evt.key.keysym.sym, mlx_ptr->event[2].param);
	else if (evt.type == SDL_KEYUP && mlx_ptr->event[3].set)
		mlx_ptr->event[3].callback(
		(int)evt.key.keysym.sym, mlx_ptr->event[3].param);
	else if (evt.type == SDL_QUIT && mlx_ptr->event[17].set)
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
