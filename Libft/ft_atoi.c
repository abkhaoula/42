#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	size_t	is_negative;
	int		num;

	i = 0;
	while (nptr[i] == ' ')
		i++;
	is_negative = 0;
	if (nptr[i] == '-')
	{
		i++;
		is_negative = 1;
	}
	num = 0;
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		num = num * 10;
		num = num + nptr[i] - '0';
		i++;
	}
	if (is_negative)
		num = (-1 ) * num;
	return (num);
}
