/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:49:53 by vsoltys           #+#    #+#             */
/*   Updated: 2024/05/08 01:50:54 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	check_death(t_data *data)
{
	pthread_mutex_lock(&data->dead);
	if (data->dead_flag == true)
	{
		pthread_mutex_unlock(&data->dead);
		return (1);
	}
	pthread_mutex_unlock(&data->dead);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n )
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i])
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	norme(t_data *data)
{
	data->philo = malloc(sizeof(t_philo) * data->arg.philo_counter);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->arg.philo_counter);
	data->dead_flag = false;
	pthread_mutex_init(&data->dead, NULL);
	pthread_mutex_init(&data->time_eat, NULL);
	pthread_mutex_init(&data->write, NULL);
}
