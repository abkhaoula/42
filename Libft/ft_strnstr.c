#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!little[0])
		return ((char *) big);
	while ((big[i]) && (little[j]) && (i < len - 1))
	{
		if (big[i] == little[j])
			j++;
		else
			j = 0;
		i++;
	}
	if (!little[j])
		return ((char *) big + i - j);
	return (NULL);
}
