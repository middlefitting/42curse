/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:14:30 by sechung           #+#    #+#             */
/*   Updated: 2022/07/20 20:23:45 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	boxing_char(t_flag *flag, t_box *box)
{
	box -> value_len = 1;
	if (flag -> type == PERCENT)
		box -> value = '%';
}

static void	boxing_string(t_box *box)
{
	box -> value_len = 6;
	if (box -> value)
		box -> value_len = ft_strlen((char *) box -> value);
}

static void	boxing_int(t_box *box)
{
	box -> base_len = 10;
	if (box -> value < 0)
	{
		box -> value_len += 1;
		box -> sign = '-';
		box -> value *= -1;
	}
	box -> value_len += ft_get_number_length(box -> value, box -> base_len);
	box -> base = ft_strndup("0123456789", 10);
}

static void	boxing_hexa(t_flag *flag, t_box *box)
{
	char	*base;

	base = "0123456789abcdef";
	if (flag -> type == XHEXA)
		base = "0123456789ABCDEF";
	if (flag -> type == POINTER)
	{
		box -> value_len = 2;
		box -> prefix = 1;
	}
	box -> base = ft_strndup(base, 16);
	box -> base_len = 16;
	box -> value_len += ft_get_number_length((unsigned long long) box -> value,
			box -> base_len);
}

t_box	box_initialize(t_flag *flag, long long arg)
{
	t_box	box;

	ft_bzero(&box, sizeof(t_box));
	box.value = arg;
	if (flag -> type == PERCENT || flag -> type == CHARACTER)
		boxing_char(flag, &box);
	if (flag -> type == STRING)
		boxing_string(&box);
	if (flag -> type == DIGIT
		|| flag -> type == INTEGER
		|| flag -> type == UDIGIT)
		boxing_int(&box);
	if (flag -> type == POINTER
		|| flag -> type == HEXA
		|| flag -> type == XHEXA)
		boxing_hexa(flag, &box);
	return (box);
}
