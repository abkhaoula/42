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

int	*read_stack(int argc, char *argv[])
{
	int	i;
	int	j;
	int	*stack;

	i = 0;
	stack = malloc((argc + 1) * sizeof(int));
	while ((stack) && (i < (argc - 1)))
	{
		j = 0;
		while (j < (int)ft_strlen(argv[i + 1]))
		{
			if (((j != 0) || argv[i + 1][j] != '-')
				&& ((argv[i + 1][j] < '0') || (argv[i + 1][j] > '9')))
			{
				printf("Error\n");
				free(stack);
				return (NULL);
			}
			j++;
		}
		stack[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (stack);
}

int	*read_check_stack(int argc, char *argv[])
{
	int	*stack;
	int	i;
	int	j;

	if (argc <= 1)
	{
		printf("Error\n");
		return (NULL);
	}
	stack = read_stack(argc, argv);
	i = -1;
	while ((stack) && (i < (argc - 3) && (2 + i++)))
	{
		j = i;
		while ((j < (argc - 2))  && (1 + j++))
		{
			if (stack[i] == stack[j])
			{
				printf("Error\n");
				free(stack);
				return (NULL);
			}
		}
	}
	return (stack);
}

int	main(int argc, char *argv[])
{
	int	*a;

	a = read_check_stack(argc, argv);
	if (!a)
		return (0);
	return (a[0]);
}
