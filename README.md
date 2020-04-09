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
### Color format
Alpha is 0-255 and 0 mean full transparency
### Events
Only 6 events:
* `00`: Loop
* `02`: KeyPress
* `03`: KeyRelease
* `04`: ButtonPress
* `05`: ButtonRelease
* `17`: DestroyNotify
### KeyCodes
Code send by keypress/keyrelease/buttonpress/buttonrelease are SDL code,
 see:
 http://wiki.libsdl.org/SDL_MouseButtonEvent
 http://wiki.libsdl.org/SDLKeycodeLookup
### Not yet implemented
Theses functions has no effect when called (it will not crash)
```c
unsigned int	mlx_get_color_value(void *mlx_ptr, int color);
int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
int	mlx_do_key_autorepeatoff(void *mlx_ptr);
int	mlx_do_key_autorepeaton(void *mlx_ptr);
int	mlx_do_sync(void *mlx_ptr);
```
## License
This project is licensed under the MIT License - see the LICENSE.md file for details
