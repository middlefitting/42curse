/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:45:01 by sechung           #+#    #+#             */
/*   Updated: 2022/12/29 17:29:33 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	size;

	if (!s)
		return ;
	size = ft_strlen(s);
	write(fd, s, size);
}

int	ft_atoi(const char *str)
{
	size_t					i;
	unsigned long long		result;
	int						sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		if ((result > 9223372036854775807) && (sign == 1))
			return (-1);
		if ((result > 9223372036854775808UL) && (sign == -1))
			return (0);
		i++;
	}
	return (((int) result) * sign);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	result;
	int		temp;

	temp = n;
	if (temp == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (temp < 0)
	{
		write(fd, "-", 1);
		temp *= -1;
	}
	if (temp >= 10)
		ft_putnbr_fd(temp / 10, fd);
	result = temp % 10 + '0';
	write(fd, &result, 1);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*copy;
	size_t	size;

	i = 0;
	size = ft_strlen(s);
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
