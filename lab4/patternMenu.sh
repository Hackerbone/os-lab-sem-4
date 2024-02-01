#! /bin/bash

file_name=$1
pattern=$2

if [ -z $pattern ]; then
	echo "Pattern argument not specified. USAGE: ./patternMenu.sh [file_name] [pattern]"
	exit 1
fi


if [ -z $file_name ]; then
	echo "File name argument not specified. USAGE: ./patternMenu.sh [file_name] [pattern]"
	exit 1
fi


exit_script=0 # Stay in menu if this is 0

echo $'Welcome to pattern menu\nChoose options:'
while (( $exit_script == 0 )); do
	echo "1] Search the pattern $pattern in file $file_name"
	echo "2] Delete the pattern $pattern in file $file_name"
	echo '3] Exit Menu'
	echo 'Enter 1, 2, 3 for respective menus'
	read option

	case $option in
		"1")
		if [[ -z $(cat $file_name | grep $pattern) ]]; then
			echo $'No matching lines found\n'
		else 
			echo "Line(s) found:"
			echo $(cat $file_name | grep $pattern)
			echo $'\n'
		fi
		;;
		"2")
			sed -i -e "s/$pattern//g" $file_name
			echo "Pattern $pattern deleted in file $file_name"
		;;
		"3")
		echo "Bye Bye"
		exit_script=1
	esac
done
