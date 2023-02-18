/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:26:32 by sechung           #+#    #+#             */
/*   Updated: 2023/01/29 16:31:15 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data)
{
	t_node	*temp;

	if (data->b.size == 0)
		return ;
	temp = ft_pop(&(data->b));
	ft_push(temp, &(data->a));
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_data *data)
{
	t_node	*temp;

	if (data->a.size == 0)
		return ;
	temp = ft_pop(&(data->a));
	ft_push(temp, &(data->b));
	ft_putstr_fd("pb\n", 1);
}
