#!/bin/bash
# Palindrome checker for string

isPalindrome() {

	str=$1
	len=${#str}
	count=$(($len - 1 ))
	reversed=""
	while [ $count -ge 0 ]
	do
		reversed="$reversed${str:$count:1}"
		((count--))
	done
	if [ $reversed ==  $str ]
	then 
		return 1
	else
		return 0
	fi

}


main(){

	echo -n "Enter a string :"
	read string
	isPalindrome "$string"

	if [ $? -eq 1 ]
	then
		echo "String is Palindrome"
	else
		echo "String is not Palindrome"
	fi

}

main
