#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*dup;

	i = 0;
	while ((s[i]) && (s[i] != (char)start))
		i++;
	if (!s[i])
		return (NULL);
	dup = malloc(sizeof(char) * (len + 1));
	while ((s[i + j]) && (j < len))
	{
		dup[j] = s[i + j];
		j++;
	}
	dup[j] = '\0';
	return (dup);
}
