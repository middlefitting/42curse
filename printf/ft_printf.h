/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:17:08 by sechung           #+#    #+#             */
/*   Updated: 2022/07/20 20:23:49 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define PERCENT 1
# define CHARACTER 2
# define STRING 3
# define POINTER 4
# define DIGIT 5
# define INTEGER 6
# define UDIGIT 7
# define HEXA 8
# define XHEXA 9

typedef struct s_flag
{
	int			type;
}				t_flag;

typedef struct s_box
{
	char		sign;
	int			prefix;
	long long	value;
	int			value_len;
	char		*base;
	int			base_len;
}				t_box;

int			ft_printf(const char *form, ...);

int			parse(t_flag *flag, char **form);

void		ft_bzero(void *dest, size_t size);
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);
char		*ft_strndup(const char *s, size_t size);
size_t		ft_get_number_length(unsigned long long n, int base_len);

long long	flag_initialize(t_flag *flag, va_list ap);

t_box		box_initialize(t_flag *flag, long long arg);

void		print_logic(t_flag *flag, t_box *box);

#endif
