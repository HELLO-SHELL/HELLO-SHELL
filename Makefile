NAME = minishell
LIB_DIR = ./lib/
LIBFT = libft/libft.a
GNL = get_next_line/libgnl.a
CC = cc
CFLAGS= -Wall -Wextra -Werror

# readline 경로를 아키텍쳐 별로 변경하는 코드. M1 Mac, Cluster Mac, arm Linux 환경 대응
detected_OS := $(shell uname -sm)
ifeq ($(detected_OS), Linux aarch64)
LINKING_FLAGS = -lreadline
else ifeq ($(detected_OS), Darwin x86_64)
LINKING_FLAGS = -lreadline -L ${HOME}/.brew/opt/readline/lib
COMFILE_FLAGS = -I ${HOME}/.brew/opt/readline/include
else ifeq ($(detected_OS), Darwin arm64)
LINKING_FLAGS = -lreadline -L /opt/homebrew/opt/readline/lib
COMFILE_FLAGS = -I /opt/homebrew/opt/readline/include
endif

RM = rm -rf

MAIN_SRCS = src/main.c src/welcome/print_wallpaper.c src/init.c
MAIN_OBJS = $(MAIN_SRCS:.c=.o)

UTILS_DIR = src/utils/
UTILS_SRCS = env_utils/env_utils.c env_utils/env_key_valid_checker.c env_utils/get_env_by_key.c \
	  env_utils/make_node_to_envp.c  \
	  built_in_utils/cd_utils.c \
	  replace_dollar/replace_dollar.c replace_dollar/replace_dollar_append_utils.c replace_dollar/replace_dollar_len_utils.c \
	  chore_utils/is_same_string.c chore_utils/safe_malloc.c  \
	  free_utils/free_utils.c \
	  signal.c get_token_head.c ft_error.c word_check.c
UTILS_PATH = $(addprefix $(UTILS_DIR), $(UTILS_SRCS))
UTILS_OBJS = $(UTILS_PATH:.c=.o)

BUILT_IN_DIR = src/built_in/
BUILT_IN_SRCS = ft_exit.c ft_env.c ft_export.c ft_cd.c ft_pwd.c ft_unset.c ft_echo.c
BUILT_IN_PATH = $(addprefix $(BUILT_IN_DIR), $(BUILT_IN_SRCS))
BUILT_IN_OBJS = $(BUILT_IN_PATH:.c=.o)

PARSER_DIR = src/parser/
PARSER_SRCS = make_arr_to_list.c set_process_list.c  process_list_utils.c process_utils.c \
	split/ft_split_util.c split/ft_split.c split/ft_split_quote_util.c
PARSER_PATH = $(addprefix $(PARSER_DIR), $(PARSER_SRCS))
PARSER_OBJS = $(PARSER_PATH:.c=.o)

EXECUTOR_DIR = src/executor/
EXECUTOR_SRCS = executor.c heredoc.c is_func.c pipe.c redirect.c safe_func.c wait.c
EXECUTOR_PATH = $(addprefix $(EXECUTOR_DIR), $(EXECUTOR_SRCS))
EXECUTOR_OBJS = $(EXECUTOR_PATH:.c=.o)
OBJS = $(READLINE_OBJS) $(MAIN_OBJS) $(BUILT_IN_OBJS) $(PARSER_OBJS) $(UTILS_OBJS) $(EXECUTOR_OBJS)

$(NAME) : $(OBJS)
	make bonus -j -C $(LIB_DIR)/libft
	make -j -C $(LIB_DIR)/get_next_line
	$(CC) $(CFLAGS) $(OBJS) $(LINKING_FLAGS) $(LIB_DIR)/$(LIBFT) $(LIB_DIR)/$(GNL) -o $(NAME)
	make -j fclean -C $(LIB_DIR)/libft
	make -j fclean -C $(LIB_DIR)/get_next_line
#  -fsanitize=address
all : $(NAME)
	./minishell

debug :
	$(CC) src/*.c src/**/*.c src/**/**/*.c -g3 lib/*/*.c $(COMFILE_FLAGS) $(LINKING_FLAGS) -o minishell

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
	$(RM) minishell.dSYM

re :
	make fclean
	make all

%.o :   %.c
	$(CC) -c $^ $(COMFILE_FLAGS) -o $@

.PHONY : all clean fclean re
