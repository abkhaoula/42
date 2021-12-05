/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sharp_flag_bonus.c                                  :+:      :+:    :+:   */
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

void	sharp_flag(const char *message, va_list arguments, int *count, int *i)
{
	unsigned num_u;
	int		size;
	char	*s;
    int 	space;
    int 	count_indent;

	size = 0;
    while ((message[(*i) + 2 + size] <= '9') && (message[(*i) + 2 + size] >= '0'))
        size++;
    size++;
    s = malloc(size * sizeof(char));
    if (!s)
        return ;
    size = 0;
    while ((message[(*i) + 2 + size] <= '9') && (message[(*i) + 2 + size] >= '0'))
    {
        s[size] = message[(*i) + 2 + size];
        size++;
    }
    s[size] = 0;
    space = ft_atoi(s);
    free(s);
    (*i) = (*i) + size + 1;
    count_indent = (*count);



    if ((message[(*i) + 1] == 'x') || (message[(*i) + 1] == 'X'))
    {
        num_u = va_arg(arguments, unsigned);
        if (num_u == 0)
            count_indent = hex_div_count(num_u, 1);
        else
            count_indent = hex_div_count(num_u, 1) + 2;
    }


    while(space - count_indent > 0)
    {
        write(1, " ", 1);
        (*count)++;
        space--;
    }

    if (message[(*i) + 1] == 'x')
    {
        if (num_u != 0)
        {
            write(1, "0x", 2);
            (*count) = (*count) + 2;
        }
        hex_div(num_u, count, 1);
    }
    else if (message[(*i) + 1] == 'X')
    {
        if (num_u != 0)
        {
            write(1, "0X", 2);
            (*count) = (*count) + 2;
        }
    	hex_div(num_u, count, 0);
    }
}
