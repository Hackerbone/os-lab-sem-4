#! /bin/bash

all_files=$*

for file_name in $all_files; do
	if [ -z "$file_name" ]; then
		echo "File $file_name does not exist, cannot delete"
	else
		rm $file_name
		echo "Removed $file_name successfully"
	fi
done