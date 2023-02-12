/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mataman <mataman@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:11:46 by mataman           #+#    #+#             */
/*   Updated: 2023/02/12 14:11:46 by mataman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_definer(const char ch, va_list args)
{
	int		length;

	length = 0;
	if (ch == 'c')
		length += ft_printchar(va_arg(args, int));
	else if (ch == 's')
		length += ft_printstr(va_arg(args, char *));
	else if (ch == 'p')
	{
		length += write(1, "0x", 2);
		length += ft_printadress(va_arg(args, unsigned long int));
	}
	else if (ch == 'd' || ch == 'i')
		length += ft_printnumber(va_arg(args, int));
	else if (ch == 'u')
		length += ft_printuns(va_arg(args, unsigned int));
	else if (ch == 'x')
		length += ft_printhex(va_arg(args, unsigned int), 1);
	else if (ch == 'X')
		length += ft_printhex(va_arg(args, unsigned int), 2);
	else if (ch == '%')
		length += write(1, "%", 1);
	return (length);
}

int	ft_printf(const char *str, ...)
{
	size_t		i;
	size_t		len;
	va_list		args;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_definer(str[i], args);
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
