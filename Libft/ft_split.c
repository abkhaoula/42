#include "libft.h"
#include <stdlib.h>

int	split_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	word_len(char const *s, char c, int position)
{
	int	i;

	i = 0;
	while ((s[i + position]) && (s[i + position] != c))
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		position;
	int		count;
	char	**p;

	count = split_count(s, c);
	p = malloc(sizeof(char *) * (count + 2));
	j = 0;
	position = 0;
	while (j < count + 1)
	{
		p[j] = malloc(sizeof(char) * (word_len(s, c, position) + 1));
		i = 0;
		while ((s[i + position]) && (s[i + position] != c))
		{
			p[j][i] = s[i + position];
			i++;
		}
		p[j][i] = '\0';
		position = position + i + 1;
		j++;
	}
	p[j] = NULL;
	return (p);
}
