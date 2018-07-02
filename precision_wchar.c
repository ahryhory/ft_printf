/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_wchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:16:21 by ahryhory          #+#    #+#             */
/*   Updated: 2018/02/21 14:48:38 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		precision_wchar(int precision, wchar_t *wstr)
{
	int		new_precision;

	new_precision = 0;
	while (*wstr)
	{
		if ((precision -= get_count_bytes(*wstr)) >= 0)
			new_precision++;
		wstr++;
	}
	return (new_precision);
}
