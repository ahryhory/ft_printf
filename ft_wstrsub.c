/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:06:42 by ahryhory          #+#    #+#             */
/*   Updated: 2018/02/18 15:27:12 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wstrsub(wchar_t const *s, unsigned int start, size_t len)
{
	wchar_t	*sub;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	sub = (wchar_t *)ft_memalloc(sizeof(wchar_t) * (len + 1));
	if (sub == NULL)
		return (NULL);
	while (i < (int)len)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
