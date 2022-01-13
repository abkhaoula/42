/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
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

int	render_rect(t_mlx_win *mw, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			mlx_pixel_put(mw->mlx_ptr, mw->win_ptr, j++, i, rect.color);
		++i;
	}
	return (0);
}

int	color_elem(char c, int **pos, int x, int y)
{
	int	color;

	if (c == '1')
		color = 0xF9EAE1;
	else if (c == '0')
		color = 0x000000;
	else if (c == 'E')
		color = 0xAA998F;
	else if (c == 'P')
	{
		(*pos) = malloc(2 * sizeof(int));
		color = 0x38686A;
		(*pos)[0] = y / 50;
		(*pos)[1] = x / 50;
	}
	else if (c == 'C')
		color = 0xD98324;
	return (color);
}

int	*render_map_rects(t_mlx_win *mw, int fd)
{
	int		r;
	char	c;
	int		x;
	int		y;
	int		*pos;

	x = 0;
	y = 0;
	r = read(fd, &c, 1);
	pos = malloc(2 * sizeof(int));
	while (r)
	{
		if ((c == '1') || (c == '0') || (c == 'E') || (c == 'P') || (c == 'C'))
		{
			render_rect(mw, (t_rect){x, y, 50, 50, color_elem(c, &pos, x, y)});
			x = x + 50;
		}
		else if (c == '\n')
		{
			x = 0;
			y = y + 50;
		}
		r = read(fd, &c, 1);
	}
	return (pos);
}

int	render_map(t_mlx_win *mw)
{
	int	fd;

	fd = open("maps/simple.ber", O_RDONLY);
	mw->hw = map_dim(fd);
	if (!mw->hw)
		return (0);
	close(fd);
	fd = open("maps/simple.ber", O_RDONLY);
	mw->coin = parse_map(fd, mw->hw);
	if (!mw->coin)
		return (0);
	mw->win_ptr = mlx_new_window(mw->mlx_ptr, (50 * mw->hw[0]),
			(50 * mw->hw[1]), "So Long");
	if (mw->win_ptr == NULL)
	{
		free(mw->win_ptr);
		return (0);
	}
	close(fd);
	fd = open("maps/simple.ber", O_RDONLY);
	mw->pos = render_map_rects(mw, fd);
	close(fd);
	fd = open("maps/simple.ber", O_RDONLY);
	mw->map = map_to_tab(fd, mw->hw);
	return (1);
}
