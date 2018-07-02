/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:55:59 by ahryhory          #+#    #+#             */
/*   Updated: 2018/02/21 17:12:28 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		check(char type)
{
	if (!ft_isdigit(type) && type != '+' &&
			type != '-' && type != ' ' &&
			type != '#' && type != '0' &&
			type != 'h' && type != 'l' &&
			type != 'j' && type != 'z' &&
			type != '.')
		return (1);
	return (0);
}

static size_t	find_len(const char **format)
{
	size_t	i;
	size_t	j;
	char	*conversions;

	i = 1;
	conversions = "sSpdDioOuUxXcC%";
	while ((*format)[i])
	{
		j = 0;
		while (j < ft_strlen(conversions))
		{
			if ((*format)[i] == conversions[j])
				return (i);
			j++;
		}
		if (check((*format)[i]))
			return (i);
		i++;
	}
	return (i - 1);
}

static void		parse_type(char type, char *form, va_list ap, int *length)
{
	if (type == 's' || type == 'S')
		*length = parse_type_s(form, ap, type);
	else if (type == 'p')
		*length = parse_type_p(form, ap);
	else if (type == 'd' || type == 'D' || type == 'i')
		*length = parse_type_d_i(form, ap, type);
	else if (type == 'o' || type == 'O')
		*length = parse_type_o(form, ap, type);
	else if (type == 'u' || type == 'U')
		*length = parse_type_u(form, ap, type);
	else if (type == 'x' || type == 'X')
		*length = parse_type_x(form, ap, type);
	else if (type == 'c' || type == 'C')
		*length = parse_type_c(form, ap, type);
	else if (type != '\0' && check(type))
		*length = parse_type_proc(form, type);
}

int				parse(const char **format, va_list ap)
{
	char	*form;
	size_t	len;
	char	type;
	int		length;

	length = 0;
	len = find_len(format);
	form = ft_strsub(*format, 1, len);
	*format += len + 1;
	type = form[ft_strlen(form) - 1];
	parse_type(type, form, ap, &length);
	return (length);
}
