#! /bin/bash

file_name=$1

if [ -z "./$file_name" ]; then
	echo "File not specified or does not exist"
else
	script_flags=$*

	for flag in $script_flags; do
		case $flag in
			"-linecount")
			echo "Line count: " $(wc -l < $file_name)
			;;
			"-wordcount")
			echo "Word count: " $(wc -w < $file_name)
			;;
			"-charcount")
			echo "Character count: " $(wc -m < $file_name)
			;;
			*)	
			;;
		esac
	done
fi