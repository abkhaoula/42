/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:28:00 by kabdenou          #+#    #+#             */
/*   Updated: 2021/11/23 16:28:00 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*ft_substr(char *s, int start, int len);
int		ft_strlen(char *s);
int		ft_is_new_line(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_line(char *rest);
char	*read_file(int fd, char *rest);
char	*get_next_line(int fd);
char	*get_leftover(char *leftover);

#endif
