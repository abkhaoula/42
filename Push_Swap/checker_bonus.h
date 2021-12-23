/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:28:00 by kabdenou          #+#    #+#             */
/*   Updated: 2021/12/12 16:28:00 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdio.h>

int		*read_check_stack(int *argc, char *argv[]);
int		is_sorted(int *a, int argc);
void	sab(int **ab, int ab_count);
void	ss(int **a, int a_count, int **b, int b_count);
void	pab(int **a, int *a_count, int **b, int *b_count);
void	rab(int **ab, int ab_count);
void	rr(int **a, int a_count, int **b, int b_count);
void	rrab(int **ab, int ab_count);
void	rrr(int **a, int a_count, int **b, int b_count);

#endif