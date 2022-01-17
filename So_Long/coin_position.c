/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_position.c                                    :+:      :+:    :+:   */
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

void	cpos_init(t_mlx_win	*mw)
{
	int	i;
	int	j;
	int	count;

	mw->coins.x = malloc(mw->coins.count * sizeof(int));
	mw->coins.y = malloc(mw->coins.count * sizeof(int));
	i = 0;
	count = 0;
	while (i < mw->hw[1])
	{
		j = 0;
		while (j < mw->hw[0])
		{
			if (mw->map[i][j] == 'C')
			{
				mw->coins.x[count] = i * 50;
				mw->coins.y[count] = j * 50;
				count++;
			}
			j++;
		}
		i++;
	}
	mw->coins.loop = 0;
}

char	*c_pic_name(int motion)
{
	char	*path;

	path = ft_strjoin("./img/C", ft_itoa((((motion + 1) % 19) + 1)));
	path = ft_strjoin(path, ".xpm");
	return (path);
}

int	animate_coin(t_mlx_win *mw)
{
	char	*pic;
	int		i;
	void	*img;

	if (mw->coins.loop < 10000)
	{
		mw->coins.loop++;
		return (0);
	}
	mw->coins.loop = 0;
	pic = c_pic_name(mw->coins.motion);
	mw->coins.motion = (mw->coins.motion + 1) % 20;
	img = mlx_xpm_file_to_image(mw->mlx_ptr, pic,
			&(int){50}, &(int){50});
	i = 0;
	while (i < mw->coins.count)
	{
		mlx_put_image_to_window (mw->mlx_ptr, mw->win_ptr,
			img, mw->coins.y[i], mw->coins.x[i]);
		i++;
	}
	return (0);
}
