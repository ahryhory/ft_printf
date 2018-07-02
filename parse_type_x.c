/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:10:08 by ahryhory          #+#    #+#             */
/*   Updated: 2018/02/21 14:36:57 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	change_specifier(t_specifier *specifier, char *num)
{
	if (specifier->precision || specifier->flags.minus)
		specifier->flags.zero = 0;
	if (ft_strequ(num, "0"))
		specifier->flags.hash = 0;
}

static void	change_str(t_specifier specifier, char *num, char **str, char type)
{
	if (ft_strequ(num, "0") && specifier.precision == -1)
		*str = ft_strdup("");
	else
		*str = ft_strdup(num);
	flag_zero(specifier, str, type);
	precision(specifier, str, type);
	flag_hash(specifier, str, type);
	if (type == 'X')
		*str = to_up_case(*str);
	width(specifier, str);
}

static int	write_with(t_specifier specifier, char *num, char type)
{
	char	*str;
	int		len;

	change_specifier(&specifier, num);
	change_str(specifier, num, &str, type);
	ft_putstr(str);
	len = ft_strlen(str);
	return (len);
}

static char	*get_length(t_specifier *specifier, va_list ap)
{
	uintmax_t	num;
	char		*num_s;

	if (specifier->length.hh)
		num = (unsigned char)va_arg(ap, unsigned int);
	else if (specifier->length.h)
		num = (unsigned short)va_arg(ap, unsigned int);
	else if (specifier->length.l)
		num = va_arg(ap, unsigned long int);
	else if (specifier->length.ll)
		num = va_arg(ap, unsigned long long int);
	else if (specifier->length.j)
		num = va_arg(ap, uintmax_t);
	else if (specifier->length.z)
		num = va_arg(ap, size_t);
	else
		num = va_arg(ap, unsigned int);
	num_s = ft_itoa_base(num, 16);
	return (num_s);
}

int			parse_type_x(char *form, va_list ap, char type)
{
	t_specifier	specifier;
	int			len;
	char		*num;

	get_specifier(form, &specifier);
	num = get_length(&specifier, ap);
	if (specifier.spec)
		len = write_with(specifier, num, type);
	else
	{
		if (type == 'X')
			num = to_up_case(num);
		len = ft_strlen(num);
		ft_putstr(num);
	}
	return (len);
}
