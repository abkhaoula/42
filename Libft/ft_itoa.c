/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:28:00 by kabdenou          #+#    #+#             */
/*   Updated: 2021/11/12 16:28:00 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

int	*num_len(int n)
{
	int	i;
	int	tens;
	int	*t;

	t = malloc(sizeof(int) * 2);
	i = 0;
	tens = 1;
	while (((n / tens) != 0) && (tens < 1000000000))
	{
		i++;
		tens = tens * 10;
	}
	if ((n != 0) && ((n / tens) == 0))
		tens = tens / 10;
	t[0] = i;
	t[1] = tens;
	return (t);
}

char	*ft_itoa(int n)
{
	int		tens;
	int		i;
	char	*num;

	if (n == -2147483648)
		return ("-2147483648");
	tens = num_len(n)[1];
	num = malloc(sizeof(char) * (num_len(n)[0] + 2));
	i = 0;
	if (n < 0)
	{
		num[i] = '-';
		n = n * (-1);
		i++;
	}
	while (tens > 0)
	{
		num[i] = '0' + (n / tens);
		n = n % tens;
		tens = tens / 10;
		i++;
	}
	num[i] = '\0';
	return (num);
}
