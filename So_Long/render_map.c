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

void	render_elem(t_mlx_win *mw, int *xy, char c, int **pos)
{
	void	*img;

	if (c == 'P')
	{
		(*pos) = malloc(2 * sizeof(int));
		(*pos)[0] = xy[1] / 50;
		(*pos)[1] = xy[0] / 50;
		mw->p_img = mlx_xpm_file_to_image(mw->mlx_ptr, "./img/PL.xpm",
				&(int){50}, &(int){50});
		img = mw->p_img;
	}
	else if (c == '1')
		img = mlx_xpm_file_to_image(mw->mlx_ptr, "./img/1.xpm",
				&(int){50}, &(int){50});
	else if (c == 'C')
		img = mlx_xpm_file_to_image(mw->mlx_ptr, "./img/C.xpm",
				&(int){50}, &(int){50});
	else if (c == 'E')
		img = mlx_xpm_file_to_image(mw->mlx_ptr, "./img/E.xpm",
				&(int){50}, &(int){50});
	else if (c == 'D')
		img = mlx_xpm_file_to_image(mw->mlx_ptr, "./img/D1.xpm",
				&(int){50}, &(int){50});
	if (c != '0')
		mlx_put_image_to_window (mw->mlx_ptr, mw->win_ptr, img, xy[0], xy[1]);
}

void	render_map_rects(t_mlx_win *mw, int fd)
{
	int		r;
	char	c;
	int		x;
	int		y;
	int		*pos;

	x = 0;
	y = 0;
	r = read(fd, &c, 1);
	while (r)
	{
		if ((c == '1') || (c == '0') || (c == 'E') || (c == 'P')
			|| (c == 'C') || (c == 'D'))
		{
			render_elem(mw, (int []){x, y}, c, &pos);
			x = x + 50;
		}
		else if (c == '\n')
		{
			x = 0;
			y = y + 50;
		}
		r = read(fd, &c, 1);
	}
	mw->pos = pos;
}

int	render_map(t_mlx_win *mw)
{
	int	fd;

	fd = open("maps/map.ber", O_RDONLY);
	mw->hw = map_dim(fd);
	if (!mw->hw)
		return (0);
	close(fd);
	fd = open("maps/map.ber", O_RDONLY);
	mw->coins.count = parse_map(fd, mw->hw);
	if (!mw->coins.count)
		return (0);
	mw->win_ptr = mlx_new_window(mw->mlx_ptr, (50 * mw->hw[0]),
			(50 * mw->hw[1]), "So Long");
	if (mw->win_ptr == NULL)
	{
		free(mw->win_ptr);
		return (0);
	}
	close(fd);
	fd = open("maps/map.ber", O_RDONLY);
	render_map_rects(mw, fd);
	close(fd);
	fd = open("maps/map.ber", O_RDONLY);
	map_to_tab(fd, mw);
	return (1);
}
