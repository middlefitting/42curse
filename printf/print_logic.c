/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_logic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:01:32 by sechung           #+#    #+#             */
/*   Updated: 2022/07/20 19:18:24 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_string(char *value, size_t value_len)
{
	if (value == 0)
		write(1, "(null)", 6);
	else
		write(1, value, value_len);
}

static void	print_char(char value, int value_len)
{
	write(1, &value, value_len);
}

static void	print_num(unsigned long long value, int base_len, char *base)
{
	long long	temp;

	temp = value % base_len;
	value = value / base_len;
	if (value > 0)
		print_num(value, base_len, base);
	write(1, &base[temp], 1);
}

void	print_logic(t_flag *flag, t_box *box)
{
	if (box -> sign != 0)
		write(1, &(box -> sign), 1);
	if (box -> prefix == 1)
		write(1, "0x", 2);
	if (flag -> type == STRING)
		print_string((char *) box -> value, box -> value_len);
	else if ((flag -> type == CHARACTER) || (flag -> type == PERCENT))
		print_char((char) box -> value, box -> value_len);
	else
	{
		print_num((unsigned long long) box -> value,
			box -> base_len, box -> base);
		free(box -> base);
	}
}
