
#include "ft_printf.h"

long long	cut_value(t_flag *flag, va_list ap)
{
	if (flag -> type == PERCENT)
		return (0);
	else if (flag -> type == POINTER || flag -> type == STRING)
		return ((long long) va_arg(ap, void *));
	else if (flag -> type == CHARACTER)
		return ((char) va_arg(ap, int));
	else if (flag -> type == DIGIT || flag -> type == INTEGER)
		return ((int) va_arg(ap, int));
	else if (flag -> type == UDIGIT)
		return ((unsigned int) va_arg(ap, unsigned int));
	else if (flag -> type == HEXA)
		return ((unsigned int) va_arg(ap, unsigned int));
	else if (flag -> type == XHEXA)
		return ((unsigned int) va_arg(ap, unsigned int));
	return (0);
}
