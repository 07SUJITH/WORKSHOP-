#!/bin/bash

function isPrime(){

	num=$1
	if [ $num -lt 2 ]
	then 
		return 0
	fi
	flag=1
	for((i=2;i<=$((num/2));i++))
	do
		if [  $((num%2)) -eq 0 ]
		then
			flag=0
			break
		fi
	done
	return $flag	
}

main(){
	read -p "enter a number : " number
	isPrime $number
	if [ $? -eq 1 ]
	then
		echo "number is prime "
	else
		echo "number is not prime"
	fi
	
}

main
