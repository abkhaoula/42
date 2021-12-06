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
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

void	space_flag(const char *message, va_list arguments, int *count, int *i)
{
	int		num;
	int		size;
	char	*s;
    int 	space;
    int 	count_indent;
    char    *ss;

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


    while(space - count_indent > 0)
    {
        write(1, " ", 1);
        (*count)++;
        space--;
    }

    if ((message[(*i) + 1] == 'd') || (message[(*i) + 1] == 'i'))
    {
        ft_itoa(num, count);
    }
    else if (message[(*i) + 1] == 's')
    {
    	ft_putstr(ss, count);
    }
}