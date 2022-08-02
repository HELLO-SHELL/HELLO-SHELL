#!/bin/bash/sh

cc -lreadline ./built_in_unit_test.c ../src/built_in/*.c ../src/utils/*.c ../lib/*/*.c -o unit_test 
./unit_test;