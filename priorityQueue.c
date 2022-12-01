#include<stdio.h>
int r=-1,f=-1,size=5;
int q[2][50];
void dequeue(){
    if(f==-1)
        printf("queue is empty");
    else{
        printf("deleted data : %d",q[0][f]);
        f= f==r? -1: f+1;
        if(f==-1)
            r=-1;
    }
}
void enqueue(int data,int prio){
    if(r==size-1)
        printf("queue is full");
    else{
        if(f==-1){
            q[0][0]=data;
            q[1][0]=prio;
            f++;
        }
        else{
        int i,loc;
        for( i=r; i>=f; i--)
            if(q[1][i]<=prio)
                break;
        loc =i+1;
        for(i=r;i>=loc;i--){
            q[0][i+1]=q[0][i];
            q[1][i+1]=q[1][i];
        }
        q[0][loc]=data;
        q[1][loc]=prio;      
        }
        r++; 
    }
}
void display(){
    if(f==-1)
        printf("queue is empty");
    else
        for(int i=f;i<=r;i++)
        printf("%d ",q[0][i]);
}
int main(){
    int choice ,data,prio;
    do{
        printf("\nEnter\n1 For Enqueue \n2 For Dequeue\n3 for Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1 : printf("Enter the data : ");
                     scanf("%d",&data);
                     printf("Enter the priority :");
                     scanf("%d",&prio);
                     enqueue(data,prio); display();
                     break;
            case 2 : dequeue();display();break;
        }
    }while(choice<3);
}
