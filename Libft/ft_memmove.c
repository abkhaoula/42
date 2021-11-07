#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*string_dest;
	const char	*string_src;
	size_t		i;

	string_dest = dest;
	string_src = src;
	i = 0;
	while (i < n)
	{
		string_dest[n - 1 - i] = string_src[n - 1 - i];
		i++;
	}
	return (dest);
}
