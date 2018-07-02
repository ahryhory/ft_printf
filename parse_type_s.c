/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:10:08 by ahryhory          #+#    #+#             */
/*   Updated: 2018/02/21 14:49:00 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	write_wchar(wchar_t *wstr, int *len)
{
	while (*wstr)
	{
		*len += ft_putwchar(*wstr);
		wstr++;
	}
}

static int	write_with_wchar(t_specifier specifier, char *str, wchar_t *wstr)
{
	int		len;
	int		i;

	len = 0;
	if (specifier.precision)
		wstr = ft_wstrsub(wstr, 0, precision_wchar(specifier.precision, wstr));
	str = ft_strdup("");
	i = 0;
	while (wstr[i])
		specifier.width -= get_count_bytes(wstr[i++]);
	flag_zero(specifier, &str, 's');
	width(specifier, &str);
	if (specifier.flags.minus)
		write_wchar(wstr, &len);
	ft_putstr(str);
	if (!specifier.flags.minus)
		write_wchar(wstr, &len);
	len += (int)ft_strlen(str);
	return (len);
}

static int	write_with(t_specifier specifier, char *str, wchar_t *wstr)
{
	int		len;

	len = 0;
	if (str)
	{
		if (specifier.precision)
			str = ft_strsub(str, 0, specifier.precision);
		else
			str = ft_strdup(str);
		flag_zero(specifier, &str, 's');
		width(specifier, &str);
		ft_putstr(str);
		len = (int)ft_strlen(str);
	}
	else
		len = write_with_wchar(specifier, str, wstr);
	return (len);
}

static void	init(char **str, wchar_t **wstr, char type, va_list ap)
{
	*str = NULL;
	*wstr = NULL;
	if (type == 's')
		*str = va_arg(ap, char *);
	else
		*wstr = va_arg(ap, wchar_t *);
}

int			parse_type_s(char *form, va_list ap, char type)
{
	t_specifier	specifier;
	int			len;
	char		*str;
	wchar_t		*wstr;

	get_specifier(form, &specifier);
	if (specifier.length.l)
		type = 'S';
	init(&str, &wstr, type, ap);
	if (!wstr && !str)
		return (parse_type_s_null(specifier));
	len = 0;
	if (specifier.spec)
		len = write_with(specifier, str, wstr);
	else
	{
		if (type == 'S')
			write_wchar(wstr, &len);
		else
		{
			len = ft_strlen(str);
			ft_putstr(str);
		}
	}
	return (len);
}
