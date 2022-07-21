NAME = minishell

LIB_DIR = ./lib/libft
LIBFT = libft.a

CC = cc
CFLAGS= -Wall -Wextra -Werror

RM = rm -f
SRC = ./src/main.c \
	  ./src/utils/env.c \
	  ./src/utils/init.c
	
OBJ=$(SRC:.c=.o)

$(NAME) : $(OBJ)
	make -C $(LIB_DIR) bonus
	$(CC) -lreadline -fsanitize=address $(CFLAGS) $(LIB_DIR)/$(LIBFT) $(OBJ) -o $(NAME)
	make fclean -C $(LIB_DIR)

all : $(NAME)
	./minishell

clean :
	$(RM) $(OBJ)

fclean : clean
	make -C $(LIB_DIR) fclean
	$(RM) $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re
