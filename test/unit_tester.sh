#!/bin/bash/sh

cc -lreadline -L ${HOME}/.brew/opt/readline/lib -I ${HOME}/.brew/opt/readline/include ./built_in_unit_test.c ../src/built_in/ft_echo.c ../src/utils/*.c ../src/parser/split/*.c ../src/utils/chore_utils/safe_malloc.c ../lib/*/*.c -g3 -o unit_test
./unit_test;
