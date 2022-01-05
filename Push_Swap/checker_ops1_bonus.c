/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops1_bonus.c                               :+:      :+:    :+:   */
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

void	_sab(int **ab, int ab_count)
{
	int	tmp;

	if (ab_count < 2)
		return ;
	tmp = (*ab)[0];
	(*ab)[0] = (*ab)[1];
	(*ab)[1] = tmp;
}

void	_ss(int **a, int a_count, int **b, int b_count)
{
	_sab(a, a_count);
	_sab(b, b_count);
}

void	_rab(int **ab, int ab_count)
{
	int	tmp;
	int	i;

	tmp = (*ab)[0];
	i = 0;
	while (i < ab_count - 1)
	{
		(*ab)[i] = (*ab)[i + 1];
		i++;
	}
	(*ab)[ab_count - 1] = tmp;
}

void	_rr(int **a, int a_count, int **b, int b_count)
{
	_rab(a, a_count);
	_rab(b, b_count);
}
