#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*string_s;
	size_t	i;

	*string_s = s;
	i = 0;
	while (i < n)
	{
		string_s[i] = c;
		i++;
	}
	return (s);
}
