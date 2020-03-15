/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_clear_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 01:26:21 by fcals             #+#    #+#             */
/*   Updated: 2020/03/15 14:28:11 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <mlx_private.h>

int	mlx_clear_window(void *mlx_ptr, void *win_ptr)
{
	if (!(mlx_ptr) || !(win_ptr))
		return (0);
	SDL_SetRenderDrawColor(((t_mlx_window*)win_ptr)->render, 0, 0, 0,
	SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(((t_mlx_window*)win_ptr)->render, NULL);
	return (0);
}
