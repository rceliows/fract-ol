#include "../inc/main.h"

int	in_main_cardioid(const t_complex c)
{
	double	q;
	double	p;

	p = sqrt((c.real - 0.25) * (c.real - 0.25) + c.imag * c.imag);
	if (c.real <= p - 2 * p * p + 0.25)
		return (1);
	q = (c.real + 1) * (c.real + 1) + c.imag * c.imag;
	if (q <= 0.0625)
		return (1);
	return (0);
}

int	in_period_2_bulb(const t_complex c)
{
	double	q;

	q = (c.real + 1) * (c.real + 1) + c.imag * c.imag;
	if (q <= 0.0625)
		return (1);
	return (0);
}

int	mandelbrot_iterations(const t_complex a, int max_iterations)
{
	int			iterations;
	t_complex	i;

	if (in_main_cardioid(a) || in_period_2_bulb(a))
		return (max_iterations);
	iterations = 0;
	i.real = 0.0;
	i.imag = 0.0;
	while (real_square(i) <= 16.0 && iterations < max_iterations)
	{
		i = complex_add(complex_square(i), a);
		iterations++;
	}
	return (iterations);
}

static void	render_mandelbrot_pixel(t_fractol *fractol,
			size_t x, size_t y, int max_iter)
{
	t_complex	c;
	int			iterations;
	int			color;

	c = pixel_to_complex_zoom(x, y, fractol);
	iterations = mandelbrot_iterations(c, max_iter);
	color = get_color_advanced(iterations, max_iter,
			fractol->color_scheme, fractol->color_shift);
	set_pixel(fractol, x, y, color);
}

static void	render_mandelbrot_row(t_fractol *fractol, size_t y, int max_iter)
{
	size_t	x;

	x = 0;
	while (x < fractol->width)
	{
		render_mandelbrot_pixel(fractol, x, y, max_iter);
		x++;
	}
}

void	render_mandelbrot(t_fractol *fractol)
{
	size_t	y;
	int		max_iter;

	y = 0;
	max_iter = get_optimal_iterations(fractol->zoom);
	while (y < fractol->height)
	{
		render_mandelbrot_row(fractol, y, max_iter);
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}
