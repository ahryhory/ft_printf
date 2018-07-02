/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type_s_null.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:37:39 by ahryhory          #+#    #+#             */
/*   Updated: 2018/02/21 14:36:27 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_type_s_null(t_specifier specifier)
{
	char	*str;

	str = ft_strdup("(null)");
	if (specifier.precision)
		str = ft_strsub(str, 0, specifier.precision);
	flag_zero(specifier, &str, 's');
	width(specifier, &str);
	ft_putstr(str);
	return ((int)ft_strlen(str));
}
