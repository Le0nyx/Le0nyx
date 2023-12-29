#!/bin/bash
Par1=$1
Par2=$2

echo "$1 $2"

if [ $Par1 == "-c" ]
then
    touch "$Par2"
    echo "created file: $Par2"
fi

if [ $Par1 == "-r" ]
then
    rm "$Par2"
    echo "removed file: $Par2"
fi 
