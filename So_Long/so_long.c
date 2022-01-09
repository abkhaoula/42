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
#include "mlx.h"
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_mlx_win
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx_win;

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
	mlx_key_hook(mw.win_ptr, &handle_input, &mw);
	mlx_hook(mw.win_ptr, 17, 0, close_button, &mw);
	mlx_loop (mw.mlx_ptr);
	mlx_destroy_display(mw.mlx_ptr);
	free(mw.mlx_ptr);
}
