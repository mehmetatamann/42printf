/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mataman <mataman@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:13:39 by mataman           #+#    #+#             */
/*   Updated: 2023/02/12 14:13:49 by mataman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned int nb, int c)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += ft_printhex(nb / 16, c);
		len += ft_printhex(nb % 16, c);
	}
	if (nb < 16)
	{
		if (nb < 10)
			len += ft_printchar(nb + 48);
		else
		{
			if (c == 1)
				len += ft_printchar(nb + 87);
			else
				len += ft_printchar(nb + 55);
		}
	}
	return (len);
}
