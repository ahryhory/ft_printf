/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_sign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 13:50:45 by ahryhory          #+#    #+#             */
/*   Updated: 2018/02/21 17:09:42 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_sign(t_specifier specifier, char **str)
{
	if (specifier.flags.plus)
		*str = ft_strjoin("+", *str);
	else if (specifier.neg)
		*str = ft_strjoin("-", *str);
}
