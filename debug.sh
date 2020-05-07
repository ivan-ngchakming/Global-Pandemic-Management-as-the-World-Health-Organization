#!/bin/bash
rm debug_infection_rate_calculator
make debug_infection_rate_calculator
make clean

./debug_infection_rate_calculator < debug_infection_rate_calculator.txt
rm debug_infection_rate_calculator
