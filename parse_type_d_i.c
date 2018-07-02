/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:10:08 by ahryhory          #+#    #+#             */
/*   Updated: 2018/02/21 14:34:58 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	change_specifier(t_specifier *specifier)
{
	if (specifier->precision || specifier->flags.minus)
		specifier->flags.zero = 0;
	if (specifier->flags.plus)
		specifier->flags.space = 0;
	if (specifier->neg)
	{
		specifier->flags.plus = 0;
		specifier->flags.space = 0;
	}
}

static void	change_str(t_specifier specifier, char *num, char **str, char type)
{
	if (ft_strequ(num, "0") && specifier.precision == -1)
		*str = ft_strdup("");
	else
		*str = ft_strdup(num);
	flag_zero(specifier, str, type);
	precision(specifier, str, type);
	flag_sign(specifier, str);
	flag_space(specifier, str);
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
	intmax_t	num;

	if (specifier->length.l)
		num = va_arg(ap, long);
	else if (specifier->length.ll)
		num = va_arg(ap, long long);
	else if (specifier->length.h)
		num = (short)va_arg(ap, int);
	else if (specifier->length.hh)
		num = (signed char)va_arg(ap, int);
	else if (specifier->length.j)
		num = va_arg(ap, intmax_t);
	else if (specifier->length.z)
		num = va_arg(ap, size_t);
	else
		num = va_arg(ap, int);
	if (num < 0)
	{
		num *= -1;
		specifier->neg = 1;
	}
	return (ft_itoa_base(num, 10));
}

int			parse_type_d_i(char *form, va_list ap, char type)
{
	t_specifier	specifier;
	int			len;
	char		*num_s;

	get_specifier(form, &specifier);
	if (type == 'D')
	{
		specifier.length.l = 1;
		specifier.spec = 1;
	}
	num_s = get_length(&specifier, ap);
	if (specifier.spec)
		len = write_with(specifier, num_s, type);
	else
	{
		flag_sign(specifier, &num_s);
		len = ft_strlen(num_s);
		ft_putstr(num_s);
	}
	return (len);
}
