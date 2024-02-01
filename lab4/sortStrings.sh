#! /bin/bash

all_strings=("$@")

num_of_strings=${#all_strings[@]}

echo $num_of_strings


for (( i=0; i<num_of_strings-1; i++)); do
	
	min_string=$all_strings[$i]
	for(( j=i+1; j<n; j++ )); do
		if [[ $all_strings[$j] < $all_strings[$((j+1))] ]]