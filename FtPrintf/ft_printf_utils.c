/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:28:00 by kabdenou          #+#    #+#             */
/*   Updated: 2021/12/30 16:28:00 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <unistd.h>

void	hex_digit_write(int num, int islower)
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
		hex_div(s / 16, count, islower);
		hex_digit_write((s % 16), islower);
	}
	(*count)++;
}

int	hex_div_count(unsigned long int s, int islower)
{
	int	count;

	count = 0;
	if (!(s < 16))
	{
		count = count + hex_div_count(s / 16, islower);
	}
	(count)++;
	return (count);
}

void	put_adress(unsigned long int s, int *count)
{
	if (!s)
	{
		write(1, "(nil)", 5);
		(*count) = (*count) + 5;
	}
	else
	{
		write(1, "0x", 2);
		(*count)++;
		(*count)++;
		hex_div(s, count, 1);
	}
}
