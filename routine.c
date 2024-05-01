/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:38:19 by valentins         #+#    #+#             */
/*   Updated: 2024/05/01 11:53:30 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	eat(t_philo *philo)
{
	if (check_death(philo->data))
		return ;
	pthread_mutex_lock(philo->own_fork);
	pthread_mutex_lock(philo->left_fork);
	if (check_death(philo->data))
	{
		pthread_mutex_unlock(philo->own_fork);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	custom_printf(philo, "has taken is own fork", B_YELLOW);
	custom_printf(philo, "has taken a fork", B_YELLOW);
	custom_printf(philo, "eating the miksmaks", B_GREEN);
	pthread_mutex_lock(&philo->data->time_eat);
	philo->last_meal_timer = actual_time();
	pthread_mutex_unlock(&philo->data->time_eat);
	pthread_mutex_lock(&philo->data->eating_count);
	philo->eating_count++;
	pthread_mutex_unlock(&philo->data->eating_count);
	ft_usleep(philo->data->arg.time_to_eat);
	pthread_mutex_unlock(philo->own_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	sleepp(t_philo *philo)
{
	custom_printf(philo, "mi mi mi mi", B_WHITE);
	ft_usleep(philo->data->arg.time_to_sleep);
}

void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	custom_printf(philo, "created", B_RED);
	pthread_mutex_lock(&philo->data->time_eat);
	philo->last_meal_timer = actual_time();
	pthread_mutex_unlock(&philo->data->time_eat);
	if ((philo->id + 1) % 2 == 0)
		ft_usleep(10);
	while (12)
	{
		custom_printf(philo, "big brain time", B_CYAN);
		if (check_death(philo->data))
			break ;
		eat(philo);
		if (check_death(philo->data))
			break ;
		sleepp(philo);
		if (check_death(philo->data))
			break ;
	}
	return (NULL);
}
