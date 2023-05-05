/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceferrei <ceferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 23:59:24 by ceferrei          #+#    #+#             */
/*   Updated: 2023/01/14 01:16:59 by ceferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str(char *ap)
{
	int	i;

	i = 0;
	if (!ap)
		return (write(1,"(null)", 6));
	while (ap[i])
	{
		write(1, &ap[i], 1);
		i++;
	}
	return (i);
}

int	ft_pointer(uintptr_t ap)
{
	int	i;

	if (ap == 0)
		return (write(1, "(nil)", 5));
	else
	{
		i = write(1, "0x", 2);
		ft_hex(ap);
	}
	return (i += ft_cont_pointer(ap));
}

int	ft_number(int ap)//verificar se ponho unsigned
{
	int	i;

	i = ft_cont(ap);
	if (ap == -2147483648)
	{
		ft_char('-');
		ft_char('2');
		ap = 147483648;
	}
	if (ap < 0)
	{
		ft_char('-');
		ap = -ap;
	}
	if (ap >= 10)
	{
		ft_number(ap / 10);
		ap %= 10;
	}
	if (ap < 10)
		ft_char(ap + 48);
	return (i);
}

int	ft_nbu(unsigned int ap)
{
	int	i;

	i = 0;
	if (ap >= 10)
	{
		i += ft_number(ap / 10);
		ap %= 10;
	}
	if (ap < 10)
		i += ft_char(ap + 48);
	return (i);
}

int	ft_hexa(unsigned int ap, const char format)
{
	if (ap == 0)
		return (ft_char('0'));
	else
		ft_hex_format(ap, format);
	return (ft_cont_hexa(ap));
}
