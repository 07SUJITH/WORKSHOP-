#include<stdio.h>
#include<stdlib.h>

int mutex =1 ,empty, full = 0, items=0;

void wait(int *s){
    (*s)--;
}
void signal(int * s){
   (*s)++; 
}
void producer(){
    wait(&empty);
    wait(&mutex);
    items++;
    printf("Produced an item.\nNumber of items left : %d\n",items);
    signal(&mutex);
    signal(&full);
}

void consumer(){
    wait(&full);
    wait(&mutex);
    items--;
    printf("Consumed an item.\nNumber of items left : %d\n",items);
    signal(&mutex);
    signal(&empty);
}

int main(){
    int buffer_size,choice;
    printf("PRODUCER CONSUMER PROBLEM\n\n");
    printf("Enter the size of buffer :");
    scanf("%d",&buffer_size);
    empty = buffer_size;
    printf("\n1 PRODUCER \n2 CONSUMER \n3 EXIT\n");
    do{
           printf("Enter your choice : ");
           scanf("%d",&choice);
           switch(choice){
            case 1: 
                if(mutex==1  && empty !=0)
                    producer();
                else
                    printf("No space in buffer!\n");
                break;
            case 2: 
                if(mutex==1 && full!=0)
                    consumer();
                else    
                    printf("Buffer is empty!\n");
                break;
            case 3: exit(0);
            default:printf("Wrong Choice! Try Again!!!");
          
           }
    }while(1);
 
}
