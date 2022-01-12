/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dim_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:28:00 by kabdenou          #+#    #+#             */
/*   Updated: 2022/01/07 16:28:00 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include "mlx.h"
#include <X11/keysym.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	*initial(int fd, int *r, char *c, int *i)
{
	int	*hw;

	hw = malloc(2 * sizeof(int));
	hw[0] = 0;
	*r = read(fd, c, 1);
	while ((*r) & ((*c) != '\n'))
	{
		hw[0]++;
		*r = read(fd, c, 1);
	}
	hw[1] = 1;
	*r = read(fd, c, 1);
	*i = 0;
	return (hw);
}

int	*check_end_r(int i, int *hw)
{
	if (i != hw[0])
		return (NULL);
	else
	{
		hw[1]++;
		return (hw);
	}
}

void	re_intitial(int *i, int *r, int fd, char *c)
{
	*i = 0;
	*r = read(fd, c, 1);
}

int	check_size_i(int *i, int *hw)
{
	(*i)++;
	if ((*i) > hw[0])
		return (1);
	return (0);
}
