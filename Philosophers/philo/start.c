/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 10:26:48 by kabdenou          #+#    #+#             */
/*   Updated: 2022/09/29 10:24:39 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eats(t_philo *philo)
{
	t_env	*env;

	env = philo->env;
	pthread_mutex_lock(&(env->forks[philo->left_fork_id]));
	pthread_mutex_lock(&(env->eat_die));
	action_print(env, philo->id, "has taken a fork");
	pthread_mutex_unlock(&(env->eat_die));
	pthread_mutex_lock(&(env->forks[philo->right_fork_id]));
	pthread_mutex_lock(&(env->eat_die));
	action_print(env, philo->id, "has taken a fork");
	pthread_mutex_unlock(&(env->eat_die));
	pthread_mutex_lock(&(env->eat_die));
	action_print(env, philo->id, "is eating");
	philo->t_last_meal = timestamp();
	(philo->ate)++;
	pthread_mutex_unlock(&(env->eat_die));
	sleepers(env->time_eat, philo->t_last_meal, env);
	pthread_mutex_unlock(&(env->forks[philo->left_fork_id]));
	pthread_mutex_unlock(&(env->forks[philo->right_fork_id]));
}

void	*handler(void *philo_)
{
	int		i;
	t_philo	*philo;
	t_env	*env;

	i = 0;
	philo = (t_philo *)philo_;
	env = philo->env;
	while (!(env->dieded))
	{
		philo_eats(philo);
		pthread_mutex_lock(&(env->eat_die));
		if (env->all_ate)
			break ;
		action_print(env, philo->id, "is sleeping");
		pthread_mutex_unlock(&(env->eat_die));
		sleepers(env->time_eat + env->time_sleep, philo->t_last_meal, env);
		pthread_mutex_lock(&(env->eat_die));
		action_print(env, philo->id, "is thinking");
		pthread_mutex_unlock(&(env->eat_die));
		i++;
	}
	return (NULL);
}

void	end(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->nb_philo)
	{
		pthread_mutex_destroy(&(env->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(env->writing));
}

void	is_dead(t_env *env, t_philo *p)
{
	int	i;

	while (!(env->all_ate))
	{
		i = -1;
		while (++i < env->nb_philo && !(env->dieded))
		{
			pthread_mutex_lock(&(env->eat_die));
			if ((timestamp() - p[i].t_last_meal) > env->time_death)
			{
				action_print(env, i, "died");
				env->dieded = 1;
			}
			pthread_mutex_unlock(&(env->eat_die));
		}
		if (env->dieded)
			break ;
		i = -1;
		pthread_mutex_lock(&(env->eat_die));
		while (env->nb_eat != -1
			&& ++i < env->nb_philo && p[i].ate >= env->nb_eat);
		if (i == env->nb_philo)
			env->all_ate = 1;
		pthread_mutex_unlock(&(env->eat_die));
	}
}

void	start(t_env *env)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = env->philo;
	env->start_timestamp = timestamp();
	while (i < env->nb_philo)
	{
		philo[i].t_last_meal = timestamp();
		pthread_create(&(philo[i].thread_num), NULL, handler, &(philo[i]));
		usleep(100);
		pthread_detach(philo[i].thread_num);
		i++;
	}
	is_dead(env, env->philo);
	end(env);
}
