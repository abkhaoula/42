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

typedef struct s_C
{
	int		*x;
	int		*y;
	int		count;
	int		motion;
	int		loop;
}	t_C;

typedef struct s_D
{
	int		*x;
	int		*y;
	int		count;
	int		motion;
	int		loop;
}	t_D;

typedef struct s_mlx_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		*hw;
	char	**map;
	int		*pos;
	t_D		danger;
	t_C		coins;
}	t_mlx_win;

typedef struct s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}	t_rect;

int		*initial(int fd, int *r, char *c, int *i);
int		*check_end_r(int i, int *hw);
int		re_intitial(int *i, int *r, int fd, char *c);
int		check_size_i(int *i, int *hw);
int		*map_dim(int fd);
int		render_errors(int p, int e, int c);
void	update_pce(char c, int **pce);
int		parse_map(int fd, int *hw);
int		render_rect(t_mlx_win *mw, t_rect rect);
int		render_map(t_mlx_win *mw);
void	map_to_tab(int fd, t_mlx_win *mw);
void	render_count(t_mlx_win *mw, int count);
int		exit_fail(t_mlx_win *mw, int x, int y);
int		exit_success(t_mlx_win *mw);
int		handle_input_button(int keysym, t_mlx_win *mw);
char	*ft_itoa(int n);
void	dpos_init(t_mlx_win	*mw);
int		animate_danger(t_mlx_win *mw);
void	cpos_init(t_mlx_win	*mw);
int		animate_coin(t_mlx_win *mw);
int		animate(t_mlx_win *mw);
char	*ft_strjoin(char const *s1, char const *s2);

#endif