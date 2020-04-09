/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 17:37:41 by fcals             #+#    #+#             */
/*   Updated: 2020/04/09 15:47:28 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <mlx_private.h>

int	mlx_mouse_move(void *win_ptr, int x, int y)
{
	if (win_ptr && x >= 0 && y >= 0)
		SDL_WarpMouseInWindow(((t_mlx_window*)win_ptr)->window, x, y);
	return (0);
}
