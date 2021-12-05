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
int     ft_atoi(char *nptr);
int	    ft_itoa_count(int n);
void	ft_itoa_u(unsigned int n, int *count);
int	    ft_itoa_u_count(unsigned int n);
void	ft_putstr(char *s, int *count);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
void	ft_putchar(char c, int *count);
void	hex_div(unsigned long int s, int *count, int islower);
int     hex_div_count(unsigned long int s, int islower);
void	put_adress(unsigned long int s, int *count);
void	conversions(const char *message, va_list arguments, int *count, int i);
void	conversions_bonus(const char *message, va_list arguments, int *count, int *i);
void    plus_flag(va_list arguments, int *count, int *i);
void	minus_flag(const char *message, va_list arguments, int *count, int *i);
void	zero_flag(const char *message, va_list arguments, int *count, int *i);
void	sharp_flag(const char *message, va_list arguments, int *count, int *i);
void	space_flag(const char *message, va_list arguments, int *count, int *i);
void	dot_flag(const char *message, va_list arguments, int *count, int *i);

#endif