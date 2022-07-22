# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongyle <seongyle@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/14 16:53:07 by kyungsle          #+#    #+#              #
#    Updated: 2022/07/21 12:25:37 by seongyle         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC		= cc
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror
AR		= ar
ARFLAGS = rscu

NAME	= libgnl.a

SRCS	= get_next_line.c get_next_line_utils.c
OBJS	= $(SRCS:.c=.o)


%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) ${OBJS} 

fclean: clean
	$(RM) $(NAME)

re: 
	make fclean
	make all

.PHONY: all bonus clean fclean re
