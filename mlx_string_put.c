/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_string_put.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 12:41:44 by fcals             #+#    #+#             */
/*   Updated: 2020/04/09 16:45:42 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL_ttf.h>

static void	colortosdl(SDL_Color *sdl, int color)
{
	sdl->a = color & 0xff000000;
	sdl->r = color & 0x00ff0000;
	sdl->g = color & 0x0000ff00;
	sdl->b = color & 0x000000ff;
}

int	mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color,
	char *string)
{
	SDL_Surface	*image;
	SDL_Color	fg;
	TTF_Font	*font;

	if (!(mlx_ptr) || !(win_ptr) || x < 0 || y < 0 || !(string))
		return (0);
	if (!(font = TTF_OpenFont("font.ttf", 20)))
		return (0);
	colortosdl(&fg, color);
	image = TTF_RenderText_Solid(font, string, fg);
	TTF_CloseFont(font);
	if (!image)
		return (0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, image, x, y);
	SDL_FreeSurface(image);
	return (0);
}
