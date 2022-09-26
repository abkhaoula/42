/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 10:26:48 by kabdenou          #+#    #+#             */
/*   Updated: 2022/09/18 12:30:31 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <string.h>

typedef struct s_state
{
	int ids;
	int died_num;
	int full_num;
	int philo_num;
	int die_time;
	int eat_time;
	int sleep_time;
	int max_eat_time;
	int *forks;
	int *philo_died;
	int *philo_action;
	int *philo_waiting_to_eat;
	int time_start;
	pthread_mutex_t writing;
	pthread_mutex_t *forking;
} t_state;

char* itoa(int val, int base){
	
	static char buf[32] = {0};
	
	int i = 30;
	if (val == 0)
		return ("0");
	
	for(; val && i ; --i, val /= base)
	
		buf[i] = "0123456789abcdef"[val % base];
	
	return &buf[i+1];
	
}

t_state init_state(int philo_num, int die_time, int eat_time, int sleep_time, int max_eat_time)
{
	int i;
	t_state s;
	struct timeval	t;

	s.died_num = 0;
	s.full_num = 0;
	s.ids = 1;
	s.philo_num = philo_num;
	s.die_time = die_time;
	s.eat_time = eat_time;
	s.sleep_time = sleep_time;
	s.max_eat_time = max_eat_time;
	s.forks = malloc(philo_num * sizeof(int));
	s.philo_died = malloc(philo_num * sizeof(int));
	s.philo_action = malloc(philo_num * sizeof(int));
	s.philo_waiting_to_eat = malloc(philo_num * sizeof(int));
	gettimeofday(&t, NULL);
	s.time_start = (t.tv_sec * 1000) + (t.tv_usec / 1000);
	i = 0;
	pthread_mutex_init(&(s.writing), NULL);
	s.forking = malloc(philo_num * sizeof(pthread_mutex_t));
	while (i < philo_num)
	{
		s.forks[i] = 1;
		s.philo_died[i] = 0;
		s.philo_action[i] = 0;
		s.philo_waiting_to_eat[i] = s.time_start;
		pthread_mutex_init(&(s.forking[i]), NULL);
		i++;
	}
	return (s);
}

void *myThreadFun(void *state)
{
	int id;
	char idc;
	long long tmp_time;
	char *time_tmp;
	long long time_sleeping;
	long long time_eating;
	struct timeval	t;
	int eating_num;
		
	// first_init
	id = ((t_state *)state)->ids;
	((t_state *)state)->ids = id +1;
	eating_num = 0;
	idc = '0' + id;
	// first_init


	while((!((t_state *)state)->philo_died[id - 1]) && (((t_state *)state)->died_num + ((t_state *)state)->full_num) != ((t_state *)state)->philo_num)
	{
		if (((t_state *)state)->philo_action[id - 1] == 0) //waiting to eat
		{
			if (((t_state *)state)->forks[(id-1) % ((t_state *)state)->philo_num] && ((t_state *)state)->forks[(id) % ((t_state *)state)->philo_num])
			{
				pthread_mutex_lock(&((t_state *)state)->forking[(id-1) % ((t_state *)state)->philo_num]);
				pthread_mutex_lock(&((t_state *)state)->writing);
				gettimeofday(&t, NULL);
				tmp_time = (t.tv_sec * 1000) + (t.tv_usec / 1000) - ((t_state *)state)->time_start;
				time_tmp = itoa(tmp_time,10);
				write(1, time_tmp, strlen(time_tmp));
				write(1, " : philo", 9);
				write(1, &idc, 1);
				write(1, " : took a fork\n", 16);
				pthread_mutex_unlock(&((t_state *)state)->writing);
				pthread_mutex_lock(&((t_state *)state)->forking[(id) % ((t_state *)state)->philo_num]);
				pthread_mutex_lock(&((t_state *)state)->writing);
				gettimeofday(&t, NULL);
				tmp_time = (t.tv_sec * 1000) + (t.tv_usec / 1000) - ((t_state *)state)->time_start;
				time_tmp = itoa(tmp_time,10);
				write(1, time_tmp, strlen(time_tmp));
				write(1, " : philo", 9);
				write(1, &idc, 1);
				write(1, " : took a fork\n", 16);
				pthread_mutex_unlock(&((t_state *)state)->writing);
				((t_state *)state)->forks[(id-1) % ((t_state *)state)->philo_num] = 0;
				((t_state *)state)->forks[(id) % ((t_state *)state)->philo_num] = 0;
				((t_state *)state)->philo_action[id - 1] = 1;
			}
		}
		if (((t_state *)state)->philo_action[id - 1] == 1) //eating
		{
			pthread_mutex_lock(&((t_state *)state)->writing);
			tmp_time = (t.tv_sec * 1000) + (t.tv_usec / 1000) - ((t_state *)state)->time_start;
			time_tmp = itoa(tmp_time,10);
			write(1, time_tmp, strlen(time_tmp));
			write(1, " : philo", 9);
			write(1, &idc, 1);
			write(1, " : eating\n", 11);
			pthread_mutex_unlock(&((t_state *)state)->writing);
			eating_num++;
			usleep(((t_state *)state)->eat_time * 1000);
			pthread_mutex_unlock(&((t_state *)state)->forking[(id-1) % ((t_state *)state)->philo_num]);
			pthread_mutex_unlock(&((t_state *)state)->forking[(id) % ((t_state *)state)->philo_num]);
			
			((t_state *)state)->forks[(id-1) % ((t_state *)state)->philo_num] = 1;
			((t_state *)state)->forks[(id) % ((t_state *)state)->philo_num] = 1;
			((t_state *)state)->philo_action[id - 1] = 2;
			if (eating_num == ((t_state *)state)->max_eat_time && ((t_state *)state)->max_eat_time > 0)
			{
				((t_state *)state)->philo_died[id - 1] = 1;
				((t_state *)state)->full_num ++;
				return (NULL);
			}

		}
		if (((t_state *)state)->philo_action[id - 1] == 2) //sleeping
		{
			pthread_mutex_lock(&((t_state *)state)->writing);
			gettimeofday(&t, NULL);
			tmp_time = (t.tv_sec * 1000) + (t.tv_usec / 1000) - ((t_state *)state)->time_start;
			time_tmp = itoa(tmp_time,10);
			write(1, time_tmp, strlen(time_tmp));
			write(1, " : philo", 9);
			write(1, &idc, 1);
			write(1, " : sleeping\n", 13);
			pthread_mutex_unlock(&((t_state *)state)->writing);
			usleep(((t_state *)state)->sleep_time * 1000);
			pthread_mutex_lock(&((t_state *)state)->writing);
			tmp_time = (t.tv_sec * 1000) + (t.tv_usec / 1000) - ((t_state *)state)->time_start + ((t_state *)state)->sleep_time;
			time_tmp = itoa(tmp_time,10);
			write(1, time_tmp, strlen(time_tmp));
			write(1, " : philo", 9);
			write(1, &idc, 1);
			write(1, " : thinking\n", 13);
			pthread_mutex_unlock(&((t_state *)state)->writing);
			((t_state *)state)->philo_waiting_to_eat[id - 1] = (t.tv_sec * 1000) + (t.tv_usec / 1000);
			((t_state *)state)->philo_action[id - 1] = 0;
		}
	}
    return NULL;
}

int death_update(t_state *s)
{
	int i;
	int time;
	char *time_tmp;
	char ic;
	struct timeval	t;

	i = 0;
	gettimeofday(&t, NULL);
	time = (t.tv_sec * 1000) + (t.tv_usec / 1000);
	while (i < s->philo_num)
	{
		ic = '0' + i;
		if (!s->philo_died[i] && s->philo_action[i] == 0 && ((time - s->philo_waiting_to_eat[i]) > s->die_time))
		{
			pthread_mutex_lock(&s->writing);
			time_tmp = itoa(time - s->time_start,10);
			write(1, time_tmp, strlen(time_tmp));
			write(1, " : philo", 9);
			write(1, &ic, 1);
			write(1, " : died\n", 9);
			pthread_mutex_unlock(&s->writing);
			s->philo_died[i] = 1;
			s->died_num ++;
		}
		i++;
	}
}

int	main (int argc, char **argv)
{
	pthread_t *philosopher;
	int philo_num;
	int die_time;
	int eat_time;
	int sleep_time;
	int max_eat_time;
	int i;
	char* str;
	t_state s;

	str = "hello";

	if (argc != 6 && argc != 5)
	{
		write(1, "Wrong number of arguments\n", 27);
		return(0);
	}
	philo_num = atoi(argv[1]);
	die_time = atoi(argv[2]);
	eat_time = atoi(argv[3]);
	sleep_time = atoi(argv[4]);
	max_eat_time = -1;
	if (argc == 6)
		max_eat_time = atoi(argv[5]);
	s = init_state(philo_num, die_time, eat_time, sleep_time, max_eat_time);

	i = 0;
	philosopher = malloc(sizeof(pthread_t) * philo_num);
	while (i < philo_num)
	{
		pthread_create(&philosopher[i], NULL, myThreadFun, &s);
		//usleep(1);
		i++;
	}
	while((s.died_num + s.full_num) != philo_num)
	{
		death_update(&s);
	}
	pthread_mutex_destroy(&(s.writing));
}