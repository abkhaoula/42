/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 10:26:48 by kabdenou          #+#    #+#             */
/*   Updated: 2022/09/28 14:41:58 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

struct	s_env;

typedef struct s_philo
{
	int					id;
	int					ate;
	int					left_fork_id;
	int					right_fork_id;
	long long			t_last_meal;
	struct s_env		*env;
	pthread_t			thread_num;
}						t_philo;

typedef struct s_env
{
	int					nb_philo;
	int					time_death;
	int					time_eat;
	int					time_sleep;
	int					nb_eat;
	int					dieded;
	int					all_ate;
	long long			start_timestamp;
	pthread_mutex_t		eat_die;
	pthread_mutex_t		forks[300];
	pthread_mutex_t		writing;
	t_philo				philo[300];
}						t_env;

int						ft_atoi(const char *str);
void					action_print(t_env *env, int id, char *string);
long long				timestamp(void);
void					start(t_env *env);
//void					end(t_env *env, t_philo *philos);
void					end(t_env *env);

#endif
