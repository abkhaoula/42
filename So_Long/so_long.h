/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:28:00 by kabdenou          #+#    #+#             */
/*   Updated: 2022/01/07 16:28:00 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>

typedef struct s_mlx_win
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx_win;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

int		*initial(int fd, int *r, char *c, int *i);
int		*check_end_r(int i, int *hw);
void	re_intitial(int *i, int *r, int fd, char *c);
int		check_size_i(int *i, int *hw);
int		*map_dim(int fd);

#endif