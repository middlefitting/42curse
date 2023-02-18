/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrx_logic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:26:37 by sechung           #+#    #+#             */
/*   Updated: 2023/01/29 16:31:17 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrx_logic(t_node **top, t_node **bot)
{
	t_node	*temp;

	temp = *bot;
	*bot = (*bot)->pre;
	(*bot)->next = 0;
	(*top)->pre = temp;
	temp->next = *top;
	temp->pre = 0;
	(*top) = temp;
}

void	rra(t_data *data)
{
	if (data->a.size < 2)
		return ;
	rrx_logic(&(data->a.top), &(data->a.bot));
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_data *data)
{
	if (data->b.size < 2)
		return ;
	rrx_logic(&(data->b.top), &(data->b.bot));
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_data *data)
{
	if (data->a.size < 2 || data->b.size < 2)
		return ;
	rrx_logic(&(data->a.top), &(data->a.bot));
	rrx_logic(&(data->b.top), &(data->b.bot));
	ft_putstr_fd("rrr\n", 1);
}
