/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 13:48:54 by ahryhory          #+#    #+#             */
/*   Updated: 2018/02/21 17:10:11 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_zero(t_specifier specifier, char **str, char type)
{
	int		tmp;

	tmp = specifier.flags.space + specifier.flags.plus + specifier.neg;
	if (type == 'x' || type == 'X')
		tmp += specifier.flags.hash * 2;
	else if (type == 'u')
		tmp += specifier.flags.hash;
	else if (type == 'o' || type == 'O')
		tmp += specifier.flags.hash;
	if (specifier.flags.zero)
		while (specifier.width > (int)ft_strlen(*str) + tmp)
			*str = ft_strjoin("0", *str);
}
