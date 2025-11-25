#include "../inc/main.h"

t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex	result;

	result.real = a.real + b.real;
	result.imag = a.imag + b.imag;
	return (result);
}

t_complex	complex_square(t_complex a)
{
	t_complex	result;

	result.real = a.real * a.real - a.imag * a.imag;
	result.imag = 2 * (a.real * a.imag);
	return (result);
}

t_complex	pixel_to_complex_zoom(int x, int y, t_fractol *fractol)
{
	t_complex	c;
	double		range;

	range = 4.0 / fractol->zoom;
	c.real = (double)(x - fractol->width / 2)
		* range / fractol->width + fractol->offset_x;
	c.imag = (double)(y - fractol->height / 2)
		* range / fractol->height + fractol->offset_y;
	return (c);
}

double	real_square(t_complex a)
{
	return ((a.real * a.real) + (a.imag * a.imag));
}
