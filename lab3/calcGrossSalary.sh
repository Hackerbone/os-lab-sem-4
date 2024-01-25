#! /bin/bash

echo "Enter your Basic Salary"

read basic_salary

echo "Enter your TA"

read ta

gross_salary=`bc <<< $basic_salary+$ta+$basic_salary*0.1` 

echo "Your Gross Salary is : $gross_salary" 