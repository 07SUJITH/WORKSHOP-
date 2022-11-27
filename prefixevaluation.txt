#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
# define MAX 100
char prefix[100] ,infix[100];
int stack[MAX];
int top=-1;
void reverse(char str[], int index,int size){
	char temp=str[index];
	str[index]=str[size-index];
	str[size-index]=temp;
	if(index==size/2)
		return;
	reverse(str,index+1,size);
}
int pop(){
	if(top==-1){
	printf("stack underflow");
	exit(1);
	}
	return stack[top--];
}
void push(int value){
	if(top==MAX-1){
		printf("stack overflow  ");
		exit(1);
	}
	 stack[++top]=value;
}
int precedence(char symbol){
	switch(symbol){
	case '^': return 3;
	case '*':
	case '/': return 2;
	case '+':
	case '-': return 1;
	default : return 0;
	}
}
int isEmpty(){
	if(top==-1)
		return 1;
	else 
		return 0;
}
void infixToPrefix(){
	int j=0;
	char next,symbol;
	reverse(infix,0,strlen(infix)-1);
	for(int i=0;i<strlen(infix);i++){
	symbol=infix[i];
	switch(symbol){	
	case ')': push(symbol);break;
	case '(': while((next=pop())!=')')
			prefix[j++]=next;
		  break;
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':
		 while(!isEmpty() && (precedence(symbol)<precedence(stack[top]))){
			prefix[j++]=pop();
		 }		
		 push(symbol); break;
	default :prefix[j++]=symbol;
	}
	}
	while(!isEmpty())
		prefix[j++]=pop();
	prefix[j]='\0';
	reverse(prefix,0,strlen(prefix)-1);
}
int prefixEvaluation(){
	int op1,op2;
	char ch;
	for(int i=strlen(prefix)-1;i>=0;i--){
		ch=prefix[i];
		if(ch>='0'&&ch<='9'){
			push(ch-'0');
			continue;
		}
		op1=pop();
		op2=pop();
		switch(ch){
		case '+':push(op1+op2); break;
		case '-':push(op1-op2); break;
		case '*':push(op1*op2);break;
		case '/':push(op1/op2);break;
		case '^':push(pow(op1,op2)); break;
		}
	}
	return pop() ;
}
void printArray(char arr[]){
	int i=0;
	while(arr[i])
		printf("%c",arr[i++]);
	printf("\n");
}
int main(){
	printf("ENTER THE INFIX EXPRESSION  : ");
	scanf("%s",infix);
	infixToPrefix();
	printf("EQUIVALENT prefix EXPRESSION :");
	printArray(prefix);
	printf("\nRESULT = %d",prefixEvaluation());
}
