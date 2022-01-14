/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input_button_utils.c                        :+:      :+:    :+:   */
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

void	render_count(t_mlx_win *mw, int count)
{
	void	*img;

	img = mlx_xpm_file_to_image(mw->mlx_ptr, "./img/1.xpm",
			&(int){50}, &(int){50});
	mlx_put_image_to_window (mw->mlx_ptr, mw->win_ptr, img, 0, 0);
	mlx_string_put(mw->mlx_ptr, mw->win_ptr, 30, 20, 0x000000, ft_itoa(count));
}
