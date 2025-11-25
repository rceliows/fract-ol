#include "../inc/main.h"

static void	error_exit(t_fractol *fractol, int i)
{
	if (i == 0)
	{
		ft_printf("Error: Failed to initialize MiniLibX\n");
		cleanup_fractol(fractol);
		exit(1);
	}
	if (i == 1)
	{
		ft_printf("Error: Failed to create window\n");
		cleanup_fractol(fractol);
		exit(1);
	}
	if (i == 2)
	{
		ft_printf("Error: Failed to create image\n");
		cleanup_fractol(fractol);
		exit(1);
	}
}

void	init_fractol(t_fractol *fractol)
{
	fractol->width = 800;
	fractol->height = 600;
	fractol->zoom = 1.0;
	fractol->offset_x = 0.0;
	fractol->offset_y = 0.0;
	fractol->max_iter = 100;
	fractol->color_scheme = 0;
	fractol->color_shift = 0.0;
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		error_exit(fractol, 0);
	fractol->win = mlx_new_window(fractol->mlx,
			fractol->width, fractol->height, "Fract'ol");
	if (!fractol->win)
		error_exit(fractol, 1);
	fractol->img = mlx_new_image(fractol->mlx, fractol->width, fractol->height);
	if (!fractol->img)
		error_exit(fractol, 2);
	fractol->img_data = mlx_get_data_addr(fractol->img,
			&fractol->bits_per_pixel, &fractol->line_length, &fractol->endian);
}

void	render_fractal(t_fractol *fractol)
{
	if (fractol->fractal_type == MANDELBROT)
		render_mandelbrot(fractol);
	else if (fractol->fractal_type == JULIA)
		render_julia(fractol);
}

int	get_optimal_iterations(double zoom)
{
	int	base_iter;

	base_iter = 100;
	if (zoom < 1.0)
		return (base_iter);
	else if (zoom < 10.0)
		return (base_iter + 50);
	else if (zoom < 100.0)
		return (base_iter + 100);
	else
		return (base_iter + 200);
}
