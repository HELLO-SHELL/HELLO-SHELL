NAME = minishell

LIB_DIR = ./lib/
LIBFT = libft/libft.a
GNL = get_next_line/libgnl.a

CC = cc
# CFLAGS= -Wall -Wextra -Werror
# 아래의 brew info readline 에서 주소를 얻어와서 넣어주어야 합니다
READLINE = -lreadline -L ${HOME}/.brew/opt/readline/lib -I ${HOME}/.brew/opt/readline/include
RM = rm -f
SRC = ./src/main.c ./src/welcome/print_wallpaper.c \
./src/utils/ft_split_util.c ./src/utils/ft_split.c ./src/utils/ft_error.c \
./src/utils/env_utils/env.c ./src/init.c ./src/utils/chore_utils/is_same_string.c ./src/utils/get_token_head.c \
./src/utils/signal.c ./src/utils/chore_utils/safe_malloc.c ./src/utils/chore_utils/ft_memccpy.c ./src/utils/env_utils/get_env_by_key.c\
./src/utils/env_utils/env_key_valid_chechker.c\
./src/built_in/ft_exit.c ./src/built_in/ft_env.c ./src/built_in/ft_export.c\
./src/parser/make_arr_to_list.c ./src/parser/set_process_list.c  ./src/parser/process_list_utils.c \
./src/parser/process_utils.c \
./src/temp_tester/command_list_test.c

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

%.o :	%.c
	$(CC) $(READLINE) -c $^ -o $@

.PHONY : all clean fclean re
