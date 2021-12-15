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

long		ft_atoi(const char *nptr);
size_t		ft_strlen(const char *s);
long int	*read_check_stack(int argc, char *argv[]);
int			is_sorted(long int *a, int argc);
void		translate(long int *a[], int argc);
int			**itob(long int *a, int argc);
void		sab(int ***stack, int argc);
void		pab(int ***stack1, int ***stack2, int argc);
void		rab(int ***stack, int argc);
void		rrab(int ***stack, int argc);

#endif