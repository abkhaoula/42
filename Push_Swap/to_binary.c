/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_binary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:28:00 by kabdenou          #+#    #+#             */
/*   Updated: 2021/12/12 16:28:00 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdlib.h>

static void	tobinary(int a, int **a_stack)
{
	int	i;

	i = 0;
	while (a / 2)
	{
		(*a_stack)[i] = a % 2;
		a = a / 2;
		i++;
	}
	if (a % 2)
		(*a_stack)[i++] = a % 2;
	while (i < 32)
	{
		(*a_stack)[i] = -1;
		i++;
	}
}

int	**itob(int *a, int argc)
{
	int	**a_stack;
	int	i;

	i = 0;
	a_stack = malloc((argc - 1) * sizeof(int *));
	while ((a_stack) && (i < argc - 1))
	{
		a_stack[i] = malloc(32 * sizeof(int));
		if (!a_stack[i])
		{
			free(a_stack);
			return (NULL);
		}
		tobinary(a[i], &a_stack[i]);
		i++;
	}
	return (a_stack);
}
