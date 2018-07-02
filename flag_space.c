/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 14:16:47 by ahryhory          #+#    #+#             */
/*   Updated: 2018/02/21 17:10:03 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_space(t_specifier specifier, char **str)
{
	if (specifier.flags.space && (int)ft_strlen(*str) >= specifier.width)
		*str = ft_strjoin(" ", *str);
}
