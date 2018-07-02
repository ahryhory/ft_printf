/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 12:21:42 by ahryhory          #+#    #+#             */
/*   Updated: 2018/02/21 11:23:33 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init(t_specifier **specifier)
{
	(*specifier)->spec = 0;
	(*specifier)->neg = 0;
	(*specifier)->flags.minus = 0;
	(*specifier)->flags.plus = 0;
	(*specifier)->flags.hash = 0;
	(*specifier)->flags.space = 0;
	(*specifier)->flags.zero = 0;
	(*specifier)->length.hh = 0;
	(*specifier)->length.h = 0;
	(*specifier)->length.l = 0;
	(*specifier)->length.ll = 0;
	(*specifier)->length.j = 0;
	(*specifier)->length.z = 0;
}

static void	get_flags(t_specifier **specifier, char **form)
{
	while (**form == '-' || **form == '+' || **form == ' ' ||
			**form == '#' || **form == '0')
	{
		if (**form == '-')
			(*specifier)->flags.minus = 1;
		else if (**form == '+')
			(*specifier)->flags.plus = 1;
		else if (**form == ' ')
			(*specifier)->flags.space = 1;
		else if (**form == '#')
			(*specifier)->flags.hash = 1;
		else if (**form == '0')
			(*specifier)->flags.zero = 1;
		(*form)++;
	}
}

static void	get_length(t_specifier **specifier, char *form)
{
	if (ft_strstr(form, "hh"))
		(*specifier)->length.hh = 1;
	else if (ft_strchr(form, 'h'))
		(*specifier)->length.h = 1;
	else if (ft_strchr(form, 'l'))
		(*specifier)->length.l = 1;
	else if (ft_strstr(form, "ll"))
		(*specifier)->length.ll = 1;
	else if (ft_strchr(form, 'j'))
		(*specifier)->length.j = 1;
	else if (ft_strchr(form, 'z'))
		(*specifier)->length.z = 1;
}

void		get_precision(t_specifier **specifier, char *form)
{
	char	*precision;

	precision = ft_strchr(form, '.');
	if (precision)
	{
		(*specifier)->precision = ft_atoi(precision + 1);
		if ((*specifier)->precision == 0)
			(*specifier)->precision = -1;
	}
	else
		(*specifier)->precision = 0;
}

void		get_specifier(char *form, t_specifier *specifier)
{
	init(&specifier);
	get_precision(&specifier, form);
	get_flags(&specifier, &form);
	get_length(&specifier, form);
	specifier->width = ft_atoi(form);
	if (specifier->flags.minus || specifier->flags.plus ||
		specifier->flags.space || specifier->flags.hash ||
		specifier->flags.zero || specifier->width ||
		specifier->precision)
		specifier->spec = 1;
}
