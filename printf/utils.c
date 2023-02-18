/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:09:21 by sechung           #+#    #+#             */
/*   Updated: 2022/07/20 20:44:16 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bzero(void *dest, size_t size)
{
	size_t			i;
	unsigned char	*c_dest;

	i = 0;
	c_dest = (unsigned char *) dest;
	while (i < size)
	{
		c_dest[i] = 0;
		i++;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	result;

	result = 0;
	while (str[result] != 0)
		result++;
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	char	c_c;
	size_t	i;

	i = 0;
	c_c = (char) c;
	while (s[i] != c_c && s[i] != 0)
		i++;
	if (s[i] == c_c)
		return ((char *) s + i);
	return (0);
}

char	*ft_strndup(const char *s, size_t size)
{
	size_t	i;
	char	*copy;

	i = 0;
	copy = malloc(sizeof(char) * (size + 1));
	if (copy == 0)
		return (0);
	while (i < size)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}

size_t	ft_get_number_length(unsigned long long n, int base_len)
{
	size_t				result;
	unsigned long long	temp;

	result = 0;
	temp = n;
	if (n == 0)
		result = 1;
	while (temp > 0)
	{
		temp /= base_len;
		result += 1;
	}
	return (result);
}
