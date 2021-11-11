#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dup;

	if (ft_strlen(s) < start)
		return ("");
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
	{
		return (NULL);
	}
	i = 0;
	while ((i < len) && (s[start + i]))
	{
		dup[i] = s[start + i];
		i++;
	}
	return (dup);
}
