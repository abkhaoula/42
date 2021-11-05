#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*string_s;
	size_t	i;

	string_s = s;
	i = 0;
	while (i < n)
	{
		string_s[i] = '\0';
		i++;
	}
}
