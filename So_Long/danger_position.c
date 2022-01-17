/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   danger_position.c                                  :+:      :+:    :+:   */
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

int	count_d(t_mlx_win	*mw)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (i < mw->hw[1])
	{
		j = 0;
		while (j < mw->hw[0])
		{
			if (mw->map[i][j] == 'D')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	dpos_init(t_mlx_win	*mw)
{
	int	i;
	int	j;
	int	count;

	mw->danger.count = count_d(mw);
	mw->danger.x = malloc(mw->danger.count * sizeof(int));
	mw->danger.y = malloc(mw->danger.count * sizeof(int));
	i = 0;
	count = 0;
	while (i < mw->hw[1])
	{
		j = 0;
		while (j < mw->hw[0])
		{
			if (mw->map[i][j] == 'D')
			{
				mw->danger.x[count] = i * 50;
				mw->danger.y[count] = j * 50;
				count++;
			}
			j++;
		}
		i++;
	}
	mw->danger.loop = 0;
}

char	*pic_name(int motion)
{
	if (motion == 0)
		return ("./img/D2.xpm");
	else if (motion == 1)
		return ("./img/D3.xpm");
	else if (motion == 2)
		return ("./img/D4.xpm");
	else if (motion == 3)
		return ("./img/D5.xpm");
	else if (motion == 4)
		return ("./img/D6.xpm");
	else if (motion == 5)
		return ("./img/D7.xpm");
	else if (motion == 6)
		return ("./img/D8.xpm");
	else if (motion == 7)
		return ("./img/D9.xpm");
	else if (motion == 8)
		return ("./img/D10.xpm");
	else if (motion == 9)
		return ("./img/D11.xpm");
	else if (motion == 10)
		return ("./img/D12.xpm");
	else
		return ("./img/D1.xpm");
}

int	animate_danger(t_mlx_win *mw)
{
	char	*pic;
	int		i;
	void	*img;

	if (mw->danger.loop < 10000)
	{
		mw->danger.loop++;
		return (0);
	}
	mw->danger.loop = 0;
	pic = pic_name(mw->danger.motion);
	mw->danger.motion = (mw->danger.motion + 1) % 12;
	img = mlx_xpm_file_to_image(mw->mlx_ptr, pic,
			&(int){50}, &(int){50});
	i = 0;
	while (i < mw->danger.count)
	{
		mlx_put_image_to_window (mw->mlx_ptr, mw->win_ptr, img,
			mw->danger.y[i], mw->danger.x[i]);
		i++;
	}
	return (0);
}
