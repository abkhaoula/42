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

void	sort(int ***a_stack, int ***b_stack, int argc)
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
				pab(b_stack, a_stack, argc);
				printf("pb\n");
				count++;
			}
			else
			{
				rab(a_stack, argc);
				printf("ra\n");
			}
			j++;
		}
		j = 0;
		while (j < count)
		{
			pab(a_stack, b_stack, argc);
			printf("pa\n");
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
	a_stack = itob(a, argc);
	free(a);
	b_stack = stack_to_void(argc);
	if ((!a_stack) || (!b_stack))
		return (0);
	sort(&a_stack, &b_stack, argc);
	return (1);
}
