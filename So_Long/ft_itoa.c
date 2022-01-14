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
#include "so_long.h"
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

char	*ft_itoa(int n)
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
		return (0);
	return (rtn);
}
