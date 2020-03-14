# mlx_sdl2
minilibx made with SDL2.
## Getting Started
### Prerequisites
 * SDL2
Download the development libraries at http://www.libsdl.org/download-2.0.php
**OR**
Use a package manager (Brew, Advanced Packaging Tool, ...)
 * SDL_Image
 Download the development libraries at https://www.libsdl.org/projects/SDL_image/

## Limitations
Some behaviors of the minilibx has changed with the use of SDL2. Note that these behaviors are considered as bugs and will be fixed asap
 - Due to event implementation, mlx_ptr leaks if mlx_destroy_window is not called at least once
 - Alpha is 0-255 and 0 mean full transparancy
 - Only 4 event is handled (keypress, keyrelease, destroynotify, loop_hook)

### Not yet implemented
```c
int	mlx_clear_window(void *mlx_ptr, void *win_ptr);
uint	mlx_get_color_value(void *mlx_ptr, int color);
int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
int	mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);
int	mlx_mouse_hook (void *win_ptr, int (*f)(), void *param);
void	*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data, int *width, int *height);
int	mlx_mouse_hide();
int	mlx_mouse_show();
int	mlx_mouse_move(void *win_ptr, int x, int y);
int	mlx_mouse_get_pos(void *win_ptr, int *x, int *y);
int	mlx_do_key_autorepeatoff(void *mlx_ptr);
int	mlx_do_key_autorepeaton(void *mlx_ptr);
```
## License
This project is licensed under the MIT License - see the LICENSE.md file for details
