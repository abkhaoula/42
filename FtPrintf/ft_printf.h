/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:28:00 by kabdenou          #+#    #+#             */
/*   Updated: 2021/12/30 16:28:00 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

int		ft_printf(const char *message, ...);
void	ft_itoa(int n, int *count);
void	ft_itoa_u(unsigned int n, int *count);
void	ft_putstr(char *s, int *count);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
void	ft_putchar(char c, int *count);
void	hex_div(unsigned long int s, int *count, int islower);
void	put_adress(unsigned long int s, int *count);

#endif