#!/bin/bash/sh


cc -lreadline ./utils_fun_unit_test.c ../src/*/*.c ../lib/*/*.c -lreadline -o unit_test
./unit_test;