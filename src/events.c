#include "../inc/main.h"

int	handle_close(t_fractol *fractol)
{
	ft_printf("Cleaning and exiting...\n");
	cleanup_fractol(fractol);
	exit (0);
}

int	handle_esc(int keycode, t_fractol *fractol)
{
	if (keycode == 65307)
	{
		ft_printf("ESC pressed, exiting...\n");
		cleanup_fractol(fractol);
		exit(0);
	}
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fractol *fractol)
{
	double		zoom_factor;
	t_complex	mouse_point;

	if (button == 4)
		zoom_factor = 1.2;
	else if (button == 5)
		zoom_factor = 1.0 / 1.2;
	else
		return (0);
	mouse_point = pixel_to_complex_zoom((size_t)x, (size_t)y, fractol);
	fractol->zoom *= zoom_factor;
	fractol->offset_x = mouse_point.real - (x - (int)(fractol->width / 2))
		* (4.0 / fractol->zoom) / fractol->width;
	fractol->offset_y = mouse_point.imag - (y - (int)(fractol->height / 2))
		* (4.0 / fractol->zoom) / fractol->height;
	if (fractol->zoom > 1000000)
		fractol->zoom = 1000000;
	else if (fractol->zoom < 0.1)
		fractol->zoom = 0.1;
	render_fractal(fractol);
	return (0);
}

int	handle_colors(int keycode, t_fractol *fractol)
{
	if (keycode == 99)
	{
		fractol->color_scheme = (fractol->color_scheme + 1) % 5;
		ft_printf("Color scheme: %d\n", fractol->color_scheme);
		render_fractal(fractol);
	}
	else if (keycode == 101)
	{
		fractol->color_shift += 0.1;
		if (fractol->color_shift > 1.0)
			fractol->color_shift = 0.0;
		render_fractal(fractol);
	}
	else if (keycode == 113)
	{
		fractol->color_shift -= 0.1;
		if (fractol->color_shift < 0.0)
			fractol->color_shift = 1.0;
		render_fractal(fractol);
	}
	return (0);
}

int	handle_arrows(int keycode, t_fractol *fractol)
{
	double	move_step;

	move_step = 0.1 / fractol->zoom;
	if (keycode == 65361 || keycode == 97)
	{
		fractol->offset_x -= move_step;
		render_fractal(fractol);
	}
	else if (keycode == 65363 || keycode == 100)
	{
		fractol->offset_x += move_step;
		render_fractal(fractol);
	}
	else if (keycode == 65362 || keycode == 119)
	{
		fractol->offset_y -= move_step;
		render_fractal(fractol);
	}
	else if (keycode == 65364 || keycode == 115)
	{
		fractol->offset_y += move_step;
		render_fractal(fractol);
	}
	return (0);
}
