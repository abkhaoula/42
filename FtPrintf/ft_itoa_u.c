/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:28:00 by kabdenou          #+#    #+#             */
/*   Updated: 2021/12/30 16:28:00 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdlib.h>

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

static int	estim_u(unsigned long n)
{
	size_t	estim;

	estim = 0;
	while (n >= 1)
	{
		estim++;
		n /= 10;
	}
	return (estim);
}

void	ft_itoa_u(unsigned int n, int *count)
{
	int				len;
	char			*rtn;
	unsigned long	nbr;
	int				isneg;

	nbr = n;
	len = estim_u(nbr);
	rtn = 0;
	isneg = 0;
	rtn = gen(rtn, nbr, len, isneg);
	if (!rtn)
		return ;
	ft_putstr(rtn, count);
	free(rtn);
}

int	ft_itoa_u_count(unsigned int n)
{
	int				len;
	char			*rtn;
	unsigned long	nbr;
	int				isneg;
	int				count;

	nbr = n;
	len = estim_u(nbr);
	rtn = 0;
	isneg = 0;
	rtn = gen(rtn, nbr, len, isneg);
	if (!rtn)
		return (0);
	count = ft_strlen(rtn);
	free(rtn);
	return (count);
}
