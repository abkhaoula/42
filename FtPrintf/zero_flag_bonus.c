/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_flag_bonus.c                                  :+:      :+:    :+:   */
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

static void	write_zero(int space, int *count)
{
	while (space > 0)
	{
		write(1, "0", 1);
		(*count)++;
		space--;
	}
}

static long int	tmp(char s, va_list arguments, int *count, int space)
{
	long int	num;

	if ((s == 'd') || (s == 'i'))
	{
		num = va_arg(arguments, int);
		space = space - ft_itoa_count(num);
		if (num < 0)
		{
			ft_putchar('-', count);
			if (num != -2147483648)
				num = -num;
		}
	}
	else if (s == 'u')
	{
		num = va_arg(arguments, unsigned int);
		space = space - ft_itoa_u_count(num);
	}
	else if ((s == 'x') || (s == 'X'))
	{
		num = va_arg(arguments, unsigned);
		space = space - hex_div_count(num, 1);
	}
	write_zero(space, count);
	return (num);
}

void	zero_flag(const char *message, va_list arguments, int *count, int *i)
{
	long int	num;
	int			space;

	space = read_num(message, i);
	num = tmp(message[(*i) + 1], arguments, count, space);
	if ((message[(*i) + 1] == 'd') || (message[(*i) + 1] == 'i'))
	{
		if (num == -2147483648)
		{
			write(1, "2147483648", 10);
			(*count) = (*count) + 10;
		}
		else
			ft_itoa(num, count);
	}
	else if (message[(*i) + 1] == 'u')
		ft_itoa_u(num, count);
	else if (message[(*i) + 1] == 'x')
		hex_div(num, count, 1);
	else if (message[(*i) + 1] == 'X')
		hex_div(num, count, 0);
}
