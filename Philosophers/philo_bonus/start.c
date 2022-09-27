/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 10:26:48 by kabdenou          #+#    #+#             */
/*   Updated: 2022/09/18 12:30:31 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eats(t_philo *philo)
{
	t_env	*env;

	env = philo->env;
	sem_wait(env->forks);
	action_print(env, philo->id, "has taken a fork");
	sem_wait(env->forks);
	action_print(env, philo->id, "has taken a fork");
	sem_wait(env->eat_die);
	action_print(env, philo->id, "is eating");
	philo->t_last_meal = timestamp();
	sem_post(env->eat_die);
	usleep(env->time_eat * 1000);
	(philo->ate)++;
	sem_post(env->forks);
	sem_post(env->forks);
}

void	*is_dead(void *philo_)
{
	t_philo			*philo;
	t_env			*env;

	philo = (t_philo *)philo_;
	env = philo->env;
	while (1)
	{
		sem_wait(env->eat_die);
		if ((timestamp() - philo->t_last_meal) > env->time_death)
		{
			action_print(env, philo->id, "died");
			env->dieded = 1;
			sem_wait(env->writing);
			exit(1);
		}
		sem_post(env->eat_die);
		if (env->dieded)
			break ;
		usleep(1000);
		if (philo->ate >= env->nb_eat && env->nb_eat != -1)
			break ;
	}
	return (NULL);
}

void	handler(void *philo_)
{
	t_philo	*philo;
	t_env	*env;

	philo = (t_philo *)philo_;
	env = philo->env;
	philo->t_last_meal = timestamp();
	pthread_create(&(philo->dead_check), NULL, is_dead, philo_);
	if (philo->id % 2)
		usleep(15000);
	while (!(env->dieded))
	{
		philo_eats(philo);
		if (philo->ate >= env->nb_eat && env->nb_eat != -1)
			break ;
		action_print(env, philo->id, "is sleeping");
		usleep(env->time_sleep * 1000);
		action_print(env, philo->id, "is thinking");
	}
	pthread_join(philo->dead_check, NULL);
	if (env->dieded)
		exit(1);
	exit(0);
}

void	end(t_env *env)
{
	int	i;
	int	status;

	i = 0;
	while (i < env->nb_philo)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = 0;
			while (i < env->nb_philo)
			{
				kill(env->philo[i].pid, SIGTERM);
				i++;
			}
			break ;
		}
		i++;
	}
	sem_close(env->forks);
	sem_close(env->writing);
	sem_close(env->eat_die);
	sem_unlink("/philo_forks");
	sem_unlink("/philo_write");
	sem_unlink("/philo_mealcheck");
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
		philo[i].pid = fork();
		if (philo[i].pid == 0)
			handler(&(philo[i]));
		usleep(100);
		i++;
	}
	end(env);
}
