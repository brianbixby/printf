# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbixby <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/10 06:48:25 by bbixby            #+#    #+#              #
#    Updated: 2018/11/10 06:48:27 by bbixby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -c -Wall -Werror -Wextra
HEADER = ft_printf.h
CFILES = ./ft_printf.c ./ft_print.c ./ft_helpers.c ./ft_wchar.c ./ft_print_s.c ./ft_print_c.c ./ft_print_unsigned.c ./ft_print_signed.c ./ft_print_p.c ./ft_print_f.c
OFILES	= $(CFILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

$(OFILES): $(CFILES)
	gcc $(CFLAGS) -I=$(HEADER) $(CFILES)

clean:
	/bin/rm -f $(OFILES)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
