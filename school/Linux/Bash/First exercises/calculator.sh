#!/bin/bash

echo "This is a calculator" 

#input values and stuff
echo "Enter value 1: "
read input1 
echo "Enter value 2: "
read input2

echo ""
echo ""
echo "Num1 = $input1 and Num2 = $input2"
echo ""
echo "[1] Addition       (num1+num2)"
echo "[2] Subtraction    (num1-num2)"
echo "[3] Multiplication (num1*num2)"
echo "[4] Division       (num1/num2)"
echo "[5] Exponential    (num1^num2)"
echo ""
echo "Choose what you want to do: "
read chosen
echo ""

#calculations
if [ $chosen = 1 ] #addition
then
	echo "Result of $input1 + $input2 = $(($input1 + $input2))"
fi


if [ $chosen = 2 ] #subtraction
then
	echo "Result of $input1 - $input2 = $(($input1 - $input2))"
fi


if [ $chosen = 3 ] #multiplication
then
	echo "Result of $input1 * $input2 = $(($input1 * $input2))"
fi


if [ $chosen = 4 ] #division
then
	echo "Result of $input1 / $input2 = $(($input1 / $input2)) (this won't give you comma numbers)"
fi

result=$input1
if [ $chosen = 5 ] # exponential
then
    for((i=1; i<$input2; i++))
    do
        result=$(($result * $input1))
    done
    echo "Result of $input1 ^ $input2 = $result"
fi