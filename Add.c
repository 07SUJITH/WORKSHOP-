#include<stdio.h>
#include<stdlib.h>
struct node{
    float coeff;
    int expo;
    struct node *link;
};
void print(struct node* head){
    struct node *temp = head;
    if(temp==NULL)
        printf("No Polynoial");
    while(temp!=NULL){
            printf("(%.1fx^%d)",temp->coeff,temp->expo);
            temp=temp->link;
            if(temp!=NULL)
                printf("+");        
            else
                printf("\n");
    }
}
struct node *insert(struct node* head,float co,int ex){
    struct node *temp;
    struct node *new =(struct node *)malloc(sizeof(struct node));
    new->coeff=co;
    new->expo=ex;
    new->link=NULL;
    //if there is no node in the list or given exponent is greater the first node exponent
    if(head==NULL || ex>head->expo){
        new->link=head;
        head=new;
    }
    else{
        temp=head;
        while(temp->link!=NULL && temp->link->expo >= ex)
            temp=temp->link;
        new->link=temp->link;
        temp->link=new;
    }
    return head;
}
struct node *create(struct node *head){
    int i, n,ex;
    float co;
    printf("Enter the number of terms:");
    scanf("%d",&n);
    for(i=0; i<n; i++){
        printf("Enter the coefficient  for term %d :", i+1);
        scanf("%f", &co);
        printf("Enter the exponent for the term %d :",i+1);
        scanf("%d", &ex);
        head= insert(head,co,ex);
    }
    return head;
}
struct node *polyAdd(struct node *head1, struct node *head2){
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;
    while(ptr1!=NULL && ptr2!=NULL){

        if(ptr1->expo==ptr2->expo){
            head3 =insert(head3,ptr1->coeff+ptr2->coeff,ptr1->expo);
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }
        else if(ptr1->expo > ptr2->expo){
            head3 =insert(head3,ptr1->coeff,ptr1->expo);
            ptr1=ptr1->link;
        }
        else if(ptr1->expo < ptr2->expo){
            head3 =insert(head3,ptr2->coeff,ptr2->expo);
            ptr2=ptr2->link;
        }
    }
    while(ptr1!=NULL){
        head3 =insert(head3,ptr1->coeff,ptr1->expo);
        ptr1=ptr1->link;
    }
    while(ptr2!=NULL){
        head3 =insert(head3,ptr2->coeff,ptr2->expo);
        ptr2=ptr2->link;
    }
    return head3;
}
int main(){
    struct node* head1 =NULL;
    struct node* head2 =NULL;
    struct node* head3 =NULL;
    printf("enter the first polnomial\n");
    head1=create(head1);
    printf("enter the second polnomial\n");
    head2=create(head2);
    printf("\nFIRST POLYNOMIAL    : ");
    print(head1);
    printf("\nSECOND POLYNOMIAL   : ");
    print(head2);
    head3 =polyAdd(head1,head2);
    printf("\nRESULTANT POLYNOMIAL:");
    print(head3);
    free(head1);
    free(head2);
    free(head3);
}
/*  enter the first polnomial
Enter the number of terms:2
Enter the coefficient  for term 1 :9
Enter the exponent for the term 1 :3
Enter the coefficient  for term 2 :5
Enter the exponent for the term 2 :2
enter the second polnomial
Enter the number of terms:2 
Enter the coefficient  for term 1 :10
Enter the exponent for the term 1 :2
Enter the coefficient  for term 2 :20
Enter the exponent for the term 2 :1

FIRST POLYNOMIAL    : (9.0x^3)+(5.0x^2)

SECOND POLYNOMIAL   : (10.0x^2)+(20.0x^1)

RESULTANT POLYNOMIAL:(9.0x^3)+(15.0x^2)+(20.0x^1)*/
