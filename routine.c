/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentins <valentins@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:38:19 by valentins         #+#    #+#             */
/*   Updated: 2024/04/25 16:26:37 by valentins        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void *routine(void *args)
{
	t_data *data;

	data = (t_data *)args;
	if(data->philo->id % 2 == 0)
		ft_usleep(10);
	return (NULL);
}

