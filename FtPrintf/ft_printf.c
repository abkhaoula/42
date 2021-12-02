/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:28:00 by kabdenou          #+#    #+#             */
/*   Updated: 2021/12/30 16:28:00 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

void	conversions(const char *message, va_list arguments, int *count, int i)
{
	if (message[i + 1] == 'c')
		ft_putchar(va_arg(arguments, int), count);
	else if (message[i + 1] == 's')
		ft_putstr(va_arg(arguments, char *), count);
	else if (message[i + 1] == 'p')
		put_adress(va_arg(arguments, unsigned long int), count);
	else if (message[i + 1] == 'd')
		ft_itoa(va_arg(arguments, int), count);
	else if (message[i + 1] == 'i')
		ft_itoa(va_arg(arguments, int), count);
	else if (message[i + 1] == 'u')
		ft_itoa_u(va_arg(arguments, unsigned int), count);
	else if (message[i + 1] == 'x')
		hex_div(va_arg(arguments, unsigned), count, 1);
	else if (message[i + 1] == 'X')
		hex_div(va_arg(arguments, unsigned), count, 0);
	else if (message[i + 1] == '%')
	{
		write(1, "%", 1);
		(*count)++;
	}
}

int	ft_printf(const char *message, ...)
{
	int		count;
	va_list	arguments;
	int		i;

	i = 0;
	count = 0;
	va_start(arguments, message);
	while (message[i])
	{
		if (message[i] == '%')
		{
			conversions(message, arguments, &count, i);
			i++;
		}
		else
		{
			write(1, &message[i], 1);
			count++;
		}
		i++;
	}
	va_end(arguments);
	return (count);
}
