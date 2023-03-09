# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 23:37:39 by gghaya            #+#    #+#              #
#    Updated: 2023/03/08 22:41:23 by gghaya           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAMEB = checker
CC = cc
FLAGS =  -Wall -Werror -Wextra
CFILES = chekers.c ft_atoi.c ft_isdigit.c ft_split_copy.c fctsupplimentaires.c \
		ft_strjoin.c ft_strlen.c  ft_substr.c parcing.c linkedlist.c\
		allowed_instructions3.c algorithms.c allowed_instructions.c sort.c main.c utils.c allowed_function2.c\

B = chekers.c ft_atoi.c ft_isdigit.c ft_split_copy.c fctsupplimentaires.c\
		ft_strjoin.c ft_strlen.c bonus.c ft_substr.c parcing.c linkedlist.c\
		allowed_instructions3.c algorithms.c allowed_instructions.c sort.c utils.c allowed_function2.c get_next_line_utils.c get_next_line.c mainb.c\

OFILES = ${CFILES:.c=.o}
O = ${B:.c=.o}

all : ${NAME}

bonus : ${NAMEB}

${NAME} : ${OFILES} push_swap.h ${CFILES}
	${CC}  ${FLAGS} ${OFILES}  -o  ${NAME}

${NAMEB} : ${O} push_swap.h ${B}
	${CC}  ${FLAGS} ${O}  -o  ${NAMEB}

%.o:%.c push_swap.h
	${CC} -c ${FLAGS} $<

clean :
	rm -f ${OFILES}
	rm -f ${O}

fclean : clean
	rm -f ${NAME}
	rm -f  $(NAMEB)

re : fclean all

.PHONY: clean fclean re all bonus
