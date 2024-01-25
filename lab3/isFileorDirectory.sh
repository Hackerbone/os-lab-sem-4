#! /bin/bash

echo "Enter file name in current directory"

read file_name

echo "Checking....."

if [ -f $file_name ]; then
echo "$file_name is a normal file"
elif [ -d $file_name ];  then
echo "$file_name is a directory"
fi
