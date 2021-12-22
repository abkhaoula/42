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

int	main(int argc, char *argv[])
{
	int	*a;
	int	**a_stack;
	int	**b_stack;

	a = read_check_stack(&argc, argv);
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
