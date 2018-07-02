/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_up_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:02:49 by ahryhory          #+#    #+#             */
/*   Updated: 2018/02/15 12:12:44 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*to_up_case(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}