#!/bin/bash

echo "This program calculates the factorial of a number."
echo "Enter a number: "
read input

result=1
for ((i = 1; i <= input; i++))
do
    result=$((result * i))
done

echo "The factorial of $input is: $result"