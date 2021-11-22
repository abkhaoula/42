/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:28:00 by kabdenou          #+#    #+#             */
/*   Updated: 2021/11/12 16:28:00 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	*move(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src < dest)
	{
		while (i < n)
		{
			dest[n - 1 - i] = src[n - 1 - i];
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*string_dest;
	const char	*string_src;

	if ((!dest) && (!src))
		return (NULL);
	string_dest = dest;
	string_src = src;
	return (move(string_dest, string_src, n));
}
