/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
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

int	parse_edge_line(int fd, int *hw)
{
	int		i;
	char	c;

	i = 0;
	while (i < hw[0])
	{
		read(fd, &c, 1);
		if (c != '1')
		{
			printf("\033[0;31m YOUR EDGES ARE NOT WELL DONE !!! \n\e[0m");
			return (0);
		}
		i++;
	}
	return (1);
}

int	parse_line(int fd, int *hw, int **pce)
{
	int		j;
	char	c;

	j = 0;
	while (j < hw[0])
	{
		read(fd, &c, 1);
		if (((j == 0) || (j == hw[0] - 1)) && (c != '1'))
		{
			printf("\033[0;31m YOUR EDGES ARE NOT WELL DONE !!! \n\e[0m");
			return (0);
		}
		else if ((c == 'P') || (c == 'C') || (c == 'E'))
			update_pce(c, pce);
		else if (c != '0' && c != '1')
		{
			printf("\033[0;31m YOU HAVE A WRONG ENTRY !!! \n\e[0m");
			return (0);
		}
		j++;
	}
	return (1);
}

int	parse_all_lines(int fd, int *hw)
{
	int		i;
	int		*pce;
	char	c;

	i = 0;
	pce = malloc(3 * sizeof(int));
	pce[0] = 0;
	pce[1] = 0;
	pce[2] = 0;
	while (i < hw[1] - 2)
	{
		if (!parse_line(fd, hw, &pce))
			return (0);
		read(fd, &c, 1);
		i++;
	}
	if (!render_errors(pce[0], pce[1], pce[2]))
		return (0);
	return (pce[1]);
}

int	parse_map(int fd, int *hw)
{
	char	c;
	int		coin;

	if (!parse_edge_line(fd, hw))
		return (0);
	read(fd, &c, 1);
	coin = parse_all_lines(fd, hw);
	if (!coin)
		return (0);
	if (!parse_edge_line(fd, hw))
		return (0);
	return (coin);
}
