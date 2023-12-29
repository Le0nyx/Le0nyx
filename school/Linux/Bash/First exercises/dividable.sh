#!/bin/bash

echo "Enter a num: "
read input
echo ""
counter=$input
smallest=0
while [ $counter -gt 0 ]
do
    if [ $(($counter%7)) == 0 ] && [ $(($counter%11)) == 0 ] && [ $(($counter%13)) == 0 ]
    then
        smallest=$(($counter))
        echo "num found $counter"
    fi
    ((counter=counter-1))
done
echo ""
echo "Final num found: $smallest"