#include "../inc/main.h"

t_complex	complex_add(const t_complex a, const t_complex b)
{
	t_complex	result;

	result.real = a.real + b.real;
	result.imag = a.imag + b.imag;
	return (result);
}

t_complex	complex_square(const t_complex a)
{
	t_complex	result;

	result.real = a.real * a.real - a.imag * a.imag;
	result.imag = 2 * (a.real * a.imag);
	return (result);
}

t_complex	complex_conjugate_square(const t_complex a)
{
	t_complex	result;

	result.real = a.real * a.real - a.imag * a.imag;
	result.imag = -2 * (a.real * a.imag);
	return (result);
}

t_complex	pixel_to_complex_zoom(size_t x, size_t y, const t_fractol *fractol)
{
	t_complex	c;
	double		range;

	range = 4.0 / fractol->zoom;
	c.real = ((double)x - (double)(fractol->width / 2))
		* range / (double)fractol->width + fractol->offset_x;
	c.imag = ((double)y - (double)(fractol->height / 2))
		* range / (double)fractol->height + fractol->offset_y;
	return (c);
}

double	real_square(const t_complex a)
{
	return ((a.real * a.real) + (a.imag * a.imag));
}