/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:28:00 by kabdenou          #+#    #+#             */
/*   Updated: 2021/03/23 16:28:00 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "client.h"

void	stob_sig(int pid, char *message)
{
	int	i;
	int	j;

	i = 0;
	while (message[i])
	{
		j = 7;
		while (j > -1)
		{
			if (message[i] & (1 << j))
			{
				kill(pid, SIGUSR1);
				usleep(0.5);
			}
			else
			{
				kill(pid, SIGUSR2);
				usleep(0.5);
			}
			j--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	message = argv[2];
	stob_sig(pid, message);
}
