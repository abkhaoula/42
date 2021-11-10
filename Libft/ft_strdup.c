#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		size;
	char	*dup;

	size = 0;
	while (s[size])
		size++;
	dup = malloc(sizeof(char) * (size + 1));
	while (size >= 0)
	{
		dup[size] = s[size];
		size--;
	}
	return (dup);
}
