/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
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

int	**stack_to_void(int argc)
{
	int	**stack;
	int	i;
	int	j;

	stack = malloc((argc - 1) * sizeof(int *));
	i = 0;
	while ((stack) && (i < argc - 1))
	{
		stack[i] = malloc(32 * sizeof(int));
		if (!(stack[i]))
			return (NULL);
		j = 0;
		while (j < 32)
		{
			stack[i][j] = -1;
			j++;
		}
		i++;
	}
	return (stack);
}

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

void	small_sort(int *a, int argc)
{
	int	*tmp;
	int	k;

	if (argc == 4)
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
				pab(b_stack, a_stack, argc);
				write(1, "pb\n", 3);
				count++;
			}
			else
			{
				rab(a_stack, argc, argc - 2 - count);
				write(1, "ra\n", 3);
			}
			j++;
		}
		j = 0;
		while (j < count)
		{
			pab(a_stack, b_stack, argc);
			write(1, "pa\n", 3);
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	*a;
	int	**a_stack;
	int	**b_stack;

	a = read_check_stack(argc, argv);
	if (!a)
		return (0);
	if (is_sorted(a, argc))
		return (1);
	simplify(&a, argc);
	if (argc < 7)
	{
		small_sort(a, argc);
		return (1);
	}
	a_stack = itob(a, argc);
	free(a);
	b_stack = stack_to_void(argc);
	if ((!a_stack) || (!b_stack))
		return (0);
	big_sort(&a_stack, &b_stack, argc);
	return (1);
}
