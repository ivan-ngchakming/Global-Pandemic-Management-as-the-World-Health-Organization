#!/bin/bash

make debug_load_save
make clean
./debug_load_save < robot.txt

rm debug_load_save
rm temp.txt
