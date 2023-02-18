/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:23:39 by sechung           #+#    #+#             */
/*   Updated: 2023/01/29 16:30:58 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(t_data *data)
{
	data->a.size = 0;
	data->b.size = 0;
	data->a.top = 0;
	data->b.top = 0;
	data->a.bot = 0;
	data->b.bot = 0;
}

int	main(int ac, char *argv[])
{
	t_data	data;

	arg_check(ac, argv);
	init_data(&data);
	make_arr(ac, argv, &data);
	make_stack(&data);
	insert_sort(data.arr, data.arr_size);
	push_swap(&data);
	exit(0);
}
