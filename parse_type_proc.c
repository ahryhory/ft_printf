/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type_proc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 10:49:58 by ahryhory          #+#    #+#             */
/*   Updated: 2018/02/21 17:11:54 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_with(t_specifier specifier, char type)
{
	int		len;
	char	*s;
	char	*str;

	s = ft_strnew(1);
	s[0] = type;
	s[1] = '\0';
	str = ft_strdup(s);
	if (specifier.width && !specifier.flags.minus && !specifier.flags.zero)
		while (specifier.width > (int)ft_strlen(str))
			str = ft_strjoin(" ", str);
	if (specifier.width && specifier.flags.zero && !specifier.flags.minus)
		while (specifier.width > (int)ft_strlen(str))
			str = ft_strjoin("0", str);
	if (specifier.width && specifier.flags.minus)
		while (specifier.width > (int)ft_strlen(str))
			str = ft_strjoin(str, " ");
	ft_putstr(str);
	len = (int)ft_strlen(str);
	return (len);
}

int			parse_type_proc(char *form, char type)
{
	t_specifier	specifier;
	int			len;

	len = 1;
	get_specifier(form, &specifier);
	if (specifier.spec)
		len = write_with(specifier, type);
	else
		ft_putchar(type);
	return (len);
}
