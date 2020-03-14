/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 12:23:02 by fcals             #+#    #+#             */
/*   Updated: 2020/03/14 04:47:18 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <SDL.h>
#include <mlx.h>

void	*mlx_init(void)
{
	t_mlx_ptr *mlx_ptr;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		return (NULL);
	if (atexit(SDL_Quit) != 0)
		return (NULL);
	if (!(mlx_ptr = malloc(sizeof(t_mlx_ptr))))
		return (NULL);
	mlx_ptr->event = malloc(sizeof(t_mlx_evt) * 30);
	memset(mlx_ptr->event, 0, sizeof(t_mlx_evt) * 30);
	return ((void*)mlx_ptr);
}
