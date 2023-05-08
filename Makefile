# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 10:18:10 by kkaiyawo          #+#    #+#              #
#    Updated: 2023/05/04 16:38:252y kkaiyawo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

SRCS			=	push_swap.c arg_check.c arg_format.c malloc_utils.c \
					stack_utils.c stack_utils2.c sort2.c sort3.c sort4.c \
					sort5.c sort6.c sort7.c sort8.c sort9.c sort10.c \
					stack_utils3.c
LIBS			=	libft/libft.a

SRC_DIR			=	./src/
LIB_DIR			=	./lib/
BUILD_DIR		=	./build/

SRC				=	${addprefix ${BUILD_DIR},${SRCS}}
LIB				=	${addprefix ${LIB_DIR},${LIBS}}
OBJ				=	${SRC:.c=.o}

CC				=	gcc
CFLAGS			=	-g -Wall -Wextra -Werror -O3

all:			${LIB} ${BUILD_DIR} ${NAME}

clean:
					rm -f ${OBJ}

fclean:			clean
					rm -f $(NAME)

cleanlib:
					find ${LIB_DIR} -mindepth 1 -maxdepth 1 -exec make cleanb -C {} \;

fcleanlib:
					find ${LIB_DIR} -mindepth 1 -maxdepth 1 -exec make fcleanb -C {} \;

re:				fclean all

${BUILD_DIR}:
					mkdir -p ${BUILD_DIR}

${BUILD_DIR}%.o:${SRC_DIR}%.c
						${CC} ${CFLAGS} -c -o $@ $^

${NAME}:		${OBJ}
					${CC} ${OBJ} ${wildcard ${LIB_DIR}*/*.a} -o ${NAME} ${CFLAGS}

${LIB}:
					find ${LIB_DIR} -mindepth 1 -maxdepth 1 -exec make bonus -C {} \;

.PHONY:			all clean fclean re bonus
