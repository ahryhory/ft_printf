/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:10:08 by ahryhory          #+#    #+#             */
/*   Updated: 2018/02/21 14:34:53 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_char(char type, unsigned int c, int *len)
{
	if (type == 'C')
		*len = ft_putwchar(c);
	else
		ft_putchar(c);
}

static int	write_with(t_specifier specifier, va_list ap, char type)
{
	int				len;
	unsigned int	c;
	char			*str;

	str = ft_strdup("");
	c = va_arg(ap, unsigned int);
	specifier.width -= get_count_bytes(c);
	flag_zero(specifier, &str, type);
	width(specifier, &str);
	len = 1;
	if (specifier.flags.minus)
	{
		put_char(type, c, &len);
		ft_putstr(str);
	}
	else
	{
		ft_putstr(str);
		put_char(type, c, &len);
	}
	len += (int)ft_strlen(str);
	return (len);
}

int			parse_type_c(char *form, va_list ap, char type)
{
	t_specifier	specifier;
	int			len;

	get_specifier(form, &specifier);
	if (specifier.length.l)
		type = 'C';
	if (specifier.spec)
		len = write_with(specifier, ap, type);
	else
	{
		if (type == 'C')
			len = ft_putwchar(va_arg(ap, unsigned int));
		else
		{
			len = 1;
			ft_putchar(va_arg(ap, unsigned int));
		}
	}
	return (len);
}
