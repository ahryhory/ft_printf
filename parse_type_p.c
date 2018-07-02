/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:10:08 by ahryhory          #+#    #+#             */
/*   Updated: 2018/02/21 14:35:42 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_with(t_specifier specifier, char *num)
{
	int		len;

	if (ft_strequ(num, "0") && specifier.precision == -1)
	{
		ft_strdel(&num);
		num = ft_strdup("");
	}
	precision(specifier, &num, 'p');
	flag_zero(specifier, &num, 'x');
	flag_hash(specifier, &num, 'x');
	width(specifier, &num);
	ft_putstr(num);
	len = ft_strlen(num);
	return (len);
}

int			parse_type_p(char *form, va_list ap)
{
	t_specifier	specifier;
	int			len;
	char		*num;

	get_specifier(form, &specifier);
	specifier.flags.hash = 1;
	num = ft_itoa_base(va_arg(ap, uintmax_t), 16);
	len = write_with(specifier, num);
	return (len);
}
