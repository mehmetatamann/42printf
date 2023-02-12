/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mataman <mataman@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:11:43 by mataman           #+#    #+#             */
/*   Updated: 2023/02/12 14:13:59 by mataman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	int	len;

	len = write(1, &c, 1);
	return (len);
}

int	ft_printstr(char	*str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (*str)
		len += write(1, str++, 1);
	return (len);
}

int	ft_printnumber(int nb)
{
	long long	n;
	int			len;

	n = nb;
	len = 0;
	if (n < 0)
	{
		len += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		len += ft_printnumber(n / 10);
		len += ft_printnumber(n % 10);
	}
	if (n < 10)
		len += ft_printchar(n + 48);
	return (len);
}

int	ft_printuns(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb >= 10)
	{
		len += ft_printuns(nb / 10);
		len += ft_printuns(nb % 10);
	}
	if (nb < 10)
		len += ft_printchar(nb + 48);
	return (len);
}

int	ft_printadress(unsigned long int nb)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += ft_printadress(nb / 16);
		len += ft_printadress(nb % 16);
	}
	if (nb < 16)
	{
		if (nb < 10)
			len += ft_printchar(nb + 48);
		else
			len += ft_printchar(nb + 87);
	}
	return (len);
}
