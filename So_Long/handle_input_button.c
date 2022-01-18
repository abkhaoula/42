/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input_button.c                              :+:      :+:    :+:   */
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

void	handle_xk_up(t_mlx_win *mw, int *count)
{
	if (exit_fail(mw, mw->pos[0] - 1, mw->pos[1]))
		return ;
	if (((mw->map[mw->pos[0] - 1][mw->pos[1]] != '1')
		&& (mw->map[mw->pos[0] - 1][mw->pos[1]] != 'E'))
		|| ((mw->map[mw->pos[0] - 1][mw->pos[1]] == 'E') && (!mw->coins.count)))
	{
		if (mw->map[mw->pos[0] - 1][mw->pos[1]] == 'C')
			mw->coins.count --;
		render_rect(mw, (t_rect){(mw->pos[1] * 50),
			(mw->pos[0] * 50), 50, 50, 0x000000});
		mw->map[mw->pos[0]][mw->pos[1]] = '0';
		mw->pos[0]--;
		if (exit_success(mw))
			return ;
		mw->map[mw->pos[0]][mw->pos[1]] = 'P';
		mlx_put_image_to_window (mw->mlx_ptr, mw->win_ptr, mw->p_img,
			(mw->pos[1] * 50), (mw->pos[0] * 50));
		cpos_init(mw);
		(*count)++;
		render_count(mw, *count);
	}
}

void	handle_xk_right(t_mlx_win *mw, int *count)
{
	if (exit_fail(mw, mw->pos[0], mw->pos[1] + 1))
		return ;
	if (((mw->map[mw->pos[0]][mw->pos[1] + 1] != '1')
		&& (mw->map[mw->pos[0]][mw->pos[1] + 1] != 'E'))
		|| ((mw->map[mw->pos[0]][mw->pos[1] + 1] == 'E') && (!mw->coins.count)))
	{
		if (mw->map[mw->pos[0]][mw->pos[1] + 1] == 'C')
			mw->coins.count --;
		render_rect(mw, (t_rect){(mw->pos[1] * 50),
			(mw->pos[0] * 50), 50, 50, 0x000000});
		mw->map[mw->pos[0]][mw->pos[1]] = '0';
		mw->pos[1]++;
		if (exit_success(mw))
			return ;
		mw->map[mw->pos[0]][mw->pos[1]] = 'P';
		mlx_put_image_to_window (mw->mlx_ptr, mw->win_ptr, mw->p_img,
			(mw->pos[1] * 50), (mw->pos[0] * 50));
		cpos_init(mw);
		(*count)++;
		render_count(mw, *count);
	}
}

void	handle_xk_down(t_mlx_win *mw, int *count)
{
	if (exit_fail(mw, mw->pos[0] + 1, mw->pos[1]))
		return ;
	if (((mw->map[mw->pos[0] + 1][mw->pos[1]] != '1')
		&& (mw->map[mw->pos[0] + 1][mw->pos[1]] != 'E'))
		|| ((mw->map[mw->pos[0] + 1][mw->pos[1]] == 'E') && (!mw->coins.count)))
	{
		if (mw->map[mw->pos[0] + 1][mw->pos[1]] == 'C')
			mw->coins.count --;
		render_rect(mw, (t_rect){(mw->pos[1] * 50),
			(mw->pos[0] * 50), 50, 50, 0x000000});
		mw->map[mw->pos[0]][mw->pos[1]] = '0';
		mw->pos[0]++;
		if (exit_success(mw))
			return ;
		mw->map[mw->pos[0]][mw->pos[1]] = 'P';
		mlx_put_image_to_window (mw->mlx_ptr, mw->win_ptr, mw->p_img,
			(mw->pos[1] * 50), (mw->pos[0] * 50));
		cpos_init(mw);
		(*count)++;
		render_count(mw, *count);
	}
}

void	handle_xk_left(t_mlx_win *mw, int *count)
{
	if (exit_fail(mw, mw->pos[0], mw->pos[1] - 1))
		return ;
	if (((mw->map[mw->pos[0]][mw->pos[1] - 1] != '1')
		&& (mw->map[mw->pos[0]][mw->pos[1] - 1] != 'E'))
		|| ((mw->map[mw->pos[0]][mw->pos[1] - 1] == 'E') && (!mw->coins.count)))
	{
		if (mw->map[mw->pos[0]][mw->pos[1] - 1] == 'C')
			mw->coins.count --;
		render_rect(mw, (t_rect){(mw->pos[1] * 50),
			(mw->pos[0] * 50), 50, 50, 0x000000});
		mw->map[mw->pos[0]][mw->pos[1]] = '0';
		mw->pos[1]--;
		if (exit_success(mw))
			return ;
		mw->map[mw->pos[0]][mw->pos[1]] = 'P';
		mlx_put_image_to_window (mw->mlx_ptr, mw->win_ptr, mw->p_img,
			(mw->pos[1] * 50), (mw->pos[0] * 50));
		cpos_init(mw);
		(*count)++;
		render_count(mw, *count);
	}
}

int	handle_input_button(int keysym, t_mlx_win *mw)
{
	static int	count;

	if (keysym == XK_Escape)
	{
		mlx_destroy_window(mw->mlx_ptr, mw->win_ptr);
		mlx_loop_end(mw->mlx_ptr);
		return (0);
	}
	else if ((keysym == XK_Up) || (keysym == XK_w))
		handle_xk_up(mw, &count);
	else if ((keysym == XK_Right) || (keysym == XK_d))
	{
		mw->p_img = mlx_xpm_file_to_image(mw->mlx_ptr, "./img/PR.xpm",
				&(int){50}, &(int){50});
		handle_xk_right(mw, &count);
	}
	else if ((keysym == XK_Down) || (keysym == XK_s))
		handle_xk_down(mw, &count);
	else if ((keysym == XK_Left) || (keysym == XK_a))
	{
		mw->p_img = mlx_xpm_file_to_image(mw->mlx_ptr, "./img/PL.xpm",
				&(int){50}, &(int){50});
		handle_xk_left(mw, &count);
	}
	return (0);
}
