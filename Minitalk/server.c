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

int	g_num[20];

void	handler1(int signum)
{
	if (signum == SIGUSR1)
	{
		g_num[-1] = 1;
		g_num[g_num[0]] = 1;
		g_num[0]++;
	}
}

void	handler2(int signum)
{
	if (signum == SIGUSR2)
	{
		g_num[-1] = 1;
		g_num[g_num[0]] = 0;
		g_num[0]++;
	}
}

void	decode(void)
{
	int		i;
	int		pow_tow;
	int		c;
	char	letter;

	i = 1;
	c = 0;
	pow_tow = 128;
	while (i < 9)
	{
		c = c + (pow_tow * g_num[i]);
		pow_tow = pow_tow / 2;
		i++;
	}
	letter = (char) c;
	write(1, &letter, 1);
	g_num[0] = 1;
}

int	decode_pid(void)
{
	int	i;
	int	pid;

	i = 17;
	pid = 0;
	while (i > 0)
	{
		pid = (pid * 2) + g_num[i];
		i--;
	}
	return (pid);
}

void receive_pid(int *pid)
{
	signal(SIGUSR1, handler1);
	if (g_num[0] == 18)
		(*pid) = decode_pid();
	signal(SIGUSR2, handler2);
	if (g_num[0] == 18)
		(*pid) = decode_pid();
	if ((*pid) != 0)
		g_num[0] = 1;
}

void receive_message(void)
{
	if (g_num[-1] != -1)
	{
		g_num[-1] = 0;
	}
	signal(SIGUSR1, handler1);
	if (g_num[0] == 9)
		decode();
	signal(SIGUSR2, handler2);
	if (g_num[0] == 9)
		decode();
}

void reset_send(int *pid, int *timer)
{
	(*timer) = 0;
	g_num[-1] = -1;
	kill((*pid), SIGUSR1);
	(*pid) = 0;
}

int	main(void)
{
	pid_t	pid;
	int		timer;
	int		client_pid;

	client_pid = 0;
	g_num[0] = 1;
	g_num[-1] = -1;
	timer = 0;
	pid = getpid();
	printf("pid: %u\n", pid);
	while (1)
	{
		if (client_pid == 0)
			receive_pid(&client_pid);
		else
			receive_message();
		if (g_num[-1] == 0)
			timer++;
		else
			timer = 0;
		if (timer == 100000)
			reset_send(&client_pid, &timer);
	}
}
