#!/bin/bash/sh

cc -lreadline ./built_in_unit_test.c ../src/built_in/ft_pwd.c -o unit_test
./unit_test;
#  ../src/utils/*.c ../lib/*/*.c