/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:28:00 by kabdenou          #+#    #+#             */
/*   Updated: 2021/12/12 16:28:00 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "checker_bonus.h"
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

int	*read_stack2(int argc, char *argv[])
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

int	find_argc(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[1][i] == ' ')
		i++;
	while (argv[1][i])
	{
		if (argv[1][i] && argv[1][i] == ' ')
		{
			j++;
			while (argv[1][i] && (argv[1][i] == ' '))
				i++;
		}
		else if ((argv[1][i]) && (((argv[1][i] < '0') || (argv[1][i] > '9'))
				&& ((argv[1][i] != '-') || (argv[1][i - 1] != ' '))))
			return (-1);
		else
			i++;
	}
	if (argv[1][i - 1] != ' ')
		j++;
	return (j + 1);
}

int	*read_stack1(int *argc, char *argv[])
{
	int	i;
	int	j;
	int	*stack;

	(*argc) = find_argc(argv);
	if ((*argc) < 0)
	{
		write(1, "Error\n", 6);
		return (NULL);
	}
	stack = malloc(((*argc) - 1) * sizeof(int));
	j = 0;
	i = 0;
	while ((stack) && (i < ((*argc) - 1)))
	{
		stack[i] = ft_atoi(&argv[1][j]);
		while (argv[1][j] && argv[1][j] != ' ')
			j++;
		while (argv[1][j] && argv[1][j] == ' ')
			j++;
		i++;
	}
	return (stack);
}
