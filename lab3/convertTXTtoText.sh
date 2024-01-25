#! /bin/bash

echo "Finding all .txt files and renaming them to .text"

for file_name in $(find *.txt); do
	echo "Converting $file_name into .text"

	mv -- "$file_name" "${file_name%.txt}.text"
done

echo "Conversion successful!"