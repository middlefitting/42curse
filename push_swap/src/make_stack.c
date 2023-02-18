/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:24:11 by sechung           #+#    #+#             */
/*   Updated: 2023/01/29 16:31:05 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_pop(t_stack *stack)
{
	t_node	*result;

	result = stack->top;
	if (stack->size > 1)
	{
		stack->top = stack->top->next;
		stack->top->pre = 0;
	}
	else
	{
		stack->top = 0;
		stack->bot = 0;
	}
	result->next = 0;
	result->pre = 0;
	stack->size -= 1;
	return (result);
}

void	ft_push(t_node *temp, t_stack *stack)
{
	if (stack->size > 0)
	{
		temp->next = stack->top;
		stack->top->pre = temp;
		stack->top = temp;
	}
	else
	{
		temp->next = 0;
		stack->top = temp;
		stack->bot = temp;
	}
	temp->pre = 0;
	stack->size += 1;
}

t_node	*new_node(void)
{
	t_node	*node;

	node = (t_node *) malloc(sizeof(t_node) * 1);
	if (node == 0)
		err_exit();
	node->next = 0;
	node->pre = 0;
	return (node);
}

void	make_stack(t_data *data)
{
	t_node	*temp;
	int		i;

	i = data->arr_size;
	while (--i >= 0)
	{
		temp = new_node();
		temp->value = data->arr[i];
		ft_push(temp, &(data->a));
	}
}
