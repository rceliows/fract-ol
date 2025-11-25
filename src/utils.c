#include "../inc/main.h"

int	key_dispatcher(int keycode, t_fractol *fractol)
{
	if (keycode == 65307)
		return (handle_esc(keycode, fractol));
	else if (keycode == 99 || keycode == 101 || keycode == 113)
		return (handle_colors(keycode, fractol));
	else if (keycode == 65361 || keycode == 65363
		|| keycode == 65362 || keycode == 65364
		|| keycode == 97 || keycode == 100
		|| keycode == 119 || keycode == 115)
		return (handle_arrows(keycode, fractol));
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	count;

	count = 0;
	while (s1[count] != '\0' && s2[count] != '\0')
	{
		if (s1[count] != s2[count])
		{
			return (s1[count] - s2[count]);
		}
		count++;
	}
	return (s1[count] - s2[count]);
}

int	ft_strvalid(char *argv)
{
	size_t	i;
	int		dot_count;

	i = 0;
	dot_count = 0;
	while (((argv[i] >= 9 && argv[i] <= 13) || argv[i] == 32))
		i++;
	if (argv[i] == '+' || argv[i] == '-')
		i++;
	while (argv[i])
	{
		if (!(argv[i] < '0' || argv[i] > '9') && dot_count < 2)
			i++;
		else if (argv[i] == '.')
		{
			dot_count++;
			i++;
		}
		else
			return (0);
	}
	if (dot_count < 2)
		return (1);
	return (0);
}

void	cleanup_fractol(t_fractol *fractol)
{
	if (fractol->img)
	{
		mlx_destroy_image(fractol->mlx, fractol->img);
		fractol->img = NULL;
	}
	if (fractol->win)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		fractol->win = NULL;
	}
	if (fractol->mlx)
	{
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
		fractol->mlx = NULL;
	}
}
