/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:22:18 by sechung           #+#    #+#             */
/*   Updated: 2023/01/29 16:30:47 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	key;
	int	sorted;

	i = 1;
	sorted = 1;
	while (i < size)
	{
		key = arr[i];
		j = i - 1;
		while (arr[j] > key && j >= 0)
		{
			sorted = 0;
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
	arr_dup_check(arr, size);
	if (sorted == 1)
		exit(0);
}

void	arr_dup_check(int *arr, int size)
{
	int	i;

	i = size;
	while (--i > 0)
	{
		if (arr[i] == arr[i - 1])
			err_exit();
	}
}
