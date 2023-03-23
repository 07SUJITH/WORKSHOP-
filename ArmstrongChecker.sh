#!/bin/bash

function isArmstrong(){
	number=$1
	len=${#number}
	checker=0
	duplicate=$number
	while [ $number -gt 0 ]
	do
		remainder=$((number%10))
		checker=$( echo " $checker + $remainder^$len" | bc)
		number=$((number/10))
	done
	if [ $checker -eq $duplicate ]
	then
		return 1
	else
		return 0
	fi
}

function main(){
	read -p "Enter a number : " number
	isArmstrong  $number
	if [ $? -eq 1 ]
	then
		echo "Number is armstrong"
	else
		echo "Number is not armstrong"
	fi
}

main
