/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 13:51:21 by ahryhory          #+#    #+#             */
/*   Updated: 2018/02/21 17:09:26 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	width(t_specifier specifier, char **str)
{
	if (!specifier.flags.minus)
		while (specifier.width > (int)ft_strlen(*str))
			*str = ft_strjoin(" ", *str);
	else
		while (specifier.width > (int)ft_strlen(*str))
			*str = ft_strjoin(*str, " ");
}
