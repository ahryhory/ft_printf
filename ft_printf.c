/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 18:17:40 by ahryhory          #+#    #+#             */
/*   Updated: 2018/01/26 12:37:13 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;

	va_start(ap, format);
	len = 0;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			format++;
			len++;
		}
		else
			len += parse(&format, ap);
	}
	va_end(ap);
	return (len);
}
