#include "../inc/main.h"

int	color_default(int iterations, int max_iterations, double color_shift)
{
	int		r;
	int		g;
	int		b;
	double	ratio;

	if (iterations == max_iterations)
		return (0x000000);
	ratio = (double)iterations / max_iterations;
	r = (int)(255 * (ratio + color_shift)) % 256;
	if (r < 0)
		r = 0;
	g = (int)(255 * (1.0 - ratio + color_shift)) % 256;
	if (g < 0)
		g = 0;
	b = (int)(128 + 64 * sin(color_shift * 6.28)) % 256;
	if (b < 0)
		b = 0;
	return ((r << 16) | (g << 8) | b);
}

int	color_rainbow(int iterations, int max_iterations, double color_shift)
{
	int		r;
	int		g;
	int		b;
	double	ratio;

	if (iterations == max_iterations)
		return (0x000000);
	ratio = (double)iterations / max_iterations;
	r = (int)(128 + 127 * sin((ratio + color_shift) * 3.14159 * 2));
	if (r < 0)
		r = 0;
	g = (int)(128 + 127 * sin((ratio + color_shift) * 3.14159 * 2 + 2.09));
	if (g < 0)
		g = 0;
	b = (int)(128 + 127 * sin((ratio + color_shift) * 3.14159 * 2 + 4.18));
	if (b < 0)
		b = 0;
	return ((r << 16) | (g << 8) | b);
}

int	color_fire(int iterations, int max_iterations, double color_shift)
{
	int		r;
	int		g;
	int		b;
	double	ratio;

	if (iterations == max_iterations)
		return (0x000000);
	ratio = (double)iterations / max_iterations;
	r = (int)(255 * (ratio + color_shift * 0.3)) % 256;
	if (r < 0)
		r = 0;
	g = (int)(255 * ((ratio * ratio) + color_shift * 0.2)) % 256;
	if (g < 0)
		g = 0;
	b = (int)(128 * ((ratio * ratio * ratio) + color_shift * 0.1)) % 256;
	if (b < 0)
		b = 0;
	return ((r << 16) | (g << 8) | b);
}

int	color_ice(int iterations, int max_iterations, double color_shift)
{
	int		r;
	int		g;
	int		b;
	double	ratio;

	if (iterations == max_iterations)
		return (0x000000);
	ratio = (double)iterations / max_iterations;
	r = (int)(128 * (ratio + color_shift * 0.2)) % 256;
	if (r < 0)
		r = 0;
	g = (int)(192 * (ratio + color_shift * 0.3)) % 256;
	if (g < 0)
		g = 0;
	b = (int)(255 * (ratio + color_shift * 0.4)) % 256;
	if (b < 0)
		b = 0;
	return ((r << 16) | (g << 8) | b);
}

int	color_psychedelic(int iterations, int max_iterations, double color_shift)
{
	int		r;
	int		g;
	int		b;
	double	ratio;

	if (iterations == max_iterations)
		return (0x000000);
	ratio = (double)iterations / max_iterations;
	r = (int)(128 + 127 * sin((ratio + color_shift) * 20));
	if (r < 0)
		r = 0;
	g = (int)(128 + 127 * cos((ratio + color_shift) * 15));
	if (g < 0)
		g = 0;
	b = (int)(128 + 127 * sin((ratio + color_shift) * 25));
	if (b < 0)
		b = 0;
	return ((r << 16) | (g << 8) | b);
}
