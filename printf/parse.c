/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:25:48 by sechung           #+#    #+#             */
/*   Updated: 2022/07/22 12:50:27 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_char(char **dest, char *charset)
{
	char	*result;

	if (**dest == 0)
		return (-1);
	result = ft_strchr(charset, **dest);
	if (result == 0)
		return (-1);
	*dest = *dest + 1;
	return (result - charset + 1);
}

int	parse(t_flag *flag, char **form)
{
	char	*ptr;

	ptr = (*form) + 1;
	flag -> type = parse_char(&ptr, "%cspdiuxX");
	if (flag -> type != 0)
		*form = ptr;
	return (flag -> type);
}
