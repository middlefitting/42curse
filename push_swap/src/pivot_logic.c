/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_logic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:24:22 by sechung           #+#    #+#             */
/*   Updated: 2023/01/29 16:31:07 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mv_low_middle(t_data *data, int pivot1, int pivot2)
{
	int	temp;

	temp = data->a.top->value;
	if (temp < pivot1)
	{
		pb(data);
		rb(data);
	}
	else if (temp < pivot2)
		pb(data);
	else
		ra(data);
}

void	mv_high(t_data *data)
{
	pb(data);
}

void	pivot_logic(t_data *data)
{
	int	pivot1;
	int	pivot2;
	int	i;

	pivot1 = data->arr[data->a.size / 3];
	pivot2 = data->arr[data->a.size * 2 / 3];
	i = data->a.size;
	while (i-- > 0 && data->a.size > 3)
		mv_low_middle(data, pivot1, pivot2);
	while (data->a.size > 3)
		mv_high(data);
}
