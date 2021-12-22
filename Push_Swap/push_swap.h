/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:28:00 by kabdenou          #+#    #+#             */
/*   Updated: 2021/12/12 16:28:00 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

long	ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);
int		*read_check_stack(int argc, char *argv[]);
int		is_sorted(int *a, int argc);
void	simplify(int *a[], int argc);
int		**itob(int *a, int argc);
void	sab(int ***stack, int argc);
void	pab(int ***stack1, int ***stack2, int argc);
void	rab(int ***stack, int argc, int end);
void	rrab(int ***stack, int argc);
void	small_sort(int *a, int argc);
void	big_sort(int ***a_stack, int ***b_stack, int argc);
int		isnt_end(int **stack, int j, int argc);
int		check_rest_pb(int **a_stack, int argc, int i, int j);
void	pb_in_sort(int ***a_stack, int ***b_stack, int argc, int *count);
void	ra_in_sort(int ***a_stack, int argc, int count);
void	pa_in_sort(int ***a_stack, int ***b_stack, int argc, int count);

#endif