#include "libft.h"
#include <stdlib.h>

int	start_trim(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while ((s1[i]))
	{
		j = 0;
		while ((set[j]) && (s1[i] != set[j]))
			j++;
		if (!set[j])
			break ;
		i++;
	}
	return (i);
}

int	end_trim(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = ft_strlen(s1) -1;
	while (i > 0)
	{
		j = 0;
		while ((set[j]) && (s1[i] != set[j]))
			j++;
		if (!set[j])
			break ;
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*trim;

	start = start_trim(s1, set);
	end = end_trim(s1, set);
	trim = malloc(sizeof(char) * (end - start + 2));
	if (!trim)
		return (NULL);
	i = start;
	while (i <= end)
	{
		trim[i - start] = s1[i];
		i++;
	}
	trim[i - start] = '\0';
	return (trim);
}
