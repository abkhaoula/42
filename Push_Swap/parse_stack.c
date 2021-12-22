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

static int	*read_stack(int *argc, char *argv[])
{
	if ((*argc) == 2)
		return (read_stack1(argc, argv));
	else
		return (read_stack2((*argc), argv));
}

int	*read_check_stack(int *argc, char *argv[])
{
	int	*stack;
	int	i;
	int	j;

	if ((*argc) <= 1)
	{
		write(1, "Error\n", 6);
		return (NULL);
	}
	stack = read_stack(argc, argv);
	i = -1;
	while ((stack) && (i < ((*argc) - 3) && (2 + i++)))
	{
		j = i;
		while ((j < ((*argc) - 2)) && (1 + j++))
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
