# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjo <jjo@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/16 15:46:44 by jjo               #+#    #+#              #
#    Updated: 2020/03/16 15:46:44 by jjo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= factorization

CC	= gcc

SRCS		= factorization.c

OBJS		= $(SRCS:.c=.o)

FLAGS		= -Wall -Wextra -Werror

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} ${INCS}

$(NAME): ${OBJS}
	gcc ${OBJS} ${FLAGS} -o ${NAME}

all: $(NAME)

fclean: clean
	rm -f $(NAME)

clean:
	rm -f -f $(OBJS)

re: fclean all

