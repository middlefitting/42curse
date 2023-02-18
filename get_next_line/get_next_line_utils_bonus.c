/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:30:12 by sechung           #+#    #+#             */
/*   Updated: 2022/07/16 16:54:06 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	char	c_c;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	c_c = (char) c;
	while (s[i] != c_c && s[i] != 0)
		i++;
	if (s[i] == c_c)
		return ((char *) s + i);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	result;

	result = 0;
	while (str[result] != 0)
		result++;
	return (result);
}

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t	i;
	char	*c_dest;
	char	*c_src;

	if (!dest)
		(void)(*((char *) dest));
	if (!src)
		(void)(*((char *) src));
	if (dest == src)
		return (dest);
	c_dest = (char *) dest;
	c_src = (char *) src;
	i = 0;
	while (i < size)
	{
		c_dest[i] = c_src[i];
		i++;
	}
	return (dest);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	char	*dest;

	if (s1 == 0 && s2 == 0)
		return (0);
	if (s1 == 0)
		return (ft_strndup(s2, ft_strlen(s2)));
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	dest = malloc(sizeof(char) * (size_s1 + size_s2 + 1));
	if (dest == 0)
	{
		free((char *) s1);
		return (0);
	}
	dest[size_s1 + size_s2] = 0;
	ft_memcpy(dest, s1, size_s1);
	ft_memcpy(dest + size_s1, s2, size_s2);
	free((char *) s1);
	return (dest);
}
