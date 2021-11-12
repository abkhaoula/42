#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	int		i;

	p = ft_strdup(s);
	i = 0;
	while (p[i])
	{
		p[i] = f(i, p[i]);
		i++;
	}
	return (p);
}
