/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 18:33:19 by ahryhory          #+#    #+#             */
/*   Updated: 2018/02/21 17:12:07 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_flags
{
	int		minus;
	int		plus;
	int		space;
	int		hash;
	int		zero;
}					t_flags;

typedef struct		s_length
{
	int		hh;
	int		h;
	int		l;
	int		ll;
	int		j;
	int		z;
}					t_length;

typedef struct		s_specifier
{
	int			spec;
	int			neg;
	t_flags		flags;
	t_length	length;
	int			width;
	int			precision;
}					t_specifier;

int					ft_printf(const char *format, ...);
void				get_specifier(char *form, t_specifier *specifier);
int					parse(const char **format, va_list ap);
int					parse_type_c(char *form, va_list ap, char type);
int					parse_type_d_i(char *form, va_list ap, char type);
int					parse_type_o(char *form, va_list ap, char type);
int					parse_type_p(char *form, va_list ap);
int					parse_type_s(char *form, va_list ap, char type);
int					parse_type_u(char *form, va_list ap, char type);
int					parse_type_x(char *form, va_list ap, char type);
int					parse_type_proc(char *form, char type);
char				*ft_itoa_base(uintmax_t num, int base);
char				*to_up_case(char *str);
int					ft_putwchar(unsigned int c);
void				flag_sign(t_specifier specifier, char **str);
void				width(t_specifier specifier, char **str);
void				flag_space(t_specifier specifier, char **str);
void				flag_zero(t_specifier specifier, char **str, char type);
void				precision(t_specifier specifier, char **str, char type);
void				flag_hash(t_specifier specifier, char **str, char type);
int					get_count_bytes(unsigned int c);
wchar_t				*ft_wstrsub(wchar_t const *s, unsigned int start,
								size_t len);
int					precision_wchar(int precision, wchar_t *wstr);
int					parse_type_s_null(t_specifier specifier);

#endif
