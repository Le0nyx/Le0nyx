#!/bin/bash

Par1=$1
Par2=$2
echo "Idk man1: $Par1"
echo "Ig2: $Par2"
echo "Existing Pars: $# and they are: $@"
echo ""
echo "Summe: $((Par1 + Par2))"
echo "Mul: $((Par1 * Par2))"

if [ $Par1 -ge $Par2 ]
then
    echo "Par1 Is greater: $Par1"
else
    echo "Par2 is greater: $Par2"
fi