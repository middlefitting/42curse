/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sx_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:27:08 by sechung           #+#    #+#             */
/*   Updated: 2023/01/29 16:31:22 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sx_logic(t_node *top)
{
	int	temp;

	temp = top->value;
	top->value = top->next->value;
	top->next->value = temp;
}

void	sa(t_data *data)
{
	if (data->a.size < 2)
		return ;
	sx_logic(data->a.top);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_data *data)
{
	if (data->b.size < 2)
		return ;
	sx_logic(data->b.top);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_data *data)
{
	if (data->a.size < 2 || data->b.size < 2)
		return ;
	sx_logic(data->a.top);
	sx_logic(data->b.top);
	ft_putstr_fd("ss\n", 1);
}
