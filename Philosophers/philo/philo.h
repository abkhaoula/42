/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 10:26:48 by kabdenou          #+#    #+#             */
/*   Updated: 2022/09/29 10:13:56 by kabdenou         ###   ########.fr       */
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
# include <stdatomic.h>

struct	s_env;

typedef struct s_philo
{
	atomic_int					id;
	atomic_int					ate;
	atomic_int					left_fork_id;
	atomic_int					right_fork_id;
	atomic_llong				t_last_meal;
	struct s_env				*env;
	pthread_t					thread_num;
}								t_philo;

typedef struct s_env
{
	atomic_int					nb_philo;
	atomic_int					time_death;
	atomic_int					time_eat;
	atomic_int					time_sleep;
	atomic_int					nb_eat;
	atomic_int					dieded;
	atomic_int					all_ate;
	atomic_llong				start_timestamp;
	pthread_mutex_t				eat_die;
	pthread_mutex_t				forks[300];
	pthread_mutex_t				writing;
	t_philo						philo[300];
}								t_env;

int						ft_atoi(const char *str);
void					action_print(t_env *env, int id, char *string);
long long				timestamp(void);
void					start(t_env *env);
//void					end(t_env *env, t_philo *philos);
void					end(t_env *env);
void					sleepers(long long duration_time,
							long long start_time, t_env *env);

#endif
