/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 13:50:04 by ahryhory          #+#    #+#             */
/*   Updated: 2018/02/21 17:10:21 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	precision(t_specifier specifier, char **str, char type)
{
	int		tmp;

	tmp = 0;
	if (type == 'u')
		tmp = specifier.flags.hash;
	else if (type == 'o' || type == 'O')
		tmp = specifier.flags.hash;
	if (specifier.precision > 0)
		while (specifier.precision > (int)ft_strlen(*str) + tmp)
			*str = ft_strjoin("0", *str);
}
