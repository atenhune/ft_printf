# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 11:38:29 by atenhune          #+#    #+#              #
#    Updated: 2022/04/20 12:28:04 by atenhune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCLUDES = ./includes/

SRC_PATH = ./src/

SRC = ft_printf.c printers.c ft_bzero.c ft_putchar.c better_ft_strnew.c \
better_ft_itoa.c \
ft_isdigit.c ft_atoi.c ft_strlen.c specifiers.c ft_memmove.c ft_memdel.c \
flag_treatment.c ft_strcpy.c float.c \
print_putnbr.c float_utils.c float_2.c wildcard.c format_reader.c catchers.c \
convertes.c printer_utils.c printers_2.c flag_treatment_2.c \
flag_treatment_3.c flag_treatment_4.c flag_treatment_5.c

all : $(NAME)

$(NAME):
	@gcc -O3 -Wall -Wextra -Werror -c $(patsubst %,$(SRC_PATH)%,$(SRC)) -I $(INCLUDES)
	@ar rc $(NAME) $(patsubst %.c,%.o,$(SRC))

clean :
	@rm -f *.o

fclean : clean
	@rm -f libftprintf.a

re : fclean all
