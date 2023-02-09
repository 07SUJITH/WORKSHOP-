
// delete a specified data from the list

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
} *head=NULL;


void displayList(){
	struct node *temp=head;
	if(!head)
		printf("list is empty\n");
	while(temp){
		printf("%d " , temp->data);
		temp=temp->next;
	}
	printf("\n");
}


void deleteNode(int key){
	 struct node *temp = head;
	 struct node *prev = head;
	 while(temp!=NULL && temp->data!=key){
	 	prev=temp;
	 	temp=temp->next;
	 }
	 	
	 if(temp==NULL)
	 	return;
	 if(head->data==key)
	 	head=head->next;
	 else
	 	prev->next=temp->next;
	 free(temp);
	 printf("%d is deleted from the list\n",key);
	 displayList();
}



void insert(int data){
	struct node *newNode=malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=NULL;
	if(!head)
		head=newNode;
	else{
		struct node *prev= head;
		while(prev->next)
			prev=prev->next;
		prev->next=newNode;
	}
}


int main(){
	int limit,data,op; 
	printf("enter the number of terms in the list : ");
	scanf("%d",&limit);
	printf("enter the elements in the list :");
	for(int i=0; i<limit;i++){
		scanf("%d",&data);
		insert(data);
	}
		
	while(1){
		printf("\n1.INSERT\n2.DELETE\n3.EXIT\n");
		scanf("%d",&op);
		switch(op){
		
			case 1 :  printf("enter the data to be insert : ");
				scanf("%d",&data);
				insert(data);
				displayList();
				break;
			case 2 :  printf("enter the data to be delete : ");
				scanf("%d",&limit);
				deleteNode(limit); 
				break;
			case 3 :  exit(0);
		}
	}
	return 0;
}
