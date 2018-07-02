/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 14:31:32 by ahryhory          #+#    #+#             */
/*   Updated: 2018/02/21 17:09:55 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_hash(t_specifier specifier, char **str, char type)
{
	if (type == 'x' || type == 'X')
	{
		if (specifier.flags.hash)
			*str = ft_strjoin("0x", *str);
	}
	else if (type == 'o' || type == 'O')
		if (specifier.flags.hash)
			*str = ft_strjoin("0", *str);
}
