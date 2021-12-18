/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_opps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:28:00 by kabdenou          #+#    #+#             */
/*   Updated: 2021/12/12 16:28:00 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdlib.h>

static void	copy(int **stack1, int **stack2)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		(*stack2)[i] = (*stack1)[i];
		i++;
	}
}

void	sab(int ***stack, int argc)
{
	int	*tmp;

	tmp = malloc(32 * sizeof(int));
	if (!tmp)
		return ;
	if (argc >= 3)
	{
		copy(&(*stack)[0], &tmp);
		copy(&(*stack)[1], &(*stack)[0]);
		copy(&tmp, &(*stack)[1]);
	}
	free(tmp);
}

void	pab(int ***stack1, int ***stack2, int argc)
{
	int	*tmp;
	int	i;

	tmp = malloc(32 * sizeof(int));
	if (!tmp)
		return ;
	if (argc >= 3)
	{
		copy(&(*stack2)[0], &tmp);
		i = 0;
		while (i < argc - 2)
		{
			copy(&(*stack2)[i + 1], &(*stack2)[i]);
			copy(&(*stack1)[argc - 3 - i], &(*stack1)[argc - 2 - i]);
			i++;
		}
		i = 0;
		while (i < 32)
		{
			(*stack2)[argc - 2][i] = -1;
			i++;
		}
		copy(&tmp, &(*stack1)[0]);
	}
	free(tmp);
}

void	rab(int ***stack, int argc, int end)
{
	int	*tmp;
	int	i;

	tmp = malloc(32 * sizeof(int));
	if (!tmp)
		return ;
	if (argc >= 2)
	{
		copy(&(*stack)[0], &tmp);
		i = 0;
		while (i < end)
		{
			copy(&(*stack)[i + 1], &(*stack)[i]);
			i++;
		}
		copy(&tmp, &(*stack)[end]);
	}
	free(tmp);
}

void	rrab(int ***stack, int argc)
{
	int	*tmp;
	int	i;

	tmp = malloc(32 * sizeof(int));
	if (!tmp)
		return ;
	if (argc >= 2)
	{
		copy(&(*stack)[argc - 2], &tmp);
		i = 0;
		while (i < argc - 2)
		{
			copy(&(*stack)[argc - 3 - i], &(*stack)[argc - 2 - i]);
			i++;
		}
		copy(&tmp, &(*stack)[0]);
	}
	free(tmp);
}
