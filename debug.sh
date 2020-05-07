#!/bin/bash
rm debug_performance_index
make debug_performance_index
make clean

./debug_performance_index < debug_performance_index.txt
rm debug_performance_index
