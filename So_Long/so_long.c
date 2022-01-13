/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
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

int	handle_input(int keysym, t_mlx_win *mw)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(mw->mlx_ptr, mw->win_ptr);
		mlx_loop_end(mw->mlx_ptr);
	}
	return (0);
}

int	close_button(t_mlx_win *mw)
{
	mlx_destroy_window(mw->mlx_ptr, mw->win_ptr);
	mlx_loop_end(mw->mlx_ptr);
	return (0);
}

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

int	render_map(t_mlx_win *mw)
{
	int	fd;
	int	*hw;

	fd = open("maps/simple.ber", O_RDONLY);
	hw = map_dim(fd);
	if (!hw)
	{
		printf("\033[0;31m YOUR MAP IS NOT RECTANGULAR !!! \n\e[0m");
		mlx_destroy_window(mw->mlx_ptr, mw->win_ptr);
		mlx_loop_end(mw->mlx_ptr);
		return (0);
	}
	close(fd);
	fd = open("maps/simple.ber", O_RDONLY);
	if (parse_map(fd, hw))
	{
		printf("YESS\n");
	}
	render_rect(mw, (t_rect){0, 0, 100, 100, 0xFF0000});
	return (0);
}

int	main(void)
{
	t_mlx_win	mw;

	mw.mlx_ptr = mlx_init();
	if (mw.mlx_ptr == NULL)
		return (0);
	mw.win_ptr = mlx_new_window(mw.mlx_ptr, 640, 360, "So Long");
	if (mw.win_ptr == NULL)
	{
		free(mw.win_ptr);
		return (0);
	}
	render_map(&mw);
	mlx_key_hook(mw.win_ptr, &handle_input, &mw);
	mlx_hook(mw.win_ptr, 17, 0, close_button, &mw);
	mlx_loop (mw.mlx_ptr);
	mlx_destroy_display(mw.mlx_ptr);
	free(mw.mlx_ptr);
}
