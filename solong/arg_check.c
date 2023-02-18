/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:56:13 by sechung           #+#    #+#             */
/*   Updated: 2023/01/17 16:58:08 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	argc_check(int argc)
{
	if (argc != 2)
		print_error_exit("ARGUMENT MUST BE TWO");
}

void	argv_len_check(int len)
{
	if (len < 4)
		print_error_exit("FILENAME DOES NOT VALID");
}

void	argv_extention_check(char *extention)
{
	int		diff;

	diff = ft_strncmp(extention, ".ber", 5);
	if (diff != 0)
		print_error_exit("EXTENTION MUST BE .ber");
	free(extention);
}

void	argv_check(char	**argv)
{
	int		len;
	char	*extention;

	len = ft_strlen(argv[1]);
	argv_len_check(len);
	extention = ft_substr(argv[1], len - 4, 4);
	malloc_check(extention);
	argv_extention_check(extention);
}

void	arg_check(int argc, char **argv)
{
	argc_check(argc);
	argv_check(argv);
}
