#! /bin/bash

file_name=$1

if [ -e -z "$file_name" ]; then
	echo "File not specified or does not exist, cannot duplicate. Please pass in the arguments"
else
	name_of_file="${file_name%.*}"
	extension_of_file="${file_name#*.}"

	echo "Copying: $file_name to $name_of_file-duplicate.$extension_of_file"
	
	cp "$file_name" "$name_of_file-duplicate.$extension_of_file"
fi