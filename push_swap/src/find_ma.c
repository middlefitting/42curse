/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ma.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:22:24 by sechung           #+#    #+#             */
/*   Updated: 2023/01/29 16:30:50 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_value(t_stack stack)
{
	int		result;
	t_node	*temp;

	result = stack.top->value;
	temp = stack.top->next;
	while (temp)
	{
		if (result < temp->value)
			result = temp->value;
		temp = temp->next;
	}
	return (result);
}

int	min_value(t_stack stack)
{
	int		result;
	t_node	*temp;

	result = stack.top->value;
	temp = stack.top->next;
	while (temp)
	{
		if (result > temp->value)
			result = temp->value;
		temp = temp->next;
	}
	return (result);
}

int	outline_ma(t_data *data)
{
	int		result;
	int		target;
	t_node	*temp;

	result = 0;
	temp = data->a.top;
	target = min_value(data->a);
	while (temp)
	{
		if (temp->value == target)
			break ;
		result++;
		temp = temp->next;
	}
	if (result >= data->a.size / 2 + 1)
		result = (data->a.size - result) * -1;
	return (result);
}

int	middle_ma(t_data *data, int value)
{
	int		result;
	t_node	*temp;

	result = 1;
	temp = data->a.top;
	while (temp->next)
	{
		if (value > temp->value && value < temp->next->value)
			break ;
		result++;
		temp = temp->next;
	}
	if (result >= data->a.size / 2 + 1)
		result = (data->a.size - result) * -1;
	return (result);
}

int	find_ma(t_data *data, int value)
{
	if (value > max_value(data->a) || value < min_value(data->a))
		return (outline_ma(data));
	else
		return (middle_ma(data, value));
}
