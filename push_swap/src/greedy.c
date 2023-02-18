/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:23:10 by sechung           #+#    #+#             */
/*   Updated: 2023/01/29 16:30:55 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_mb(t_data *data, int index)
{
	if (index >= data->b.size / 2 + 1)
		return ((data->b.size - index) * -1);
	return (index);
}

int	dup_count(int ma, int mb)
{
	if (ma < 0 || mb < 0)
	{
		if (ma < mb)
			return (mb * -1);
		return (ma * -1);
	}
	if (ma > 0 || mb > 0)
	{
		if (ma > mb)
			return (mb);
		return (ma);
	}
	return (0);
}

int	more_short(int ma, int mb, int temp_a, int temp_b)
{
	int	dup;

	dup = dup_count(ma, mb);
	if (ma < 0)
		ma *= -1;
	if (mb < 0)
		mb *= -1;
	if (temp_a < 0)
		temp_a *= -1;
	if (temp_b < 0)
		temp_b *= -1;
	if ((ma + mb - dup) < (temp_a + temp_b))
		return (1);
	return (0);
}

void	greedy(t_data *data, int *temp_a, int *temp_b)
{
	int		i;
	int		ma;
	int		mb;
	t_node	*temp;

	i = 0;
	temp = data->b.top;
	while (i < data->b.size)
	{
		ma = find_ma(data, temp->value);
		mb = find_mb(data, i);
		if (i == 0 || more_short(ma, mb, *temp_a, *temp_b))
		{
			*temp_a = ma;
			*temp_b = mb;
		}
		i++;
		temp = temp->next;
	}
}
