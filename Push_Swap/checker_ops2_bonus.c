/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:28:00 by kabdenou          #+#    #+#             */
/*   Updated: 2021/12/12 16:28:00 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker_bonus.h"
#include <stdlib.h>
#include <unistd.h>

void	_pab(int **a, int *a_count, int **b, int *b_count)
{
	int	i;

	if ((*b_count) == 0)
		return ;
	i = (*a_count) - 1;
	while (i >= 0)
	{
		(*a)[i + 1] = (*a)[i];
		i--;
	}
	(*a)[0] = (*b)[0];
	(*a_count)++;
	i = 0;
	(*b_count)--;
	while (i < (*b_count))
	{
		(*b)[i] = (*b)[i + 1];
		i++;
	}
}

void	_rrab(int **ab, int ab_count)
{
	int	tmp;
	int	i;

	tmp = (*ab)[ab_count - 1];
	i = ab_count - 1;
	while (i > 0)
	{
		(*ab)[i] = (*ab)[i - 1];
		i--;
	}
	(*ab)[0] = tmp;
}

void	_rrr(int **a, int a_count, int **b, int b_count)
{
	_rrab(a, a_count);
	_rrab(b, b_count);
}
