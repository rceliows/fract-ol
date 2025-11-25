#ifndef MAIN_H
# define MAIN_H

# include "../minilibx-linux/mlx.h"
# include "../libft/inc/ft_printf.h"
# include <stdlib.h>
# include <math.h>

# define MANDELBROT 1
# define JULIA 2

# define COLOR_CLASSIC 0
# define COLOR_RAINBOW 1
# define COLOR_FIRE 2
# define COLOR_ICE 3
# define COLOR_PSYCHEDELIC 4

# define WIDTH 800
# define HEIGHT 600

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_fractol
{
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
	int				max_iter;
	int				fractal_type;
	int				color_scheme;
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_data;
	double			color_shift;
	double			zoom;
	double			offset_x;
	double			offset_y;
	t_complex		julia_c;
}	t_fractol;

// Mathematical Functions
t_complex	complex_add(t_complex a, t_complex b);
t_complex	complex_square(t_complex a);
t_complex	pixel_to_complex_zoom(int x, int y, t_fractol *fractol);
double		real_square(t_complex a);

// Fractal Algorithm Functions
int			mandelbrot_iterations(t_complex c, int max_iterations);
int			julia_iterations(t_complex i, t_complex c, int max_iterations);

// Rendering Functions
void		render_mandelbrot(t_fractol *fractol);
void		render_julia(t_fractol *fractol);
void		render_fractal(t_fractol *fractol);
void		set_pixel(t_fractol *fractol, int x, int y, int color);

//Color Functions
int			get_color_advanced(int iterations, int max_iterations,
				int color_scheme, double color_shift);
int			color_default(int iterations, int max_iterations,
				double color_shift);
int			color_rainbow(int iterations, int max_iterations,
				double color_shift);
int			color_fire(int iterations, int max_iterations,
				double color_shift);
int			color_ice(int iterations, int max_iterations,
				double color_shift);
int			color_psychedelic(int iterations, int max_iterations,
				double color_shift);

// Event Handling Functions
int			key_dispatcher(int keycode, t_fractol *fractol);
int			handle_mouse(int button, int x, int y, t_fractol *fractol);
int			handle_close(t_fractol *fractol);
int			handle_esc(int keycode, t_fractol *fractol);
int			handle_colors(int keycode, t_fractol *fractol);
int			handle_arrows(int keycode, t_fractol *fractol);

// Initialization & Cleanup Functions
void		init_fractol(t_fractol *fractol);
void		cleanup_fractol(t_fractol *fractol);

// Utility Functions
int			ft_strcmp(char *s1, char *s2);
int			ft_strvalid(char *argv);
int			get_optimal_iterations(double zoom);
double		ft_atof(char *str);

#endif
