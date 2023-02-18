/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:24:54 by sechung           #+#    #+#             */
/*   Updated: 2023/01/29 16:31:13 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_data *data)
{
	int	top;
	int	mid;
	int	bot;

	top = data->a.top->value;
	mid = data->a.top->next->value;
	bot = data->a.bot->value;
	if (top > mid && mid > bot)
	{
		sa(data);
		rra(data);
	}
	else if (top > bot && bot > mid)
		ra(data);
	else if (mid > bot && bot > top)
	{
		rra(data);
		sa(data);
	}
	else if (bot > top && top > mid)
		sa(data);
	else if (mid > top && top > bot)
		rra(data);
}

void	sort_two(t_data *data)
{
	if (data->a.top->value > data->a.top->next->value)
		sa(data);
}

void	push_swap(t_data *data)
{
	int	temp_a;
	int	temp_b;

	if (data->a.size == 4)
		pb(data);
	pivot_logic(data);
	if (data->a.size == 2)
		sort_two(data);
	else if (data->a.size == 3)
		sort_three(data);
	while (data->b.size > 0)
	{
		temp_a = 0;
		temp_b = 0;
		greedy(data, &temp_a, &temp_b);
		dup_logic(data, &temp_a, &temp_b);
		mv_a(data, temp_a);
		mv_b(data, temp_b);
		pa(data);
	}
	sort_stack(data);
}
