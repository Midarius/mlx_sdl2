/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 12:23:02 by fcals             #+#    #+#             */
/*   Updated: 2020/03/15 16:51:12 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <SDL.h>
#include <mlx_private.h>

static t_mlx_ptr	*mlx_ptr_init(void)
{
	t_mlx_ptr *mlx_ptr;
	if (!(mlx_ptr = malloc(sizeof(t_mlx_ptr))))
		return (NULL);
	memset(mlx_ptr, 0, sizeof(t_mlx_ptr));
	if (!(mlx_ptr->event = malloc(sizeof(t_mlx_evt) * 30)))
	{
		free(mlx_ptr);
		return (NULL);
	}
	memset(mlx_ptr->event, 0, sizeof(t_mlx_evt) * 30);
	return(mlx_ptr);
}

void	mlx_exit(void)
{
	t_mlx_ptr *mlx_ptr;

	if (!(mlx_ptr = mlx_init()))
		return ;
	if (mlx_ptr->event)
		free(mlx_ptr->event);
	free(mlx_ptr);
}

void	*mlx_init(void)
{
	static t_mlx_ptr *mlx_ptr = NULL;

	if (mlx_ptr != NULL)
		return ((void*)mlx_ptr);
	if (!(mlx_ptr = mlx_ptr_init()))
		return (NULL);
	if (SDL_Init(SDL_INIT_VIDEO) != 0 || atexit(SDL_Quit) != 0 ||
	atexit(mlx_exit) != 0)
	{
		SDL_Quit();
		mlx_exit();
		return (NULL);
	}
	mlx_ptr->event = malloc(sizeof(t_mlx_evt) * 30);
	memset(mlx_ptr->event, 0, sizeof(t_mlx_evt) * 30);
	return ((void*)mlx_ptr);
}
