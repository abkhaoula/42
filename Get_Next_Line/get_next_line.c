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
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

char	*protecte_gnl(int fd)
{
	char	*next_buff;
	char	tmp;
	int		isnt_eof;

	if ((BUFFER_SIZE <= 0) || (fd == -1))
		return (NULL);
	isnt_eof = read(fd, &tmp, 1);
	if (isnt_eof <= 0)
		return (NULL);
	if (!isnt_eof)
		return (ft_strdup("\0"));
	if (tmp == '\n')
		return (ft_strdup("\n"));
	next_buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!next_buff)
		return (NULL);
	next_buff[0] = tmp;
	return (next_buff);
}

int	next_stop(int fd, char **next_buff, int i)
{
	int		isnt_eof;
	char	tmp;

	isnt_eof = read(fd, &tmp, 1);
	if (!isnt_eof)
	{
		(*next_buff)[i] = '\0';
		return (1);
	}
	(*next_buff)[i] = tmp;
	if ((*next_buff)[i] == '\n')
	{
		(*next_buff)[i + 1] = '\0';
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char	*next_buff;
	char	*next_line;
	int		i;
	int		stop;

	next_buff = protecte_gnl(fd);
	if ((!next_buff) || (next_buff[0] == '\n') || (next_buff[0] == '\0'))
		return (next_buff);
	next_line = "";
	i = 1;
	stop = 0;
	while (1)
	{
		while (i < BUFFER_SIZE && (!stop))
			stop = next_stop(fd, &next_buff, i++);
		next_line = ft_strjoin(next_line, next_buff);
		if (stop)
		{
			free(next_buff);
			return (next_line);
		}
		i = 0;
	}
}
