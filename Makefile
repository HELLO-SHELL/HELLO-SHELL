NAME=minishell

CC = cc
# CFLAGS= -Wall -Wextra -Werror

RM = rm -f
SRC = ./src/main.c
	
OBJ=$(SRC:.c=.o)

$(NAME) : $(OBJ)
	$(CC) -lreadline -fsanitize=address $(OBJ) -o $(NAME)

all : $(NAME)
	./minishell

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re
