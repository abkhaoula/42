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
#include <stdlib.h>
#include "client.h"

void	handler(int signum)
{
	if (signum == SIGUSR1)
	{
		printf("received haha \n");
		exit(-1);
	}
}

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

void	itob_sig(int pid, int n)
{
	int i;

	i = 0;
	while(n)
	{
		if (n%2)
		{
			kill(pid, SIGUSR1);
			usleep(0.5);
		}
		else
		{
			kill(pid, SIGUSR2);
			usleep(0.5);
		}
		n = (n-n%2)/2;
		i++;
	}
	while (i < 17)
	{
		kill(pid, SIGUSR2);
		usleep(0.5);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;
	pid_t	client_pid;

	if (argc != 3)
		return (0);
	client_pid = getpid();
	server_pid = ft_atoi(argv[1]);
	itob_sig(server_pid, client_pid);
	stob_sig(server_pid, argv[2]);
	while(1)
	{
		signal(SIGUSR1, handler);
	}
}
