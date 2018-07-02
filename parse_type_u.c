/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:10:08 by ahryhory          #+#    #+#             */
/*   Updated: 2018/02/21 14:36:40 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	change_specifier(t_specifier *specifier)
{
	if (specifier->precision || specifier->flags.minus)
		specifier->flags.zero = 0;
}

static void	change_str(t_specifier specifier, char *num, char **str, char type)
{
	if (ft_strequ(num, "0") && specifier.precision == -1)
		*str = ft_strdup("");
	else
		*str = ft_strdup(num);
	flag_zero(specifier, str, type);
	precision(specifier, str, type);
	width(specifier, str);
}

static int	write_with(t_specifier specifier, char *num_s, char type)
{
	char			*str;
	int				len;

	change_specifier(&specifier);
	change_str(specifier, num_s, &str, type);
	ft_putstr(str);
	len = ft_strlen(str);
	return (len);
}

static char	*get_length(t_specifier *specifier, va_list ap)
{
	uintmax_t	num;

	if (specifier->length.l)
		num = va_arg(ap, unsigned long int);
	else if (specifier->length.ll)
		num = va_arg(ap, unsigned long long int);
	else if (specifier->length.hh)
		num = (unsigned char)va_arg(ap, unsigned int);
	else if (specifier->length.h)
		num = (unsigned short)va_arg(ap, unsigned int);
	else if (specifier->length.j)
		num = va_arg(ap, uintmax_t);
	else if (specifier->length.z)
		num = va_arg(ap, size_t);
	else
		num = va_arg(ap, unsigned int);
	return (ft_itoa_base(num, 10));
}

int			parse_type_u(char *form, va_list ap, char type)
{
	t_specifier		specifier;
	int				len;
	char			*num_s;

	(void)type;
	get_specifier(form, &specifier);
	if (type == 'U')
	{
		specifier.spec = 1;
		specifier.length.l = 1;
	}
	num_s = get_length(&specifier, ap);
	if (specifier.spec)
		len = write_with(specifier, num_s, type);
	else
	{
		len = ft_strlen(num_s);
		ft_putstr(num_s);
	}
	return (len);
}
