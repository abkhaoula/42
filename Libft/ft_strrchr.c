#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while ((s[i] != c) && (i >= 0))
		i--;
	if (i < 0)
		return (NULL);
	return ((char *) s + i);
}
