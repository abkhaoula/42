/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack.c                                      :+:      :+:    :+:   */
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

static int	in_int_range(char *argv[], int i)
{
	if (((int)ft_strlen(argv[i + 1]) > (10 + ((argv[i + 1][0] == '-')
				|| (argv[i + 1][0] == '+'))))
				|| (ft_atoi(argv[i + 1]) < -2147483648)
				|| (ft_atoi(argv[i + 1]) > 2147483647))
		return (0);
	return (1);
}

static int	*read_stack(int argc, char *argv[])
{
	int	i;
	int	j;
	int	*stack;

	i = 0;
	stack = malloc((argc - 1) * sizeof(int));
	while ((stack) && (i < (argc - 1)))
	{
		j = 0;
		while (j < (int)ft_strlen(argv[i + 1]))
		{
			if ((!in_int_range(argv, i)) || (((j != 0) || argv[i + 1][j] != '-')
				&& ((argv[i + 1][j] < '0') || (argv[i + 1][j] > '9'))))
			{
				write(1, "Error\n", 6);
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
		write(1, "Error\n", 6);
		return (NULL);
	}
	stack = read_stack(argc, argv);
	i = -1;
	while ((stack) && (i < (argc - 3) && (2 + i++)))
	{
		j = i;
		while ((j < (argc - 2)) && (1 + j++))
		{
			if (stack[i] == stack[j])
			{
				write(1, "Error\n", 6);
				free(stack);
				return (NULL);
			}
		}
	}
	return (stack);
}
