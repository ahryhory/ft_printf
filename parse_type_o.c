/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:10:08 by ahryhory          #+#    #+#             */
/*   Updated: 2018/02/21 14:35:27 by ahryhory         ###   ########.fr       */
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
	int		hash;
	int		precision_var;

	precision_var = specifier.precision;
	hash = specifier.flags.hash;
	if (ft_strequ(num, "0") && (precision_var == -1 || hash))
		*str = ft_strdup("");
	else
		*str = ft_strdup(num);
	flag_zero(specifier, str, type);
	precision(specifier, str, type);
	flag_hash(specifier, str, type);
	width(specifier, str);
}

static int	write_with(t_specifier specifier, char *num, char type)
{
	char	*str;
	int		len;

	change_specifier(&specifier);
	change_str(specifier, num, &str, type);
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
	return (ft_itoa_base(num, 8));
}

int			parse_type_o(char *form, va_list ap, char type)
{
	t_specifier	specifier;
	int			len;
	char		*num;

	get_specifier(form, &specifier);
	if (type == 'O')
	{
		specifier.spec = 1;
		specifier.length.l = 1;
	}
	num = get_length(&specifier, ap);
	if (specifier.spec)
		len = write_with(specifier, num, type);
	else
	{
		len = ft_strlen(num);
		ft_putstr(num);
	}
	return (len);
}
