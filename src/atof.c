#include "../inc/main.h"

static int	ft_parse_sign(const char *str, size_t *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
	return (sign);
}

static double	ft_parse_integer(const char *str, size_t *i)
{
	double	result;

	result = 0.0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}

static double	ft_parse_fraction(const char *str, size_t *i)
{
	double		fraction;
	size_t		decimal_places;
	size_t		j;

	fraction = 0.0;
	decimal_places = 0;
	j = 0;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			fraction = fraction * 10 + (str[*i] - '0');
			decimal_places++;
			(*i)++;
		}
	}
	while (j < decimal_places)
	{
		fraction /= 10.0;
		j++;
	}
	return (fraction);
}

double	ft_atof(const char *str)
{
	int			sign;
	size_t		i;
	double		result;
	double		fraction;

	i = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	sign = ft_parse_sign(str, &i);
	result = ft_parse_integer(str, &i);
	fraction = ft_parse_fraction(str, &i);
	return (sign * (result + fraction));
}