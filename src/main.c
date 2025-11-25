#include "../inc/main.h"

void	available_options(char *program_name)
{
	ft_printf("Available fractals:\n");
	ft_printf("  mandelbrot\n");
	ft_printf("  julia [real number] [imaginary number]\n");
	ft_printf("Examples:\n");
	ft_printf("  %s mandelbrot\n", program_name);
	ft_printf("  %s julia -0.7 0.27015\n", program_name);
}

void	available_controls(void)
{
	ft_printf("Controls:\n");
	ft_printf("- Mouse wheel: Zoom in/out\n");
	ft_printf("- Arrow keys or WASD: Move view\n");
	ft_printf("- C: Change color scheme\n");
	ft_printf("- E/Q: Adjust color shift\n");
	ft_printf("- ESC: Exit\n");
}

void	prep_julia(char **argv, t_fractol *fractol)
{
	fractol->fractal_type = JULIA;
	fractol->julia_c.real = ft_atof(argv[2]);
	fractol->julia_c.imag = ft_atof(argv[3]);
}

void	prep_hooks(t_fractol *fractol)
{
	mlx_hook(fractol->win, 2, 1L << 0, key_dispatcher, fractol);
	mlx_hook(fractol->win, 17, 1L << 17, handle_close, fractol);
	mlx_hook(fractol->win, 4, 1L << 2, handle_mouse, fractol);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc < 2)
	{
		available_options(argv[0]);
		return (1);
	}
	if (ft_strcmp(argv[1], "mandelbrot") == 0 && argc == 2)
		fractol.fractal_type = MANDELBROT;
	else if (ft_strcmp(argv[1], "julia") == 0 && argc == 4
		&& (ft_strvalid(argv[2]) && ft_strvalid(argv[3])))
		prep_julia(argv, &fractol);
	else
	{
		ft_printf("Wrong input\n");
		available_options(argv[0]);
		return (1);
	}
	init_fractol(&fractol);
	render_fractal(&fractol);
	available_controls();
	prep_hooks(&fractol);
	mlx_loop(fractol.mlx);
	cleanup_fractol(&fractol);
	return (0);
}
