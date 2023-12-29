#!/bin/bash

function mul {
    echo ""
    echo "Multiplied: $Par1*$Par2= $((Par1*Par2))" 
}

function div {
    echo ""
    if [ $Par1 -eq 0 ] || [ $Par2 -eq 0 ]
    then
        echo "dividing through 0 not defined"
    else
        echo "Divided: $Par1/$Par2= $((Par1/Par2))"
    fi
}

echo "All Parameters: $@"
Par1=$1
Par2=$2
mul
div
