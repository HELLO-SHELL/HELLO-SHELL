NAME = minishell

LIB_DIR = ./lib/
LIBFT = libft/libft.a
GNL = get_next_line/libgnl.a

CC = cc
# CFLAGS= -Wall -Wextra -Werror

RM = rm -f
SRC = ./src/main.c ./src/welcome/print_wallpaper.c ./src/utils/ft_split_util.c \
./src/utils/ft_split.c ./src/utils/ft_strcpm.c ./src/parser/make_arr_to_list.c
	
OBJ=$(SRC:.c=.o)

$(NAME) : $(OBJ)
	make -C $(LIB_DIR)/libft
	make -C $(LIB_DIR)/get_next_line
	$(CC) -lreadline -fsanitize=address $(LIB_DIR)/$(LIBFT) $(LIB_DIR)/$(GNL) $(OBJ) -o $(NAME)
	make fclean -C $(LIB_DIR)/libft
	make fclean -C $(LIB_DIR)/get_next_line

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
