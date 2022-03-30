/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
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

int num[15];

void	handler1(int signum)
{
	if (signum == SIGUSR1)
	{
		num[-1] = 1;
		num[num[0]] = 1;
		num[0]++;
	}
}

void	handler2(int signum)
{
	if (signum == SIGUSR2)
	{
		num[-1] = 1;
		num[num[0]] = 0;
		num[0]++;
	}
}

void decode(void)
{
	int i;
	int pow_tow;
	int c;
	char letter;

	i = 1;
	c = 0;
	pow_tow = 128;
	while(i < 9)
	{
		c = c + (pow_tow * num[i]);
		pow_tow = pow_tow / 2;
		i++;
	}
	letter = (char) c;
	write(1,&letter,1);
	num[0] = 1;
}

int	main(void)
{
	pid_t	pid;
	int		timer;
	int		send;

	num[0] = 1;
	num[-1] = -1; //-1 back to start    0 reading but stopped    1 reading still
	timer = 0;
	send = 0;
	pid = getpid();
	printf("pid: %u\n", pid);
	while (1)
	{
		if (num[-1] != -1)
		{
			if (send == 0)
			{
				printf("\nsending\n");
				send = 1;
			}
			num[-1] = 0;
		}
		signal(SIGUSR1, handler1);
		if (num[0] == 9)
			decode();
		signal(SIGUSR2, handler2);
		if (num[0] == 9)
			decode();
		if (num[-1] == 0)
			timer++;
		else
			timer = 0;
		if (timer == 100000)
		{
			send = 0;
			timer = 0;
			num[-1] = -1;
		}
	}
}
