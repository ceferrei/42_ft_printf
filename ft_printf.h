/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceferrei <ceferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:13:15 by ceferrei          #+#    #+#             */
/*   Updated: 2022/12/27 14:15:02 by ceferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_char(char c);
int	ft_format(va_list list, const char format);
int	ft_printf(const char *format, ...);
int	ft_cont(int ap);
int	ft_hex(uintptr_t ap);
int	ft_cont_pointer(uintptr_t ap);
int	ft_hex_format(unsigned int ap, const char format);
int	ft_cont_hexa(unsigned int ap);
int	ft_str(char *ap);
int	ft_pointer(uintptr_t ap);
int	ft_number(int ap);
int	ft_nbu(unsigned int ap);
int	ft_hexa(unsigned int ap, const char format);

#endif
