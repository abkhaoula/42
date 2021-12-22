/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:28:00 by kabdenou          #+#    #+#             */
/*   Updated: 2021/12/12 16:28:00 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	small_sort_4(int *a)
{
	if (a[0] == 0)
		write(1, "sa\nra\n", 6);
	else if (a[0] == 1 && a[1] == 0)
		write(1, "sa\n", 3);
	else if (a[0] == 1 && a[1] == 2)
		write(1, "rra\n", 4);
	else if (a[0] == 2 && a[1] == 0)
		write(1, "ra\n", 3);
	else
		write(1, "sa\nrra\n", 7);
}

void	small_sort_6(int *a)
{
	int	k;

	k = 0;
	while (k < a[1] - 1)
	{
		write(1, "ra\n", 3);
		k++;
	}
	write(1, "pa\n", 3);
	k = 0;
	while (k < a[1] - a[0] - 1)
	{
		write(1, "rra\n", 4);
		k++;
	}
	write(1, "pa\n", 3);
	k = 0;
	while (k < a[0])
	{
		write(1, "rra\n", 4);
		k++;
	}
}

void	small_sort(int *a, int argc)
{
	int	*tmp;

	if (argc == 4)
		small_sort_4(a);
	else if (argc == 6)
	{
		write(1, "pb\npb\n", 6);
		tmp = malloc(3 * sizeof(int));
		tmp[0] = a[2];
		tmp[1] = a[3];
		tmp[2] = a[4];
		simplify(&tmp, 4);
		small_sort(tmp, 4);
		free(tmp);
		if (a[0] > a[1])
			write(1, "sb\n", 3);
		small_sort_6(a);
	}
}

void	big_sort(int ***a_stack, int ***b_stack, int argc)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (isnt_end((*a_stack), i, argc))
	{
		j = 0;
		count = 0;
		while (j < argc - 1)
		{
			if (((*a_stack)[0][i] == 0) || ((*a_stack)[0][i] == -1))
			{
				if (check_rest_pb((*a_stack), argc, i, j))
					break ;
				pb_in_sort(a_stack, b_stack, argc, &count);
			}
			else
				ra_in_sort(a_stack, argc, count);
			j++;
		}
		pa_in_sort(a_stack, b_stack, argc, count);
		i++;
	}
}
