#!/bin/bash
cd "$(dirname $0)"

make -C ../submit

cc main.c ../submit/libftprintf.a -I ../submit
