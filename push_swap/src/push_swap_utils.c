/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:24:44 by sechung           #+#    #+#             */
/*   Updated: 2023/01/29 16:31:10 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dup_logic(t_data *data, int *temp_a, int *temp_b)
{
	int	dup;

	dup = dup_count(*temp_a, *temp_b);
	while (dup-- > 0)
	{
		if (*temp_a > 0 && *temp_b > 0)
		{
			rr(data);
			*temp_a -= 1;
			*temp_b -= 1;
		}
		else if (*temp_a < 0 && *temp_b < 0)
		{
			rrr(data);
			*temp_a += 1;
			*temp_b += 1;
		}
	}
}

void	mv_a(t_data *data, int index)
{
	if (index < 0)
	{
		while (index < 0)
		{
			rra(data);
			index++;
		}
	}
	if (index > 0)
	{
		while (index > 0)
		{
			ra(data);
			index--;
		}
	}
}

void	mv_b(t_data *data, int index)
{
	if (index < 0)
	{
		while (index < 0)
		{
			rrb(data);
			index++;
		}
	}
	if (index > 0)
	{
		while (index > 0)
		{
			rb(data);
			index--;
		}
	}
}

void	sort_stack(t_data *data)
{
	int	min;

	min = outline_ma(data);
	while (min)
	{
		if (min > 0)
		{
			ra(data);
			min--;
		}
		else if (min < 0)
		{
			rra(data);
			min++;
		}
	}
}
