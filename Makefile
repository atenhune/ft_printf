# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antti <antti@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 11:38:29 by atenhune          #+#    #+#              #
#    Updated: 2022/03/30 16:38:57 by antti            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCLUDES = ft_printf.h

SRC = ft_printf.c printers.c ft_bzero.c ft_putchar.c ft_strnew.c ft_itoa.c \
ft_isdigit.c ft_atoi.c ft_strlen.c specifiers.c ft_memmove.c ft_memdel.c \
flag_treatment.c ft_strdup.c ft_strcpy.c ft_putstr.c float.c ft_strcat.c \
ft_putnbr.c float_utils.c

all : $(NAME)

$(NAME):
	@gcc -O3 -Wall -Wextra -Werror -c $(SRC) -I $(INCLUDES)
	@ar rc $(NAME) $(patsubst %.c,%.o,$(SRC))

clean :
	@rm -f *.o

fclean : clean
	@rm -f libftprintf.a

re : fclean all
	@gcc main.c libftprintf.a
	@./a.out > vastaus
	@./a.out