# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 10:18:10 by kkaiyawo          #+#    #+#              #
#    Updated: 2023/04/30 22:38:06 by kkaiyawo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

SRCS			=	push_swap.c stack_main.c stack_utils.c arg_check.c mini_push_swap.c

SRC_DIR			=	./src/
LIB_DIR			=	./lib/
BUILD_DIR		=	./build/

SRC				=	${addprefix ${BUILD_DIR},${SRCS}}
OBJ				=	${SRC:.c=.o}

CC				=	gcc
CFLAG			=	-g -Wall -Wextra -Werror -O3

all:			library ${BUILD_DIR} ${NAME}

library:
					find ${LIB_DIR} -mindepth 1 -maxdepth 1 -exec make bonus -C {} \;

clean:
					rm -f ${OBJ}

fclean:			clean
					rm -f $(NAME)

re:				fclean all

${BUILD_DIR}:
					mkdir -p ${BUILD_DIR}

${BUILD_DIR}%.o:${SRC_DIR}%.c
						${CC} -c -o $@ $^

${NAME}:		${OBJ}
					${CC} ${OBJ} ${wildcard ${LIB_DIR}*/*.a} -o ${NAME} ${CFLAG}

.PHONY:			all clean fclean re bonus
