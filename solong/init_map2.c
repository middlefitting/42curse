/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:57:25 by sechung           #+#    #+#             */
/*   Updated: 2023/01/17 16:57:26 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fd_check(int fd)
{
	if (fd < 0)
		print_error_exit("OPEN FILE FAILED");
}

void	read_check(int result)
{
	if (result < 0)
		print_error_exit("READ FILE FAILED");
}

void	size_check(int size)
{
	if (size == 0)
		print_error_exit("EMPTY FILE");
}
