#include "../inc/main.h"

int	tricorn_iterations(const t_complex c, int max_iterations)
{
	int			iterations;
	t_complex	z;

	iterations = 0;
	z.real = 0.0;
	z.imag = 0.0;
	while (real_square(z) <= 16.0 && iterations < max_iterations)
	{
		z = complex_add(complex_conjugate_square(z), c);
		iterations++;
	}
	return (iterations);
}

static void	render_tricorn_pixel(t_fractol *fractol, size_t x,
			size_t y, int max_iter)
{
	t_complex	c;
	int			iterations;
	int			color;

	c = pixel_to_complex_zoom(x, y, fractol);
	iterations = tricorn_iterations(c, max_iter);
	color = get_color_advanced(iterations, max_iter,
			fractol->color_scheme, fractol->color_shift);
	set_pixel(fractol, x, y, color);
}

static void	render_tricorn_row(t_fractol *fractol, size_t y, int max_iter)
{
	size_t	x;

	x = 0;
	while (x < fractol->width)
	{
		render_tricorn_pixel(fractol, x, y, max_iter);
		x++;
	}
}

void	render_tricorn(t_fractol *fractol)
{
	size_t	y;
	int		max_iter;

	y = 0;
	max_iter = get_optimal_iterations(fractol->zoom);
	while (y < fractol->height)
	{
		render_tricorn_row(fractol, y, max_iter);
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}
