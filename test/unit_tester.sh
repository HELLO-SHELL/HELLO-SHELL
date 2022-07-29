#!/bin/bash/sh

cc ./built_in_unit_test.c ../src/built_in/*.c ../lib/*/*.c -o unit_test
./unit_test;