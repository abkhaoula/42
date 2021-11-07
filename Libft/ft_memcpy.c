#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*string_dest;
	const char	*string_src;
	size_t		i;

	string_dest = dest;
	string_src = src;
	i = 0;
	while (i < n)
	{
		string_dest[i] = string_src[i];
		i++;
	}
	return (dest);
}
