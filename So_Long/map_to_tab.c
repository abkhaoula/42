/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_tab.c                                       :+:      :+:    :+:   */
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

char	**map_to_tab(int fd, int *hw)
{
	int		i;
	int		j;
	char	c;
	char	**map;

	map = malloc(hw[1] * sizeof(char *));
	i = 0;
	while (i < hw[1])
	{
		map[i] = malloc(hw[0] * sizeof(char));
		j = 0;
		while (j < hw[0])
		{
			read(fd, &c, 1);
			map[i][j] = c;
			j++;
		}
		read(fd, &c, 1);
		i++;
	}
	return (map);
}
