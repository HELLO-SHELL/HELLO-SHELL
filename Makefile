NAME = minishell
LIB_DIR = ./lib/
LIBFT = libft/libft.a
GNL = get_next_line/libgnl.a
CC = cc
# CFLAGS= -Wall -Wextra -Werror
# 아래의 brew info readline 에서 주소를 얻어와서 넣어주어야 합니다

READLINE = -lreadline -L ${HOME}/.brew/opt/readline/lib -I ${HOME}/.brew/opt/readline/include
RM = rm -f

MAIN_SRCS = src/main.c src/welcome/print_wallpaper.c
MAIN_OBJS = $(MAIN_SRCS:.c=.o)

UTILS_DIR = src/utils/
UTILS_SRCS = ft_split_util.c ft_split.c ft_split_quote_util.c ft_error.c \
      env.c init.c signal.c is_same_string.c get_token_head.c \
      safe_malloc.c get_env_by_key.c
UTILS_PATH = $(addprefix $(UTILS_DIR), $(UTILS_SRCS))
UTILS_OBJS = $(UTILS_PATH:.c=.o)

BUILT_IN_DIR = src/built_in/
BUILT_IN_SRCS = ft_exit.c ft_env.c ft_export.c
BUILT_IN_PATH = $(addprefix $(BUILT_IN_DIR), $(BUILT_IN_SRCS))
BUILT_IN_OBJS = $(BUILT_IN_PATH:.c=.o)

PARSER_DIR = src/parser/
PARSER_SRCS = make_arr_to_list.c set_process_list.c  process_list_utils.c process_utils.c
PARSER_PATH = $(addprefix $(PARSER_DIR), $(PARSER_SRCS))
PARSER_OBJS = $(PARSER_PATH:.c=.o)

OBJS = $(READLINE_OBJS) $(MAIN_OBJS) $(BUILT_IN_OBJS) $(PARSER_OBJS) $(UTILS_OBJS) 

$(NAME) : $(OBJS)
	make bonus -j -C $(LIB_DIR)/libft
	make -j -C $(LIB_DIR)/get_next_line
	$(CC) $(OBJS) $(READLINE) -fsanitize=address $(LIB_DIR)/$(LIBFT) $(LIB_DIR)/$(GNL) -o $(NAME)
	make -j fclean -C $(LIB_DIR)/libft
	make -j fclean -C $(LIB_DIR)/get_next_line

all : $(NAME)
	./minishell

debug :
	$(CC) src/*.c src/**/*.c src/**/**/*.c -g3 lib/*/*.c -lreadline -o minishell

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

%.o :   %.c
	$(CC) $(READLINE) -c $^ -o $@

.PHONY : all clean fclean re
