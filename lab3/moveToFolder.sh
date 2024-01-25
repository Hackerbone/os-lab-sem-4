#! /bin/bash


echo "Enter file extension to move for example (.txt, .exe etc.)"

read ext


files_exist=$(find ./*$ext)

if [ -z "$files_exist" ]; then
	echo "No files found!"
else
	echo "Moving to folder ${ext#.}"

	mkdir -p "./${ext#.}"

	for file_name in $files_exist; do
		echo "Moving $file_name into ./${ext#.}/${file_name}"

		mv -- "$file_name" "./${ext#.}/${file_name}"
	done

	echo "Move complete"
fi