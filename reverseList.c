#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
}*head = NULL;
void displayList(struct node *ptr){
    printf("List : ");
    if(head==NULL)
        printf("List Empty\n");
    else{
        for(;ptr!=NULL;ptr=ptr->link)
            printf("%d ", ptr->data);
        printf("\n");
    }
}
int countNode(){
    if(head==NULL)
        return 0;
    int count =0;
    for(struct node *ptr=head;ptr!=NULL;ptr=ptr->link)
        count++;
    return count;
}
void reverse() {
    struct node* current = head, *prev = NULL, *next = NULL;
	while(current){
	    next = current->link;
	    current->link = prev;
	    prev = current;
	    current = next;
	}
	head=prev;
	if(head!= NULL)
		printf("\nList Reversed. \n");
	else
		printf("\nList Empty. \n");
}
void addAtPos(int data,int pos){
        struct node *ptr2=malloc(sizeof(struct node));
        ptr2->data=data;
        ptr2->link=NULL;    
        if(pos==1){
            if(head==NULL)
                head=ptr2;
            else{
                ptr2->link=head;
                head=ptr2;
            }
        }
        else{
            struct node *ptr = head;
            for(pos--;pos>1;pos--)
                ptr=ptr->link;
            ptr2->link =ptr->link;
            ptr->link=ptr2;
        }
}
void deleteAtPos(int pos){  
    struct node *curr=head,*prev= NULL;
    if(pos==1){
        head=curr->link;
        free(curr);
    }
    else{
        while(pos>1){
           prev=curr;
           curr=curr->link;
           pos--;
        }
        prev->link=curr->link;
        free(curr);
    }
}
int main(){
   int choice,data,pos;
   do{  printf("Enter \n1. Insertion" "\n2. Deletion \n3. Reverse \n4. Exit\n" );
       scanf("%d",&choice);
       switch(choice){
            case 1: 
				printf("Enter the data :"); 
 				scanf("%d",&data);
				addAtPos(data,countNode()+1);
				displayList(head); break;
            case 2: 
				deleteAtPos(countNode()); break;
				displayList(head); break;
            case 3: 
				reverse();
				displayList(head);                                   
       }
    }while(choice<3);
}
