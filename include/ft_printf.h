/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mataman <mataman@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:12:32 by mataman           #+#    #+#             */
/*   Updated: 2023/02/12 14:12:32 by mataman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printnumber(int nb);
int	ft_printchar(char c);
int	ft_checker(char c, va_list *ptr);
int	ft_printf(const char *format, ...);
int	ft_printadress(unsigned long int nb);
int	ft_printuns(unsigned int nb);
int	ft_printhex(unsigned int nb, int s);
int	ft_printstr(char	*str);
#endif