/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_flag_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:28:00 by kabdenou          #+#    #+#             */
/*   Updated: 2021/12/30 16:28:00 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

static int	read_num(const char *message, int *i)
{
	int			size;
	char		*s;
	int			space;

	size = 0;
	while ((message[(*i) + 2 + size] <= '9')
		&& (message[(*i) + 2 + size] >= '0'))
		size++;
	size++;
	s = malloc(size * sizeof(char));
	if (!s)
		return (0);
	size = 0;
	while ((message[(*i) + 2 + size] <= '9')
		&& (message[(*i) + 2 + size] >= '0'))
	{
		s[size] = message[(*i) + 2 + size];
		size++;
	}
	s[size] = 0;
	space = ft_atoi(s);
	free(s);
	(*i) = (*i) + size + 1;
	return (space);
}

static int	write_output(const char s, int space, int num, char *ss)
{
	int	count;

	count = 0;
	while (space > 0)
	{
		write(1, " ", 1);
		(count)++;
		space--;
	}
	if ((s == 'd') || (s == 'i'))
		ft_itoa(num, &count);
	else if (s == 's')
		ft_putstr(ss, &count);
	return (count);
}

void	space_flag(const char *message, va_list arguments, int *count, int *i)
{
	int		num;
	int		space;
	int		count_indent;
	char	*ss;

	space = read_num(message, i);
	count_indent = (*count);
	if ((message[(*i) + 1] == 'd') || (message[(*i) + 1] == 'i'))
	{
		num = va_arg(arguments, int);
		count_indent = ft_itoa_count(num);
		if (num >= 0)
		{
			write(1, " ", 1);
			(*count)++;
		}
		count_indent = count_indent - 1;
	}
	else if (message[(*i) + 1] == 's')
	{
		ss = va_arg(arguments, char *);
		count_indent = ft_strlen(ss);
	}
	(*count) = (*count) + write_output(message[(*i) + 1],
			space - count_indent, num, ss);
}
