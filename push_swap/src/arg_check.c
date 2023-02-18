/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:21:55 by sechung           #+#    #+#             */
/*   Updated: 2023/01/29 16:30:45 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ac_check(int ac)
{
	if (ac < 2)
		exit(0);
}

void	null_check(char *str)
{
	if (str == 0 || *str == 0)
		err_exit();
}

void	element_check(char x)
{
	if (x == '-' || x == '+')
		return ;
	if (x >= '0' && x <= '9')
		return ;
	else if (x >= 9 && x <= 13)
		return ;
	else if (x == 32)
		return ;
	err_exit();
}

void	argv_check(int ac, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		null_check(argv[i]);
		j = ft_strlen(argv[i]);
		while (--j >= 0)
			element_check(argv[i][j]);
	}
}

void	arg_check(int ac, char *argv[])
{
	ac_check(ac);
	argv_check(ac, argv);
}
