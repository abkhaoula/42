/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
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

void	conversions_bonus(const char *message,
			va_list arguments, int *count, int *i)
{
	if (message[(*i) + 1] == '-')
		minus_flag(message, arguments, count, i);
	else if (message[(*i) + 1] == '0')
		zero_flag(message, arguments, count, i);
	else if (message[(*i) + 1] == '+')
		plus_flag(arguments, count, i);
	else if (message[(*i) + 1] == '#')
		sharp_flag(message, arguments, count, i);
	else if (message[(*i) + 1] == ' ')
		space_flag(message, arguments, count, i);
	else if (message[(*i) + 1] == '.')
		dot_flag(message, arguments, count, i);
	else
		conversions(message, arguments, count, (*i));
}
