#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int coeff;
    int expo;
}POLY;
int readPoly(POLY p[]){
    int n;
    printf("\nEnter the number of terms :");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the coefficient and exponent of term %d :",i+1);
        scanf("%d%d",&p[i].coeff,&p[i].expo);
    }
    return n;
}
void displayPoly(POLY p[],int n){
    for(int i=0;i<n-1;i++){
        printf("%dx^%d +",p[i].coeff,p[i].expo);
    }
    printf("%dx^%d\n",p[n-1].coeff,p[n-1].expo);
}
int addPoly(POLY p[], POLY q[],POLY r[],int np,int nq){
    int i=0,j=0,k=0;
    while(i<np && j<nq){
        if(p[i].expo==q[j].expo){
            r[k].expo=p[i].expo;
            r[k].coeff= p[i].coeff+q[j].coeff;
            j++;i++;
        }
        else if(p[i].expo>q[j].expo){
            r[k].expo=p[i].expo;
            r[k].coeff=p[i].coeff;
            i++;
        }
        else{
            r[k].expo=q[j].expo;
            r[k].coeff=q[j].coeff;
            j++;
        }
        k++;
    }
    while(i<np){
        r[k].coeff=p[i].coeff;
        r[k].expo=p[i].expo;
        k++;i++;
    }
    while(j<nq){
        r[k].coeff=q[j].coeff;
        r[k].expo=q[j].expo;
        k++;j++; 
    }
    return k;    
}
int main(){
POLY p[20],q[20],r[40];
int np,nq,nr;
printf("\nEnter First Polynomial");
np=readPoly(p);
printf("\nEnter Second Polynomial");
nq=readPoly(q);
nr=addPoly(p,q,r,np,nq);
printf("\nFirst polynomial : ");
displayPoly(p,np);
printf("Second polynomial : ");
displayPoly(q,nq);
printf("Resultant polynomial : ");
displayPoly(r,nr);
}

/*
Enter First Polynomial
Enter the number of terms :3
Enter the coefficient and exponent of term 1 :5 3
Enter the coefficient and exponent of term 2 :4 2
Enter the coefficient and exponent of term 3 :2 1

Enter Second Polynomial
Enter the number of terms :4
Enter the coefficient and exponent of term 1 :7 4
Enter the coefficient and exponent of term 2 :5 3 
Enter the coefficient and exponent of term 3 :1 2
Enter the coefficient and exponent of term 4 :6 0

First polynomial : 5x^3 +4x^2 +2x^1
Second polynomial : 7x^4 +5x^3 +1x^2 +6x^0
Resultant polynomial : 7x^4 +10x^3 +5x^2 +2x^1 +6x^0
*/
