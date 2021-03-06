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

void	map_to_tab(int fd, t_mlx_win *mw)
{
	int		i;
	int		j;
	char	c;
	char	**map;

	map = malloc(mw->hw[1] * sizeof(char *));
	i = 0;
	while (i < mw->hw[1])
	{
		map[i] = malloc(mw->hw[0] * sizeof(char));
		j = 0;
		while (j < mw->hw[0])
		{
			read(fd, &c, 1);
			map[i][j] = c;
			j++;
		}
		read(fd, &c, 1);
		i++;
	}
	mw->map = map;
}
