/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_screen_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:48:19 by fcals             #+#    #+#             */
/*   Updated: 2020/03/14 05:00:03 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>

int	mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey)
{
	SDL_DisplayMode dm;

	if (!(mlx_ptr) || !(sizex) || !(sizey))
		return (0);
	if (SDL_GetDesktopDisplayMode(0, &dm) != 0)
	{
		*sizex = -1;
		*sizey = -1;
		return (0);
	}
	*sizex = dm.w;
	*sizey = dm.h;
	return (0);
}
