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

char	*ft_strdup(const char *s)
{
	int		size;
	char	*dup;

	size = 0;
	while (s[size])
		size++;
	dup = malloc(sizeof(char) * (size + 1));
	if (!dup)
		return (NULL);
	while (size >= 0)
	{
		dup[size] = s[size];
		size--;
	}
	return (dup);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

void	ft_putchar(char c, int *count, int *i)
{
	write(1, &c, 1);
	(*i)++;
	(*count)++;
}

void	ft_putstr(char *s, int *count, int *i)
{
	if (!s)
	{
		write(1, "(null)", 6);
        (*count) = (*count) + 6;
	}
    else
    {
        write(1, s, ft_strlen(s));
        (*count) = (*count) + ft_strlen(s);
    }
    (*i)++;
}

void hex_digit_write(int num, int islower)
{
	char	w;
	char	a;

	a = 'A';
	if (islower)
		a = 'a';
	if (num < 10)
		w = '0' + num;
	else
		w = a + num - 10;
	write(1, &w, 1);
}

void	hex_div(unsigned long int s, int *count, int islower)
{
    if (s < 16)
        hex_digit_write(s, islower);
    else
    {
        hex_div(s/16, count, islower);
        hex_digit_write((s%16), islower);
    }
    (*count)++;
}

void	put_adress(unsigned long int s, int *count, int *i)
{
	if (!s)
	{
		return ;
	}
	write(1, "0x", 2);
	(*count)++;
	(*count)++;
	hex_div(s, count, 1);
	(*i)++;
}

static int	estim(long n)
{
	size_t	estim;
	int		isneg;

	estim = 0;
	isneg = 0;
	if (n < 0)
	{
		estim++;
		isneg++;
		n = -n;
	}
	while (n >= 1)
	{
		estim++;
		n /= 10;
	}
	return (estim);
}

static char	*gen(char *rtn, long nbr, int len, int isneg)
{
	if (nbr != 0)
		rtn = malloc(sizeof(char) * (len + 1));
	else
		return (rtn = ft_strdup("0"));
	if (!rtn)
		return (0);
	isneg = 0;
	if (nbr < 0)
	{
		isneg++;
		nbr = -nbr;
	}
	rtn[len] = '\0';
	while (--len)
	{
		rtn[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (isneg == 1)
		rtn[0] = '-';
	else
		rtn[0] = (nbr % 10) + '0';
	return (rtn);
}

void	ft_itoa(int n, int *count, int *i)
{
	int		len;
	char	*rtn;
	long	nbr;
	int		isneg;

	nbr = n;
	len = estim(nbr);
	rtn = 0;
	isneg = 0;
	rtn = gen(rtn, nbr, len, isneg);
	if (!rtn)
		return ;
	ft_putstr(rtn, count, i);
	free(rtn);
}

void    conversions(const char *message, int *i, va_list arguments, int *count)
{
	if (message[(*i)+1] == 'c')
	{
		ft_putchar(va_arg(arguments, int), count, i);
	}
	else if (message[(*i)+1] == 's')
	{
		ft_putstr(va_arg(arguments, char*), count, i);
	}
	else if (message[(*i)+1] == 'p')
	{
		put_adress(va_arg(arguments, unsigned long int), count, i);
	}
	else if (message[(*i)+1] == 'd')
	{
		ft_itoa(va_arg(arguments, int), count, i);
	}
	else if (message[(*i)+1] == 'i')
	{
		ft_itoa(va_arg(arguments, int), count, i);
	}
	else if (message[(*i)+1] == 'u')
	{
		ft_itoa((int) va_arg(arguments, unsigned int), count, i);
	}
	else if (message[(*i)+1] == 'x')
	{
		hex_div(va_arg(arguments, unsigned long int), count, 1);
		(*i)++;
	}
	else if (message[(*i)+1] == 'X')
	{
		hex_div(va_arg(arguments, unsigned long int), count, 0);
		(*i)++;
	}
	else if (message[(*i)+1] == '%')
	{
		write(1, "%", 1);
		(*i)++;
		(*count)++;
	}
}


int	ft_printf(const char *message, ...)
{
	int		count;
	va_list	arguments;
    int i;

    i = 0;
    count = 0;
	va_start(arguments, message);
    while(message[i])
    {
        if (message[i] == '%')
        {
			//printf("%i\n", i);
			conversions(message, &i, arguments, &count);
			//printf("%i\n", i);	
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