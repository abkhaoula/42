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

void *myThreadFun(void *vargp)
{
    sleep(1);
    printf("%s \n", (char *)vargp);
    return NULL;
}

int	main (int argc, char **argv)
{
	pthread_t *philosopher;
	int i;
	int num;
	
	i = 0;
	num = atoi(argv[1]);
	philosopher = malloc(sizeof(pthread_t) * num);
	while (i < num)
	{
		pthread_create(&philosopher[i], NULL, myThreadFun, argv[i + 2]);
		i++;
	}
	while(1);
}