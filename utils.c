/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:18:36 by valentins         #+#    #+#             */
/*   Updated: 2024/04/29 18:22:15 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long int		actual_time(void)
{
	long int			time;
	struct timeval		current_time;


	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

void	ft_usleep(long int time)
{
	long int	start_time;

	start_time = 0;
	start_time = actual_time();
	while ((actual_time() - start_time) < time)
		usleep(time / 10);
}

void	custom_printf(t_philo *philo, char *str, char *color)
{
	pthread_mutex_lock(&philo->data->write);
	// if (!ft_strncmp(color, B_GREEN, 10))
	// 	printf("philo %d as eaten %d times\n", philo->id + 1, philo->eating_count);
	printf("%s%ld %d %s%s\n",color, actual_time() - philo->data->arg.start_time, philo->id + 1, str, RESET);
	pthread_mutex_unlock(&philo->data->write);
}