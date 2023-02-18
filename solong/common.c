/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:56:54 by sechung           #+#    #+#             */
/*   Updated: 2023/01/17 18:13:03 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error_exit(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	perror(msg);
	exit(1);
}

void	malloc_check(char *str)
{
	if (str == 0)
		print_error_exit("MALLOC FAILED");
}
