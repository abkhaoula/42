/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
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

int	is_same(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int		*a;
	int		a_count;
	int		b_count;
	int		*b;
	char	*instruction;
	int		i;
	int		r;

	if (argc == 1)
		return (0);
	a = read_check_stack(&argc, argv);
	a_count = argc - 1;
	b = malloc((argc - 1) * sizeof(int));
	b_count = 0;
	if (!a)
		return (0);
	instruction = malloc(5 * sizeof(char));
	instruction[0] = 'k';
	i = 0;
	r = 1;
	while (r > 0)
	{
		if (is_same(instruction, "sa\n"))
			sab(&a, a_count);
		else if (is_same(instruction, "sb\n"))
			sab(&b, b_count);
		else if (is_same(instruction, "ss\n"))
			ss(&a, a_count, &b, b_count);
		else if (is_same(instruction, "pa\n"))
			pab(&a, &a_count, &b, &b_count);
		else if (is_same(instruction, "pb\n"))
			pab(&b, &b_count, &a, &a_count);
		else if (is_same(instruction, "ra\n"))
			rab(&a, a_count);
		else if (is_same(instruction, "rb\n"))
			rab(&b, b_count);
		else if (is_same(instruction, "rr\n"))
			rr(&a, a_count, &b, b_count);
		else if (is_same(instruction, "rra\n"))
			rrab(&a, a_count);
		else if (is_same(instruction, "rrb\n"))
			rrab(&b, b_count);
		else if (is_same(instruction, "rrr\n"))
			rrr(&a, a_count, &b, b_count);
		else
			write(1, "Error\n", 6);
		i = 0;
		while ((i < 5))
		{
			r = read(0, &(instruction[i]), 1);
			if (instruction[i] == '\n')
				break ;
			if (r == 0 && i == 0)
				break ;
			else if (r == 0)
			{
				write(1, "Error\n", 6);
				return ;
			}
			i++;
		}
	}
	if (is_sorted(a, argc) && (a_count == argc - 1))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
