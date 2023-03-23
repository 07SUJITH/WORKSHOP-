#!/bin/bash

# Palindrome checker for number

function isPalindrome(){

	number=$1
	duplicate=$number
	reversed=0
	while [ $number -gt 0 ]
	do
		remainder=$(($number % 10))
		reversed=$( echo " $reversed*10 + $remainder " | bc)
		number=$((number / 10))
	done

	if [ $duplicate -eq  $reversed ]
	then
		return 1
	else
		return 0
	fi
}

function main(){
	read -p "Enter a number :"  num
	isPalindrome $num
	if [ $? -eq 1 ]
	then
		echo "Number is palindrome"
	else
		echo "Number is not palindrome"
	fi

}
main


