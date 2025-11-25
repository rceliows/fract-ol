#include "../inc/main.h"

int	get_color_advanced(int iterations, int max_iterations,
		int color_scheme, double color_shift)
{
	if (iterations == max_iterations)
		return (0x000000);
	if (color_scheme == 0)
		return (color_default(iterations, max_iterations, color_shift));
	else if (color_scheme == 1)
		return (color_rainbow(iterations, max_iterations, color_shift));
	else if (color_scheme == 2)
		return (color_fire(iterations, max_iterations, color_shift));
	else if (color_scheme == 3)
		return (color_ice(iterations, max_iterations, color_shift));
	else if (color_scheme == 4)
		return (color_psychedelic(iterations, max_iterations, color_shift));
	else
		return (1);
}

void	set_pixel(t_fractol *fractol, size_t x, size_t y, int color)
{
	char	*pixel_ptr;

	if (x < fractol->width && y < fractol->height)
	{
		pixel_ptr = fractol->img_data
			+ (y * fractol->line_length + x * (fractol->bits_per_pixel / 8));
		*(unsigned int *)pixel_ptr = color;
	}
}
