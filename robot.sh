#!/bin/bash
rm main
make main
make clean

./main
rm main
