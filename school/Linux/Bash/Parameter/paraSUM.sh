#!/bin/bash

echo "All Parameters: $@"
echo "Amount of Parameters: $#"

sum=0
for param in "$@"; 
do
    sum=$((sum+param))
done

echo "Sum is: $sum"