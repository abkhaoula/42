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
# include <semaphore.h>
#include <fcntl.h>
#include <signal.h>

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
	pid_t *process_id;
	sem_t *writing;
	sem_t *forking;
	sem_t **is_dying;
} t_state;


char *join(const char* s1, const char* s2)
{
    char* result = malloc(strlen(s1) + strlen(s2) + 1);

    if (result) // thanks @pmg
    {
        strcpy(result, s1);
        strcat(result, s2);
    }

    return result;
}

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
	char *semisdying;

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
	sem_unlink("writing");
	s.writing = sem_open("writing", O_CREAT, S_IRWXU, 1);
	//pthread_mutex_init(&(s.writing), NULL);
	sem_unlink("forks");
	s.forking = sem_open("forks", O_CREAT, S_IRWXU, philo_num);
	//s.forking = malloc(philo_num * sizeof(pthread_mutex_t));
	s.is_dying = malloc(philo_num * sizeof(sem_t*));
	//s.is_dying = malloc(philo_num * sizeof(pthread_mutex_t));
	s.process_id = malloc(philo_num * sizeof(pid_t));
	semisdying = "dying";
	while (i < philo_num)
	{
		s.forks[i] = 1;
		s.philo_died[i] = 0;
		s.philo_action[i] = 0;
		s.philo_waiting_to_eat[i] = s.time_start;
		sem_unlink((const char *)join("dying", (const char *)itoa(i, 10)));
		s.is_dying[i] = sem_open((const char *)join("dying", (const char *)itoa(i, 10)), O_CREAT, S_IRWXU, 1);
		//pthread_mutex_init(&(s.forking[i]), NULL);
		//pthread_mutex_init(&(s.is_dying[i]), NULL);
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
				sem_wait(((t_state *)state)->forking);
				//pthread_mutex_lock(&((t_state *)state)->forking[(id-1) % ((t_state *)state)->philo_num]);
				sem_wait(((t_state *)state)->writing);
				//pthread_mutex_lock(&((t_state *)state)->writing);
				gettimeofday(&t, NULL);
				tmp_time = (t.tv_sec * 1000) + (t.tv_usec / 1000) - ((t_state *)state)->time_start;
				time_tmp = itoa(tmp_time,10);
				write(1, time_tmp, strlen(time_tmp));
				write(1, " : philo", 9);
				write(1, &idc, 1);
				write(1, " : took a fork\n", 16);
				sem_post(((t_state *)state)->writing);
				//pthread_mutex_unlock(&((t_state *)state)->writing);
				sem_wait(((t_state *)state)->forking);
				//pthread_mutex_lock(&((t_state *)state)->forking[(id) % ((t_state *)state)->philo_num]);
				sem_wait(((t_state *)state)->writing);
				//pthread_mutex_lock(&((t_state *)state)->writing);
				gettimeofday(&t, NULL);
				tmp_time = (t.tv_sec * 1000) + (t.tv_usec / 1000) - ((t_state *)state)->time_start;
				time_tmp = itoa(tmp_time,10);
				write(1, time_tmp, strlen(time_tmp));
				write(1, " : philo", 9);
				write(1, &idc, 1);
				write(1, " : took a fork\n", 16);
				sem_post(((t_state *)state)->writing);
				//pthread_mutex_unlock(&((t_state *)state)->writing);
				((t_state *)state)->forks[(id-1) % ((t_state *)state)->philo_num] = 0;
				((t_state *)state)->forks[(id) % ((t_state *)state)->philo_num] = 0;
				((t_state *)state)->philo_action[id - 1] = 1;
			}
		}
		sem_wait(((t_state *)state)->is_dying[id-1]);
		//pthread_mutex_lock(&((t_state *)state)->is_dying[id-1]);
		if (((t_state *)state)->philo_action[id - 1] == 1) //eating
		{
			sem_wait(((t_state *)state)->writing);
			//pthread_mutex_lock(&((t_state *)state)->writing);
			tmp_time = (t.tv_sec * 1000) + (t.tv_usec / 1000) - ((t_state *)state)->time_start;
			time_tmp = itoa(tmp_time,10);
			write(1, time_tmp, strlen(time_tmp));
			write(1, " : philo", 9);
			write(1, &idc, 1);
			write(1, " : eating\n", 11);
			sem_post(((t_state *)state)->writing);
			//pthread_mutex_unlock(&((t_state *)state)->writing);
			eating_num++;
			usleep(((t_state *)state)->eat_time * 1000);
			sem_post(((t_state *)state)->forking);
			sem_post(((t_state *)state)->forking);
			//pthread_mutex_unlock(&((t_state *)state)->forking[(id-1) % ((t_state *)state)->philo_num]);
			//pthread_mutex_unlock(&((t_state *)state)->forking[(id) % ((t_state *)state)->philo_num]);
			
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
		//pthread_mutex_unlock(&((t_state *)state)->is_dying[id-1]);
		sem_post(((t_state *)state)->is_dying[id-1]);
		if (((t_state *)state)->philo_action[id - 1] == 2) //sleeping
		{
			sem_wait(((t_state *)state)->writing);
			//pthread_mutex_lock(&((t_state *)state)->writing);
			gettimeofday(&t, NULL);
			tmp_time = (t.tv_sec * 1000) + (t.tv_usec / 1000) - ((t_state *)state)->time_start;
			time_tmp = itoa(tmp_time,10);
			write(1, time_tmp, strlen(time_tmp));
			write(1, " : philo", 9);
			write(1, &idc, 1);
			write(1, " : sleeping\n", 13);
			sem_post(((t_state *)state)->writing);
			//pthread_mutex_unlock(&((t_state *)state)->writing);
			usleep(((t_state *)state)->sleep_time * 1000);
			sem_wait(((t_state *)state)->writing);
			//pthread_mutex_lock(&((t_state *)state)->writing);
			tmp_time = (t.tv_sec * 1000) + (t.tv_usec / 1000) - ((t_state *)state)->time_start + ((t_state *)state)->sleep_time;
			time_tmp = itoa(tmp_time,10);
			write(1, time_tmp, strlen(time_tmp));
			write(1, " : philo", 9);
			write(1, &idc, 1);
			write(1, " : thinking\n", 13);
			sem_post(((t_state *)state)->writing);
			//pthread_mutex_unlock(&((t_state *)state)->writing);
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
		sem_wait(s->is_dying[i]);
		//pthread_mutex_lock(&s->is_dying[i]);
		if (!s->philo_died[i] && s->philo_action[i] == 0 && ((time - s->philo_waiting_to_eat[i]) > s->die_time))
		{
			sem_wait(s->writing);
			//pthread_mutex_lock(&s->writing);
			time_tmp = itoa(time - s->time_start,10);
			write(1, time_tmp, strlen(time_tmp));
			write(1, " : philo", 9);
			write(1, &ic, 1);
			write(1, " : died\n", 9);
			sem_post(s->writing);
			//pthread_mutex_unlock(&s->writing);
			s->philo_died[i] = 1;
			s->died_num ++;
			s->philo_action[i] = -1; 
		}
		//pthread_mutex_unlock(&s->is_dying[i]);
		sem_post(s->is_dying[i]);
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
		s.process_id[i] = fork();
		if(s.process_id[i] < 0)
			return (1);
		if (s.process_id[i] == 0)
			myThreadFun(&s);
		usleep(100);
		i++;
	}
	while((s.died_num + s.full_num) != philo_num)
	{
		death_update(&s);
		//write(1, "end\n", 5);
	}
	//pthread_mutex_destroy(&(s.writing));
	//sem_close(rules->forks);
	//sem_unlink("/philo_forks");
	write(1, "end\n", 5);
	while(i < philo_num)
	{
		kill(s.process_id[i], SIGKILL);
	}
}