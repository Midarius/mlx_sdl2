/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_image_to_window.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:57:23 by fcals             #+#    #+#             */
/*   Updated: 2020/03/15 14:27:35 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <mlx_private.h>

int	mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,
	int x, int y)
{
	SDL_Texture *texture;
	SDL_Rect srcrect;
	SDL_Rect dstrect;

	if (!(mlx_ptr) || !(win_ptr) || !(img_ptr))
		return (0);
	if (!(texture = SDL_CreateTextureFromSurface(
		((t_mlx_window*)win_ptr)->render, (SDL_Surface*)img_ptr)))
		return (0);
	srcrect.x = 0;
	srcrect.y = 0;
	srcrect.w = ((SDL_Surface*)img_ptr)->w;
	srcrect.h = ((SDL_Surface*)img_ptr)->h;
	dstrect.x = x;
	dstrect.y = y;
	dstrect.w = srcrect.w;
	dstrect.h = srcrect.h;
	SDL_RenderCopy(((t_mlx_window*)win_ptr)->render, texture,
		&srcrect, &dstrect);
	SDL_RenderPresent(((t_mlx_window*)win_ptr)->render);
	SDL_DestroyTexture(texture);
	return (0);
}
