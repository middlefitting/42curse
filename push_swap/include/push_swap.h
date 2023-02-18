/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:25:06 by sechung           #+#    #+#             */
/*   Updated: 2023/01/29 16:30:40 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_node
{
	struct s_node	*pre;
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int				size;
	struct s_node	*top;
	struct s_node	*bot;
}	t_stack;

typedef struct s_data
{
	int				*arr;
	int				arr_size;
	struct s_stack	a;
	struct s_stack	b;
}	t_data;

void	err_exit(void);
void	arg_check(int ac, char *argv[]);
void	free_str_matrix(char **matrix);
void	make_arr(int ac, char *argv[], t_data *data);
void	make_stack(t_data *data);
void	arr_dup_check(int *arr, int size);
void	insert_sort(int *arr, int size);
void	push_swap(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	pivot_logic(t_data *data);
void	ft_push(t_node *temp, t_stack *stack);
void	greedy(t_data *data, int *temp_a, int *temp_b);
void	dup_logic(t_data *data, int *temp_a, int *temp_b);
void	mv_a(t_data *data, int index);
void	mv_b(t_data *data, int index);
int		find_ma(t_data *data, int value);
int		dup_count(int ma, int mb);
int		outline_ma(t_data *data);
void	sort_stack(t_data *data);
t_node	*new_node(void);
t_node	*ft_pop(t_stack *stack);
#endif
