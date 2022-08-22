#!/bin/bash/sh

# cc -lreadline -L /Users/jaekim/.brew/opt/readline/lib -I /Users/jaekim/.brew/opt/readline/include ./built_in_unit_test.c ../src/init.c ../src/built_in/*.c ../src/utils/*.c ../src/executor/*.c ../src/parser/*.c ../src/welcome/*.c ../lib/*/*.c -o unit_test
cc -lreadline -L /Users/jaekim/.brew/opt/readline/lib -I /Users/jaekim/.brew/opt/readline/include ./built_in_unit_test.c ../src/built_in/ft_echo.c ../src/utils/*.c ../src/parser/split/*.c ../src/utils/chore_utils/safe_malloc.c ../lib/*/*.c -g3 -o unit_test
./unit_test;