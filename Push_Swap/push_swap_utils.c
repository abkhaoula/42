/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:28:00 by kabdenou          #+#    #+#             */
/*   Updated: 2021/12/12 16:28:00 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_sorted(long int *a, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 2)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	translate(long int *a[], int argc)
{
	long int	min;
	int			i;

	min = (*a)[0];
	i = 1;
	while (i < argc)
	{
		if (min > (*a)[i])
			min = (*a)[i];
		i++;
	}
	if (min < 0)
	{
		i = 0;
		while (i < argc - 1)
		{
			(*a)[i] -= min;
			i++;
		}
	}
}
