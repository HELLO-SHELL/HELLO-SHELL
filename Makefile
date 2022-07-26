NAME = minishell

LIB_DIR = ./lib/
LIBFT = libft/libft.a
GNL = get_next_line/libgnl.a

CC = cc
# CFLAGS= -Wall -Wextra -Werror

RM = rm -f
SRC = ./src/main.c ./src/welcome/print_wallpaper.c \
./src/utils/ft_split_util.c ./src/utils/ft_split.c ./src/utils/ft_strcmp.c \
./src/utils/env.c ./src/utils/init.c ./src/utils/is_same_string.c ./src/utils/get_token_head.c \
./src/built_in/ft_exit.c ./src/built_in/ft_env.c \
./src/parser/make_arr_to_list.c

OBJ=$(SRC:.c=.o)

$(NAME) : $(OBJ)
	make bonus -j -C $(LIB_DIR)/libft
	make -j -C $(LIB_DIR)/get_next_line
	$(CC) $(OBJ) -lreadline -fsanitize=address $(LIB_DIR)/$(LIBFT) $(LIB_DIR)/$(GNL) -o $(NAME)
	make -j fclean -C $(LIB_DIR)/libft
	make -j fclean -C $(LIB_DIR)/get_next_line

all : $(NAME)
	./minishell

debug :
	$(CC) src/main.c src/*/*.c -g3 lib/*/*.c -lreadline -g3 -o minishell

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re
