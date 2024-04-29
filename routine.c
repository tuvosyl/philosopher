/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:38:19 by valentins         #+#    #+#             */
/*   Updated: 2024/04/29 18:27:14 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
void	eat(t_philo *philo)
{
	if (philo->data->dead_flag == true)
		return ;
	pthread_mutex_lock(philo->own_fork);
	pthread_mutex_lock(philo->left_fork);
	// pthread_mutex_lock(&philo->data->dead);
	// pthread_mutex_unlock(&philo->data->dead);
	custom_printf(philo, "has taken is own fork", B_YELLOW);
	custom_printf(philo, "has taken a fork", B_YELLOW);
	custom_printf(philo, "is eating", B_GREEN);
	pthread_mutex_lock(&philo->data->time_eat);
	philo->last_meal_timer = actual_time();
	philo->eating_count++;
	pthread_mutex_unlock(&philo->data->time_eat);
	ft_usleep(philo->data->arg.time_to_eat);
	pthread_mutex_unlock(philo->own_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	think(t_philo *philo)
{
	custom_printf(philo, "big brain time", B_CYAN);
}

void	sleepp(t_philo *philo)
{
	custom_printf(philo, "is sleeping", B_WHITE);
	ft_usleep(philo->data->arg.time_to_sleep);
}
void *routine(void *args)
{
	t_philo *philo;

	philo = (t_philo *)args;
	custom_printf(philo, "created", B_RED);
	philo->last_meal_timer = actual_time();
	if ((philo->id +1) % 2 == 0)
		ft_usleep(10);
	while(12)
	{
		if(philo->data->dead_flag == true)
			break;
		eat(philo);
		if(philo->data->dead_flag == true)
			break;
		sleepp(philo);
		custom_printf(philo, "big brain time", B_CYAN);
	}
	return (NULL);
}

