/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:28:00 by kabdenou          #+#    #+#             */
/*   Updated: 2021/12/12 16:28:00 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	long int	*a;
	int			**a_stack;

	a = read_check_stack(argc, argv);
	if (!a)
		return (0);
	if (is_sorted(a, argc))
		return (1);
	translate(&a, argc);
	a_stack = itob(a, argc);
	free(a);
	if (!a_stack)
		return (0);
	printf("To be sorted\n");
	return (1);
}
