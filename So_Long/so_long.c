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
	if (! render_map(&mw))
		return (0);
	mlx_key_hook(mw.win_ptr, &handle_input_button, &mw);
	mlx_hook(mw.win_ptr, 17, 0, close_button, &mw);
	mlx_loop (mw.mlx_ptr);
	mlx_destroy_display(mw.mlx_ptr);
	free(mw.mlx_ptr);
}
