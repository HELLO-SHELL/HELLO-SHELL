NAME = minishell

LIB_DIR = ./lib/
LIBFT = libft/libft.a
GNL = get_next_line/libgnl.a

CC = cc
# CFLAGS= -Wall -Wextra -Werror
# 아래의 brew info readline 에서 주소를 얻어와서 넣어주어야 합니다
READLINE = -lreadline -L /usr/local/Cellar/readline/8.1.2/lib -I /usr/local/Cellar/readline/8.1.2/include
#jaekim READLINE = -lreadline -L/opt/homebrew/opt/readline/lib -L/opt/homebrew/opt/readline/lib

RM = rm -f
SRC = ./src/main.c ./src/welcome/print_wallpaper.c \
./src/utils/ft_split_util.c ./src/utils/ft_split.c ./src/utils/ft_error.c \
./src/utils/env.c ./src/utils/init.c ./src/utils/is_same_string.c ./src/utils/get_token_head.c \
./src/utils/signal.c ./src/utils/safe_malloc.c \
./src/built_in/ft_exit.c ./src/built_in/ft_env.c ./src/built_in/ft_export.c\
./src/parser/make_arr_to_list.c ./src/parser/set_process_list.c ./src/temp_tester/command_list_test.c

OBJ=$(SRC:.c=.o)

$(NAME) : $(OBJ)
	make bonus -j -C $(LIB_DIR)/libft
	make -j -C $(LIB_DIR)/get_next_line
	$(CC) $(OBJ) $(READLINE) -fsanitize=address $(LIB_DIR)/$(LIBFT) $(LIB_DIR)/$(GNL) -o $(NAME)
	make -j fclean -C $(LIB_DIR)/libft
	make -j fclean -C $(LIB_DIR)/get_next_line

all : $(NAME)
	./minishell

debug :
	$(CC) src/main.c src/*/*.c -g3 lib/*/*.c -lreadline -o minishell

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re
