/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 10:26:48 by kabdenou          #+#    #+#             */
/*   Updated: 2022/09/29 10:20:08 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_lock(t_env *env)
{
	sem_unlink("/philo_forks");
	sem_unlink("/philo_write");
	sem_unlink("/philo_mealcheck");
	env->forks = sem_open("/philo_forks", O_CREAT, S_IRWXU, env->nb_philo);
	env->writing = sem_open("/philo_write", O_CREAT, S_IRWXU, 1);
	env->eat_die = sem_open("/philo_mealcheck", O_CREAT, S_IRWXU, 1);
}

void	init_philos(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->nb_philo)
	{
		env->philo[i].id = i;
		env->philo[i].ate = 0;
		env->philo[i].t_last_meal = 0;
		env->philo[i].env = env;
		i++;
	}
}

void	init(t_env *env, char **argv)
{
	env->nb_philo = ft_atoi(argv[1]);
	env->time_death = ft_atoi(argv[2]);
	env->time_eat = ft_atoi(argv[3]);
	env->time_sleep = ft_atoi(argv[4]);
	env->dieded = 0;
	if (argv[5])
		env->nb_eat = ft_atoi(argv[5]);
	else
		env->nb_eat = -1;
	init_lock(env);
	init_philos(env);
}

int	check_entries(int argc, char **argv)
{
	int		i;
	int		j;

	if (argc != 5 && argc != 6)
	{
		write(1, "Wrong number of arguments\n", 27);
		return (1);
	}
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				write(1, "Arguments should all be numbers no signs allowed\n",
					50);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_env	env;

	if (check_entries(argc, argv))
		return (0);
	init(&env, argv);
	start(&env);
	return (0);
}
