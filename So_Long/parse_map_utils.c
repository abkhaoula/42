/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
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

int	render_errors(int p, int e, int c)
{
	if (p != 1)
	{
		printf("\033[0;31m YOU SHOULD HAVE ONE PLAYER !!! \n\e[0m");
		return (0);
	}
	if (e == 0)
	{
		printf("\033[0;31m YOU SHOULD HAVE AT LEAST ONE EXIT !!! \n\e[0m");
		return (0);
	}
	if (c == 0)
	{
		printf("\033[0;31m YOU SHOULD HAVE AT LEAST ONE COIN !!! \n\e[0m");
		return (0);
	}
	return (1);
}

void	update_pce(char c, int **pce)
{
	if (c == 'P')
		(*pce)[0]++;
	else if (c == 'C')
		(*pce)[1]++;
	else if (c == 'E')
		(*pce)[2]++;
}
