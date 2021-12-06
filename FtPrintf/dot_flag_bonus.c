/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_flag_bonus.c                                   :+:      :+:    :+:   */
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

static void	output_write(const char s, int *count, long int num)
{
	if ((s == 'd') || (s == 'i'))
	{
		if (num == -2147483648)
		{
			write(1, "2147483648", 10);
			(*count) = (*count) + 10;
		}
		else
			ft_itoa(num, count);
	}
	else if (s == 'u')
		ft_itoa_u(num, count);
	else if (s == 'x')
		hex_div(num, count, 1);
	else if (s == 'X')
		hex_div(num, count, 0);
}

static long int	tmp(char s, int *count_indent, va_list arguments, int *count)
{
	long int	num;

	if ((s == 'd') || (s == 'i'))
	{
		num = va_arg(arguments, int);
		(*count_indent) = ft_itoa_count(num);
		if ((num < 0))
		{
			(*count_indent) = (*count_indent) - 1;
			ft_putchar('-', count);
			if (num != -2147483648)
				num = -num;
		}
	}
	else if (s == 'u')
	{
		num = va_arg(arguments, unsigned int);
		(*count_indent) = ft_itoa_u_count(num);
	}
	else if ((s == 'x') || (s == 'X'))
	{
		num = va_arg(arguments, unsigned);
		(*count_indent) = hex_div_count(num, 1);
	}
	return (num);
}

void	dot_flag(const char *message, va_list arguments, int *count, int *i)
{
	long int		num;
	char			*s;
	int				space;
	int				count_indent;

	space = read_num(message, i);
	count_indent = (*count);
	if (message[(*i) + 1] == 's')
	{
		s = va_arg(arguments, char *);
		count_indent = ft_strlen(s);
		if (space < count_indent)
			count_indent = space;
		write(1, s, count_indent);
		(*count) = (*count) + count_indent;
		return ;
	}
	else
		num = tmp(message[(*i) + 1], &count_indent, arguments, count);
	while ((space--) - count_indent > 0)
	{
		write(1, "0", 1);
		(*count)++;
	}
	output_write((message[(*i) + 1]), count, num);
}
