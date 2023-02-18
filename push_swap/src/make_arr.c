/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:23:50 by sechung           #+#    #+#             */
/*   Updated: 2023/01/29 16:31:02 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_matrix_size(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

int	get_arr_size(int ac, char *argv[])
{
	int			i;
	int			size;
	char		**temp;

	i = 1;
	size = 0;
	while (i < ac)
	{
		temp = ft_split(argv[i], ' ');
		if (temp == 0)
			err_exit();
		size += get_matrix_size(temp);
		free_str_matrix(temp);
		i++;
	}
	if (size == 0)
		err_exit();
	return (size);
}

int	ft_atoi2(const char *str)
{
	size_t					i;
	unsigned long long		result;
	int						sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		if (((result > 2147483647) && (sign == 1))
			|| ((result > 2147483648) && (sign == -1)))
			err_exit();
		i++;
	}
	if (str[i] != 0 || (ft_strlen(str) == 1
			&& (str[0] == '-' || str[0] == '+')))
		err_exit();
	return (((int) result) * sign);
}

void	append_arr(int *arr, char **matrix, int *index)
{
	int	i;

	i = 0;
	while (matrix[i] != 0)
	{
		arr[*index] = ft_atoi2(matrix[i]);
		*index += 1;
		i++;
	}
}

void	make_arr(int ac, char *argv[], t_data *data)
{
	int		i;
	int		index;
	int		arr_size;
	int		*arr;
	char	**temp;

	i = 1;
	index = 0;
	arr_size = get_arr_size(ac, argv);
	arr = (int *) malloc(sizeof(int) * arr_size);
	if (arr == 0)
		err_exit();
	while (i < ac)
	{
		temp = ft_split(argv[i], ' ');
		if (temp == 0)
			err_exit();
		append_arr(arr, temp, &index);
		free_str_matrix(temp);
		i++;
	}
	data->arr = arr;
	data->arr_size = arr_size;
}
