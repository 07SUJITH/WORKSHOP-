#!/bin/bash

#simple calculator

echo "CALCULATOR"
while [ true ]
do
#  -e here enables the interpretation of backslash escapes 
	echo -e "Enter \n1 for addition\n2 for subtraction\n3 for multiplication\n4 for division\n5 for exit"
	read choice
	if [ $choice -eq 5 ]
	then
		break
		
	else
		echo "enter the number1 :"
		read num1
		echo "enter the number2 :"
		read num2
	fi
			
	case $choice in
	1) 
	 echo "sum is $(($num1 +$num2))"
	 ;;
	2)
	 echo "difference is $(($num1 - $num2))"
	 ;;
	3) 
	 echo "product  is $(($num1 * $num2))"
	 ;;
	4)
	 echo "quotient is $(($num1 / $num2))"
	 ;;
	*)
	 echo "invalid choice !"
	 ;;
	 
	esac
	
done

