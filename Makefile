# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 23:37:39 by gghaya            #+#    #+#              #
#    Updated: 2023/03/03 01:28:50 by gghaya           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
FLAGS =  -Wall -Werror -Wextra
CFILES = chekers.c ft_atoi.c ft_isdigit.c ft_split_copy.c \
		ft_strjoin.c ft_strlen.c  ft_substr.c parcing.c linkedlist.c\
 		 allowed_instructions3.c algorithms.c allowed_instructions.c sort.c main.c utils.c allowed_function2.c
OFILES = ${CFILES:.c=.o}

all : ${NAME}

${NAME} : ${OFILES} push_swap.h ${CFILES}
	${CC}  ${FLAGS} ${OFILES}  -o  ${NAME}

%.o:%.c push_swap.h
	${CC} -c ${FLAGS} $<

clean :
	rm -f ${OFILES}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY: clean fclean re all
