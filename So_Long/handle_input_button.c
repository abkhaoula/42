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

void	handle_xk_up(t_mlx_win *mw)
{
	if (((mw->map[mw->pos[0] - 1][mw->pos[1]] != '1')
		&& (mw->map[mw->pos[0] - 1][mw->pos[1]] != 'E'))
		|| ((mw->map[mw->pos[0] - 1][mw->pos[1]] == 'E') && (!mw->coin)))
	{
		if (mw->map[mw->pos[0] - 1][mw->pos[1]] == 'C')
			mw->coin --;
		render_rect(mw, (t_rect){(mw->pos[1] * 50),
			(mw->pos[0] * 50), 50, 50, 0x000000});
		mw->map[mw->pos[0]][mw->pos[1]] = '0';
		mw->pos[0]--;
		if (mw->map[mw->pos[0]][mw->pos[1]] == 'E')
		{
			mlx_destroy_window(mw->mlx_ptr, mw->win_ptr);
			mlx_loop_end(mw->mlx_ptr);
			return ;
		}
		mw->map[mw->pos[0]][mw->pos[1]] = 'P';
		render_rect(mw, (t_rect){(mw->pos[1] * 50),
			(mw->pos[0] * 50), 50, 50, 0x38686A});
	}
}

void	handle_xk_right(t_mlx_win *mw)
{
	if (((mw->map[mw->pos[0]][mw->pos[1] + 1] != '1')
		&& (mw->map[mw->pos[0]][mw->pos[1] + 1] != 'E'))
		|| ((mw->map[mw->pos[0]][mw->pos[1] + 1] == 'E') && (!mw->coin)))
	{
		if (mw->map[mw->pos[0]][mw->pos[1] + 1] == 'C')
			mw->coin --;
		render_rect(mw, (t_rect){(mw->pos[1] * 50),
			(mw->pos[0] * 50), 50, 50, 0x000000});
		mw->map[mw->pos[0]][mw->pos[1]] = '0';
		mw->pos[1]++;
		if (mw->map[mw->pos[0]][mw->pos[1]] == 'E')
		{
			mlx_destroy_window(mw->mlx_ptr, mw->win_ptr);
			mlx_loop_end(mw->mlx_ptr);
			return ;
		}
		mw->map[mw->pos[0]][mw->pos[1]] = 'P';
		render_rect(mw, (t_rect){(mw->pos[1] * 50),
			(mw->pos[0] * 50), 50, 50, 0x38686A});
	}
}

void	handle_xk_down(t_mlx_win *mw)
{
	if (((mw->map[mw->pos[0] + 1][mw->pos[1]] != '1')
		&& (mw->map[mw->pos[0] + 1][mw->pos[1]] != 'E'))
		|| ((mw->map[mw->pos[0] + 1][mw->pos[1]] == 'E') && (!mw->coin)))
	{
		if (mw->map[mw->pos[0] + 1][mw->pos[1]] == 'C')
			mw->coin --;
		render_rect(mw, (t_rect){(mw->pos[1] * 50),
			(mw->pos[0] * 50), 50, 50, 0x000000});
		mw->map[mw->pos[0]][mw->pos[1]] = '0';
		mw->pos[0]++;
		if (mw->map[mw->pos[0]][mw->pos[1]] == 'E')
		{
			mlx_destroy_window(mw->mlx_ptr, mw->win_ptr);
			mlx_loop_end(mw->mlx_ptr);
			return ;
		}
		mw->map[mw->pos[0]][mw->pos[1]] = 'P';
		render_rect(mw, (t_rect){(mw->pos[1] * 50),
			(mw->pos[0] * 50), 50, 50, 0x38686A});
	}
}

void	handle_xk_left(t_mlx_win *mw)
{
	if (((mw->map[mw->pos[0]][mw->pos[1] - 1] != '1')
		&& (mw->map[mw->pos[0]][mw->pos[1] - 1] != 'E'))
		|| ((mw->map[mw->pos[0]][mw->pos[1] - 1] == 'E') && (!mw->coin)))
	{
		if (mw->map[mw->pos[0]][mw->pos[1] - 1] == 'C')
			mw->coin --;
		render_rect(mw, (t_rect){(mw->pos[1] * 50),
			(mw->pos[0] * 50), 50, 50, 0x000000});
		mw->map[mw->pos[0]][mw->pos[1]] = '0';
		mw->pos[1]--;
		if (mw->map[mw->pos[0]][mw->pos[1]] == 'E')
		{
			mlx_destroy_window(mw->mlx_ptr, mw->win_ptr);
			mlx_loop_end(mw->mlx_ptr);
			return ;
		}
		mw->map[mw->pos[0]][mw->pos[1]] = 'P';
		render_rect(mw, (t_rect){(mw->pos[1] * 50),
			(mw->pos[0] * 50), 50, 50, 0x38686A});
	}
}

int	handle_input_button(int keysym, t_mlx_win *mw)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(mw->mlx_ptr, mw->win_ptr);
		mlx_loop_end(mw->mlx_ptr);
		return (0);
	}
	else if (keysym == XK_Up)
		handle_xk_up(mw);
	else if (keysym == XK_Right)
		handle_xk_right(mw);
	else if (keysym == XK_Down)
		handle_xk_down(mw);
	else if (keysym == XK_Left)
		handle_xk_left(mw);
	return (0);
}
