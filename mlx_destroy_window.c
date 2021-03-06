/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_destroy_window.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 13:46:28 by fcals             #+#    #+#             */
/*   Updated: 2020/03/15 16:49:10 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <mlx_private.h>

int	mlx_destroy_window(void *mlx_ptr, void *win_ptr)
{
	if (!(mlx_ptr) || !(win_ptr))
		return (0);
	SDL_DestroyWindow(((t_mlx_window*)win_ptr)->window);
	SDL_DestroyRenderer(((t_mlx_window*)win_ptr)->render);
	return (0);
}
