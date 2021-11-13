/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:28:00 by kabdenou          #+#    #+#             */
/*   Updated: 2021/11/12 16:28:00 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	int		j;
	char	*joint;

	len = ft_strlen(s1) + ft_strlen(s2);
	joint = malloc(sizeof(char) * (len + 1));
	if (!joint)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joint[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		joint[i + j] = s2[j];
		j++;
	}
	joint[i + j] = '\0';
	return (joint);
}
