# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saciurus <saciurus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 16:05:59 by saciurus          #+#    #+#              #
#    Updated: 2025/01/24 16:43:21 by saciurus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRINTF = ft_printc.c ft_prints.c ft_printd.c ft_printu.c ft_printp.c ft_printx.c ft_printxx.c ft_printf.c ft_len_tab.c

OBJ = $(PRINTF:.c=.o)

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -I.

all: ${NAME}

${NAME}: ${OBJ}
	ar rcs ${NAME} ${OBJ}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: re clean fclean all