/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:28:00 by kabdenou          #+#    #+#             */
/*   Updated: 2021/11/23 16:28:00 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, int start, int len)
{
	char			*substr;
	int				i;
	int				len_str;

	if (!s)
		return (NULL);
	len_str = ft_strlen(s);
	if (start >= len_str)
		len = 0;
	else if (len > len_str)
		len = len_str;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = -1;
	while (++i < len && s[i])
		substr[i] = s[i + start];
	substr[i] = 0;
	return (substr);
}

int	ft_is_new_line(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		if (s[i++] == '\n')
			return (1);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*s;
	int				i;
	int				j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = 0;
	}
	if (!s1)
		return (NULL);
	s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		s[i++] = s1[j++];
	j = 0;
	while (s2[j])
		s[i++] = s2[j++];
	s[i] = 0;
	free(s1);
	return (s);
}

char	*read_file(int fd, char *leftover)
{
	char	*next_buff;
	int		isnt_eof;

	next_buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!next_buff)
		return (NULL);
	isnt_eof = 1;
	while (!ft_is_new_line(leftover) && isnt_eof != 0)
	{
		isnt_eof = read(fd, next_buff, BUFFER_SIZE);
		if (isnt_eof == -1)
		{
			free(next_buff);
			return (NULL);
		}
		next_buff[isnt_eof] = 0;
		leftover = ft_strjoin(leftover, next_buff);
	}
	free(next_buff);
	return (leftover);
}
