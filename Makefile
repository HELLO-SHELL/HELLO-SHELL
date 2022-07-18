NAME=minishell

CC=cc
CFLAGS= -Wall -Wextra -Werror

RM=rm -f
CP=cp
SRC= ./src/main.c
	
OBJ=$(SRC:.c=.o)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all : $(NAME)
	./minishell

clean :
	$(RM) $(OBJ)

fclean : fclean
	$(RM) $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re
