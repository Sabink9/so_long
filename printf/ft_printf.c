/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saciurus <saciurus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:26:42 by saciurus          #+#    #+#             */
/*   Updated: 2025/01/24 17:33:10 by saciurus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(const char *format, int i, va_list args)
{
	int	count;

	count = 0;
	if (format[i + 1] == 'c')
		count += ft_printc(va_arg(args, int));
	else if (format[i + 1] == 's')
		count += ft_prints(va_arg(args, char *));
	else if (format[i + 1] == 'd')
		count += ft_printd(va_arg(args, int));
	else if (format[i + 1] == 'i')
		count += ft_printd(va_arg(args, int));
	else if (format[i + 1] == 'u')
		count += ft_printu(va_arg(args, unsigned int));
	else if (format[i + 1] == 'p')
		count += ft_printp(va_arg(args, void *));
	else if (format[i + 1] == 'x')
		count += ft_printx(va_arg(args, unsigned int));
	else if (format[i + 1] == 'X')
		count += ft_printxx(va_arg(args, unsigned int));
	else if (format[i + 1] == '%')
		count += ft_printc('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += check_format(format, i, args);
			i++;
		}
		else
			count += ft_printc(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
