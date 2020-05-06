#!/bin/bash
rm debug_linkedlist
make debug_linkedlist
make clean

./debug_linkedlist
rm debug_linkedlist
