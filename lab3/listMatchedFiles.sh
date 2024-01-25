#! /bin/bash

echo "Enter a file to search/list"

read file_name

echo `ls | grep $file_name`