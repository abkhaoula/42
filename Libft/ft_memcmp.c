#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*string_s1;
	const unsigned char	*string_s2;

	string_s1 = s1;
	string_s2 = s2;
	i = 0;
	while ((i < n - 1) && (string_s1[i])
		&& (string_s2[i]) && (string_s1[i] == string_s2[i]))
		i++;
	if (n > 0)
		return (*(string_s1 + i) - *(string_s2 + i));
	return (0);
}
