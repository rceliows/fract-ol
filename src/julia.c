#include "../inc/main.h"

int	julia_iterations(t_complex i, const t_complex c, int max_iterations)
{
	int	iterations;

	iterations = 0;
	while (real_square(i) <= 16.0 && iterations < max_iterations)
	{
		i = complex_add(complex_square(i), c);
		iterations++;
	}
	return (iterations);
}

static void	render_julia_pixel(t_fractol *fractol, size_t x,
			size_t y, int max_iter)
{
	t_complex	z;
	int			iterations;
	int			color;

	z = pixel_to_complex_zoom(x, y, fractol);
	iterations = julia_iterations(z, fractol->julia_c, max_iter);
	color = get_color_advanced(iterations, max_iter,
			fractol->color_scheme, fractol->color_shift);
	set_pixel(fractol, x, y, color);
}

static void	render_julia_row(t_fractol *fractol, size_t y, int max_iter)
{
	size_t	x;

	x = 0;
	while (x < fractol->width)
	{
		render_julia_pixel(fractol, x, y, max_iter);
		x++;
	}
}

void	render_julia(t_fractol *fractol)
{
	size_t	y;
	int		max_iter;

	y = 0;
	max_iter = get_optimal_iterations(fractol->zoom);
	while (y < fractol->height)
	{
		render_julia_row(fractol, y, max_iter);
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}
