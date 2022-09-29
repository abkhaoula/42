/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 10:26:48 by kabdenou          #+#    #+#             */
/*   Updated: 2022/09/18 12:30:31 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_neg(const char *nptr, int *i)
{
	size_t	is_negative;

	is_negative = 0;
	if (nptr[*i] == '-')
	{
		(*i)++;
		is_negative = 1;
	}
	else if (nptr[*i] == '+')
		(*i)++;
	return (is_negative);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	size_t	is_negative;
	int		num;

	i = 0;
	while (nptr[i] == '\t' || nptr[i] == '\v' || nptr[i] == '\f'
		|| nptr[i] == '\r' || nptr[i] == '\n' || nptr[i] == ' ')
		i++;
	is_negative = is_neg(nptr, &i);
	num = 0;
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		if (num >= 1000000000)
		{
			if (is_negative)
				return (0);
			return (-1);
		}
		num = num * 10;
		num = num + nptr[i] - '0';
		i++;
	}
	if (is_negative)
		num = (-1) * num;
	return (num);
}

long long	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	action_print(t_env *env, int id, char *string)
{
	sem_wait(env->writing);
	if (!(env->dieded))
	{
		printf("%lli ", timestamp() - env->start_timestamp);
		printf("%i ", id + 1);
		printf("%s\n", string);
	}
	sem_post(env->writing);
	return ;
}

void		sleepers(long long duration_time, long long start_time, t_env *env)
{
	while (!(env->dieded))
	{
		if ((timestamp() - start_time) >= duration_time)
			break ;
		usleep(50);
	}
}