/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dim.c                                          :+:      :+:    :+:   */
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

static int	*compute_map_dim(int fd, int **hw)
{
	int		i;
	char	c;
	int		r;

	(*hw) = initial(fd, &r, &c, &i);
	while (r || (c == '\n'))
	{
		while ((i <= (*hw)[0]))
		{
			if ((c == '\n') && (i != (*hw)[0]))
				return (NULL);
			else if (c == '\n')
				(*hw)[1] = (*hw)[1] + re_intitial(&i, &r, fd, &c);
			else if (!r)
				return (check_end_r(i, (*hw)));
			else
			{
				r = read(fd, &c, 1);
				if (check_size_i(&i, (*hw)))
					return (NULL);
			}
		}
		(*hw)[1]++;
	}
	return (*hw);
}

int	*map_dim(int fd)
{
	int		*hw;

	hw = compute_map_dim(fd, &hw);
	if (!hw)
	{
		printf("\033[0;31m YOUR MAP IS NOT RECTANGULAR !!! \n\e[0m");
		return (NULL);
	}
	return (hw);
}
