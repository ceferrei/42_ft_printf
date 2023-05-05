/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceferrei <ceferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:06:20 by ceferrei          #+#    #+#             */
/*   Updated: 2023/01/14 01:17:00 by ceferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_format(va_list list, const char format)
{
	if (format == 'c')
		return (ft_char(va_arg(list, int)));
	else if (format == 's')
		return (ft_str(va_arg(list, char *)));
	else if (format == 'p')
		return (ft_pointer(va_arg(list, uintptr_t)));
	else if (format == 'd' || format == 'i')
		return (ft_number(va_arg(list, int))); // a funcao lida com negativos. deixo unsigned?
	else if (format == 'u')
		return (ft_nbu(va_arg(list, unsigned int)));
	else if (format == 'x')
		return (ft_hexa(va_arg(list, unsigned int), format));
	else if (format == 'X')
		return (ft_hexa(va_arg(list, unsigned int), format));
	else if (format == '%')
		return (ft_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_format(list, format[i + 1]);
			i++;
		}
		else
			count += ft_char(format[i]);
		i++;
	}
	va_end(list);
	return (count);
}
