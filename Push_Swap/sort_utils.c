/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
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

int	isnt_end(int **stack, int j, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if (stack[i][j] != -1)
			return (1);
		i++;
	}
	return (0);
}

int	check_rest_pb(int **a_stack, int argc, int i, int j)
{
	int	count;

	count = 0;
	while ((j + count) < argc - 1)
	{
		if ((a_stack[count][i] == 0) || (a_stack[count][i] == -1))
			count++;
		else
			return (0);
	}
	return (1);
}

void	pb_in_sort(int ***a_stack, int ***b_stack, int argc, int *count)
{
	pab(b_stack, a_stack, argc);
	write(1, "pb\n", 3);
	(*count)++;
}

void	ra_in_sort(int ***a_stack, int argc, int count)
{
	rab(a_stack, argc, argc - 2 - count);
	write(1, "ra\n", 3);
}

void	pa_in_sort(int ***a_stack, int ***b_stack, int argc, int count)
{
	int	j;

	j = 0;
	while (j < count)
	{
		pab(a_stack, b_stack, argc);
		write(1, "pa\n", 3);
		j++;
	}
}
