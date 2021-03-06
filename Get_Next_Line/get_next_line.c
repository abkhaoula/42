/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:28:00 by kabdenou          #+#    #+#             */
/*   Updated: 2021/11/23 16:28:00 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_leftover(char *leftover)
{
	int		i;
	char	*new;

	i = 0;
	while (leftover[i] && leftover[i] != '\n')
		i++;
	if (!leftover[i])
	{
		free(leftover);
		return (NULL);
	}
	new = ft_substr(leftover, i + 1, ft_strlen(leftover) - i);
	free(leftover);
	return (new);
}

char	*get_line(char *leftover)
{
	int		i;
	char	*next_line;

	i = 0;
	if (!leftover[0])
		return (NULL);
	while (leftover[i] && leftover[i] != '\n')
		i++;
	next_line = (char *)malloc(sizeof(char) * (i + 2));
	if (!next_line)
		return (NULL);
	i = 0;
	while (leftover[i] && leftover[i] != '\n')
	{
		next_line[i] = leftover[i];
		i++;
	}
	if (leftover[i] == '\n')
		next_line[i++] = '\n';
	next_line[i] = 0;
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	leftover = read_file(fd, leftover);
	if (!leftover)
		return (NULL);
	next_line = get_line(leftover);
	leftover = get_leftover(leftover);
	return (next_line);
}
