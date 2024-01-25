#! /bin/bash


echo "Replacing first occurence of ex to Example in current text files"

files_exist=$(find ./*.txt)

if [ -z "$files_exist" ]; then
	echo "No files found!"
else
	for file_name in $files_exist; do
		echo "Updating $file_name"

		sed -i -e 's/ex/Example/' $file_name

		echo "Update complete"
	done
fi