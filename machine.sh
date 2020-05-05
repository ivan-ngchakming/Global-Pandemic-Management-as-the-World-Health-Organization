#!/bin/bash

make encryptionmachine
make clean

./encryptionmachine < english_init.txt
rm encryptionmachine
