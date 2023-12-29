#!/bin/bash

#print hello world 10 times into terminal
for((i = 0;i<10;i++)) 
do
	echo "$((i+1)) hello world" #only way with varibles to do math
done



#remove old files and create new
rm -rf Notizen
mkdir "Notizen"
cd Notizen

#make new file
touch "Inhalt.txt"

#input current powerd directory into the txt file
echo "$PWD   is doing the doing" >> "Inhalt.txt"
