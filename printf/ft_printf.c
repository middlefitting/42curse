/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:36:59 by sechung           #+#    #+#             */
/*   Updated: 2022/07/22 12:54:55 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	initial_result(char *form, va_list ap)
{
	int		result;
	int		temp;
	t_flag	flag;
	t_box	box;

	result = 0;
	ft_bzero(&flag, sizeof(t_flag));
	while (*form)
	{
		if (*form == '%')
		{
			temp = parse(&flag, &form);
			if (temp == -1)
				return (-1);
			// if (temp == 0)
			// 	return (result);
			box = box_initialize(&flag, flag_initialize(&flag, ap));
			print_logic(&flag, &box);
			result += box.value_len;
		}
		else
			result += write(1, form++, 1);
	}
	return (result);
}

int	ft_printf(const char *form, ...)
{
	int		result;
	va_list	ap;

	va_start(ap, form);
	result = initial_result((char *) form, ap);
	va_end(ap);
	return (result);
}
