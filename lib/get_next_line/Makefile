# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongyle <seongyle@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/14 16:53:07 by kyungsle          #+#    #+#              #
#    Updated: 2022/07/20 16:54:13 by seongyle         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror
LIBC	= ar rc
NAME	= libgnl.a
SRCS	= get_next_line.c get_next_line_utils.c
OBJS	= $(SRCS:.c=.o)


%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ_FILES)
	$(LIBC) $(NAME) $(OBJ_FILES)
	$(LIBR) $(NAME)

all: $(NAME)

clean:
	$(RM) ${OBJS} ${OBJSB}

fclean: clean
	$(RM) $(NAME)

re: 
	make fclean
	make all

.PHONY: all bonus clean fclean re
