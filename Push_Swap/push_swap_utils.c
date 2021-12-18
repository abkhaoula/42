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
#include <stdlib.h>

int	is_sorted(int *a, int argc)
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

void	simplify(int *a[], int argc)
{
	int	*a_copy;
	int	i;
	int	j;
	int	k;

	a_copy = malloc((argc - 1) * sizeof(int));
	i = -1;
	while ((i < argc - 2) && (i++ || 1))
		a_copy[i] = (*a)[i];
	i = 0;
	while (i < argc - 1)
	{
		k = 0;
		j = 1;
		while (j < argc - 1)
		{
			if (a_copy[k] > a_copy[j])
				k = j;
			j++;
		}
		(*a)[k] = i;
		a_copy[k] = 2147483647;
		i++;
	}
	free(a_copy);
}
