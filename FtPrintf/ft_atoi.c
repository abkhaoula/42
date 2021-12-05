/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
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


static int	is_neg(char *nptr, int *i)
{
    size_t	is_negative;

    is_negative = 0;
    if (nptr[*i] == '-')
    {
        (*i)++;
        is_negative = 1;
    }
    else if (nptr[*i] == '+')
        (*i)++;
    return (is_negative);
}

int	ft_atoi(char *nptr)
{
	int		i;
	size_t	is_negative;
	int		num;

	i = 0;
	while ((nptr[i]) && (nptr[i] == '\t' || nptr[i] == '\v' || nptr[i] == '\f'
		|| nptr[i] == '\r' || nptr[i] == '\n' || nptr[i] == ' '))
		i++;
	is_negative = is_neg(nptr, &i);
	num = 0;
	while ((nptr[i]) && (nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		if (num >= 1000000000)
		{
			if (is_negative)
				return (0);
			return (-1);
		}
		num = num * 10;
		num = num + nptr[i] - '0';
		i++;
	}
	if (is_negative)
		num = (-1) * num;
	return (num);
}