/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rx_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:26:48 by sechung           #+#    #+#             */
/*   Updated: 2023/01/29 16:31:20 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rx_logic(t_node **top, t_node **bot)
{
	t_node	*temp;

	temp = *top;
	*top = (*top)->next;
	(*top)->pre = 0;
	(*bot)->next = temp;
	temp->pre = *bot;
	temp->next = 0;
	(*bot) = temp;
}

void	ra(t_data *data)
{
	if (data->a.size < 2)
		return ;
	rx_logic(&(data->a.top), &(data->a.bot));
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_data *data)
{
	if (data->b.size < 2)
		return ;
	rx_logic(&(data->b.top), &(data->b.bot));
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_data *data)
{
	if (data->a.size < 2 || data->b.size < 2)
		return ;
	rx_logic(&(data->a.top), &(data->a.bot));
	rx_logic(&(data->b.top), &(data->b.bot));
	ft_putstr_fd("rr\n", 1);
}
