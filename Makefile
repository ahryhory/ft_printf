# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/26 12:22:07 by ahryhory          #+#    #+#              #
#    Updated: 2018/02/21 17:05:37 by ahryhory         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

SRC =

SRC += ft_printf.c
SRC += parse.c
SRC += get_specifier.c
SRC += parse_type_s_null.c
SRC += parse_type_c.c
SRC += parse_type_d_i.c
SRC += parse_type_o.c
SRC += parse_type_p.c
SRC += parse_type_s.c
SRC += parse_type_u.c
SRC += ft_putwchar.c
SRC += parse_type_x.c
SRC += parse_type_proc.c
SRC += get_count_bytes.c
SRC += flag_sign.c
SRC += width.c
SRC += ft_wstrsub.c
SRC += flag_space.c
SRC += flag_zero.c
SRC += precision.c
SRC += flag_hash.c
SRC += to_up_case.c
SRC += precision_wchar.c
SRC += ft_itoa_base.c
SRC += ft_strcat.c
SRC += ft_strcmp.c
SRC += ft_strdup.c
SRC += ft_striteri.c
SRC += ft_strlen.c
SRC += ft_strncat.c
SRC += ft_strnequ.c
SRC += ft_strsplit.c
SRC += ft_strtrim.c
SRC += ft_strchr.c
SRC += ft_strcpy.c
SRC += ft_strequ.c
SRC += ft_strjoin.c
SRC += ft_strmap.c
SRC += ft_strncmp.c
SRC += ft_strnew.c
SRC += ft_strstr.c
SRC += ft_strnstr.c
SRC += ft_strclr.c
SRC += ft_strdel.c
SRC += ft_striter.c
SRC += ft_strlcat.c
SRC += ft_strmapi.c
SRC += ft_strncpy.c
SRC += ft_strrchr.c
SRC += ft_strsub.c
SRC += ft_isascii.c
SRC += ft_isdigit.c
SRC += ft_isprint.c
SRC += ft_isalpha.c
SRC += ft_toupper.c
SRC += ft_tolower.c
SRC += ft_atoi.c
SRC += ft_itoa.c
SRC += ft_bzero.c
SRC += ft_isalnum.c
SRC += ft_putchar.c
SRC += ft_putchar_fd.c
SRC += ft_putendl.c
SRC += ft_putendl_fd.c
SRC += ft_putnbr.c
SRC += ft_putnbr_fd.c
SRC += ft_putstr.c
SRC += ft_putstr_fd.c
SRC += ft_memalloc.c
SRC += ft_memccpy.c
SRC += ft_memchr.c
SRC += ft_memcmp.c
SRC += ft_memcpy.c
SRC += ft_memdel.c
SRC += ft_memmove.c
SRC += ft_memset.c
SRC += ft_lstnew.c
SRC += ft_lstdelone.c
SRC += ft_lstdel.c
SRC += ft_lstadd.c
SRC += ft_lstiter.c
SRC += ft_lstmap.c
SRC += ft_get_next_line.c

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c
	@gcc $(FLAGS) -I. -c $<

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
