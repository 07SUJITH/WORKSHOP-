#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int stack[MAX],top=-1;
struct node{
    int data;
    struct node* next;
}*front=NULL,*rear=NULL;

void enqueue(int data){
    struct node* newNode=malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    if(front==NULL)
        front=rear=newNode;
    else{
        rear->next=newNode;
        rear=newNode;
    }
}

void printList(struct node *temp){
    printf("Queue : ");
    if(front==NULL){
    	printf("Empty \n");return;
    }
    while(temp){
        printf("%d  ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void dequeue(){
    if(front==NULL)
    	printf("list empty \n");
    else if(front==rear){
     	free(front);
     	front=rear=NULL;
     	}
    else{
    struct node *temp=front;
    printf("Deleted :%d ",temp->data);
    front=front->next;
    free(temp);
    }
}

void push(int data){
     if(top==MAX-1){
     printf("stack overflow");exit(1);
     }
    stack[++top]=data;
}

int pop(){
    return stack[top--];
}

void toStack(){
    int j=0;
    struct node *temp=front;
    while(temp){
        push(temp->data);
        j++;
        temp=temp->next;
    }
    temp=front;
    while(temp){
		temp=temp->next;
		free(front);
		front=temp;
    }
    rear=NULL;
    for(int i=0;i<j;i++)
        enqueue(pop());
}

int main(){
    int choice,data;
    while(1){
        printf("Enter\n1 for enqueue\n"
        "2 for dequeue\n3 for reverse queue\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:  printf("Enter the data: ");
                     scanf("%d",&data);
                     enqueue(data);
                     printList(front); break;
            case 2:  dequeue();
            	     printList(front);break;
            case 3:  printList(front);
            	     toStack();
                     printList(front);
                     exit(1); 
            default : printf("Invalid option\n");
        }
    }
}
