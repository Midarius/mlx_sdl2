/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_get_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 14:40:43 by fcals             #+#    #+#             */
/*   Updated: 2020/03/15 15:42:26 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>

int	mlx_mouse_get_pos(void *win_ptr, int *x, int *y)
{
	(void)win_ptr;
	if (x && y)
		SDL_GetMouseState(x, y);
	return (0);
}
