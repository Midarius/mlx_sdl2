/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_destroy_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:26:46 by fcals             #+#    #+#             */
/*   Updated: 2020/03/13 15:27:47 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>

int	mlx_destroy_image(void *mlx_ptr, void *img_ptr)
{
	if (mlx_ptr && img_ptr)
		SDL_FreeSurface((SDL_Surface*)img_ptr);
	return (0);
}
