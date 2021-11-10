#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*string_s;

	string_s = s;
	i = 0;
	while ((i < n) && (string_s[i]) && (string_s[i] != c))
		i++;
	if ((i == n) || (!string_s[i]))
		return (NULL);
	return ((void *) s + i);
}
