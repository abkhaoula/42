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
# include <sys/time.h>

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
	pthread_mutex_t writing;
	pthread_mutex_t forking;
} t_state;

t_state init_state(int philo_num, int die_time, int eat_time, int sleep_time, int max_eat_time)
{
	int i;
	t_state s;

	s.died_num = 0;
	s.full_num = 0;
	s.ids = 1;
	s.philo_num = philo_num;
	s.die_time = die_time;
	s.eat_time = eat_time;
	s.sleep_time = sleep_time;
	s.max_eat_time = max_eat_time;
	s.forks = malloc(philo_num * sizeof(int));
	i = 0;
	pthread_mutex_init(&(s.writing), NULL);
	pthread_mutex_init(&(s.forking), NULL);
	while (i < philo_num)
	{
		s.forks[i] = 1;
		i++;
	}
	return (s);
}

void *myThreadFun(void *state)
{
	int id;
	char idc;
	long long time_waiting_eating;
	long long time_sleeping;
	long long time_eating;
	struct timeval	t;
	int action;
	int eating_num;
	write(1, "created\n", 9);
		
	// first_init
	id = ((t_state *)state)->ids;
	((t_state *)state)->ids = id +1;
	gettimeofday(&t, NULL);
	time_waiting_eating =  (t.tv_sec * 1000) + (t.tv_usec / 1000);
	action = 0;
	eating_num = 0;
	idc = '0' + id;
	// first_init

	while((action >= 0) && (((t_state *)state)->died_num + ((t_state *)state)->full_num) != ((t_state *)state)->philo_num)
	{
		if (action == 0) //waiting to eat
		{
			if (((t_state *)state)->forks[(id-1) % ((t_state *)state)->philo_num] && ((t_state *)state)->forks[(id) % ((t_state *)state)->philo_num])
			{
				pthread_mutex_lock(&((t_state *)state)->writing);
				write(1, "pilo", 5);
				write(1, &idc, 1);
				write(1, " : took a fork\n", 16);
				pthread_mutex_unlock(&((t_state *)state)->writing);
				((t_state *)state)->forks[(id-1) % ((t_state *)state)->philo_num] = 0;
				((t_state *)state)->forks[(id) % ((t_state *)state)->philo_num] = 0;
				action = 1;
			}
			else
			{
				gettimeofday(&t, NULL);
				if ((t.tv_sec * 1000) + (t.tv_usec / 1000) - time_waiting_eating >= ((t_state *)state)->die_time)
				{
					pthread_mutex_lock(&((t_state *)state)->writing);
					write(1, "pilo", 5);
					write(1, &idc, 1);
					write(1, " : died\n", 16);
					pthread_mutex_unlock(&((t_state *)state)->writing);
					action = -1;
					((t_state *)state)->died_num ++;
				}
				//mesure time and test
			}
			//sleep and all
		}
		if (action == 1) //eating
		{
			pthread_mutex_lock(&((t_state *)state)->writing);
			write(1, &idc, 1);
			//write(1, "philo", 5);
			//write(1, &idc, 1);
			//write(1, " : e1ating\n", 11);
			pthread_mutex_unlock(&((t_state *)state)->writing);
			eating_num++;
			sleep(((t_state *)state)->eat_time);
			((t_state *)state)->forks[(id-1) % ((t_state *)state)->philo_num] = 1;
			((t_state *)state)->forks[(id) % ((t_state *)state)->philo_num] = 1;
			action = 2;
			if (eating_num == ((t_state *)state)->max_eat_time)
			{
				action = -1;
				((t_state *)state)->full_num ++;
			}

		}
		if (action == 2) //sleeping
		{
			pthread_mutex_lock(&((t_state *)state)->writing);
			write(1, "pilo", 5);
			write(1, &idc, 1);
			write(1, " : sleeping\n", 13);
			pthread_mutex_unlock(&((t_state *)state)->writing);
			sleep(((t_state *)state)->sleep_time);
			pthread_mutex_lock(&((t_state *)state)->writing);
			write(1, "pilo", 5);
			write(1, &idc, 1);
			write(1, " : thinking\n", 13);
			pthread_mutex_unlock(&((t_state *)state)->writing);
			gettimeofday(&t, NULL);
			time_waiting_eating =  (t.tv_sec * 1000) + (t.tv_usec / 1000);
			action = 0;
		}
	}
    return NULL;
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

	if (argc != 6)
	{
		write(1, "Wrong number of arguments\n", 27);
		return(0);
	}
	philo_num = atoi(argv[1]);
	die_time = atoi(argv[2]);
	eat_time = atoi(argv[3]);
	sleep_time = atoi(argv[4]);
	max_eat_time = atoi(argv[5]);
	s = init_state(philo_num, die_time, eat_time, sleep_time, max_eat_time);

	i = 0;
	philosopher = malloc(sizeof(pthread_t) * philo_num);
	while (i < philo_num)
	{
		pthread_create(&philosopher[i], NULL, myThreadFun, &s);
		i++;
	}
	while((s.died_num + s.full_num) != philo_num)
	{
		sleep(1);
	}
}