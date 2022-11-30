#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct{
    int row;
    int col;
    int value;
}

SPARSE ;
void readMatrix(int m,int n,int arr[][n]){
    printf("Enter the matrix \n");
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&arr[i][j]);
}
void display(SPARSE s[]){
    printf("\nROW\tCOLUMN\tVALUE\n");
    for(int i=0;i<=s[0].value;i++)
        printf("%d\t%d\t%d\n",s[i].row,s[i].col,s[i].value);
}

void toSparse(int m,int n,int arr[m][n],SPARSE s[MAX]){
    s[0].row=m; s[0].col=n;
    int k=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(arr[i][j]){
                k++;
                s[k].row=i;
                s[k].col=j;
                s[k].value=arr[i][j];
            }
    s[0].value=k;
}
void toTrans(SPARSE s[], SPARSE t[]){
    t[0].col=s[0].row;
    t[0].row=s[0].col;
    t[0].value=s[0].value;
    int k=1;
    for(int i=0;i< s[0].col;i++)
        for(int j=1;j<=s[0].value;j++)
            if(s[j].col==i){
                t[k].row=s[j].col;
                t[k].value=s[j].value;
                t[k].col=s[j].row;
                k++;
            }
}

void addSparse(SPARSE p[MAX],SPARSE q[MAX],SPARSE sum[MAX] ) {
    int i=1,j=1,k=1;
    sum[0].row=p[0].row;
    sum[0].col=p[0].col;
    while(i<=p[0].value&&j<=q[0].value){
        if(p[i].col==q[j].col && p[i].row==q[j].row){
            sum[k].row=p[i].row;
            sum[k].col=p[j].col; 
            sum[k].value=p[i].value+q[j].value;
            i++;j++;
        }
        else if( p[i].row==q[j].row){
            sum[k].row=p[i].row;
            if(p[i].col<q[j].col){
                sum[k].col=p[i].col;
                sum[k].value=p[i].value;
                i++;
            }
            else{
                sum[k].col=q[j].col;
                sum[k].value=q[j].value;
                j++;
            }
        }
    k++;
    }
    while(i<=p[0].value){
        sum[k].row=p[i].row;
        sum[k].col=p[i].col;
        sum[k].value=p[i].value;
        k++;
    }
    while(i<=q[0].value){
        sum[k].row=q[j].row;
        sum[k].col=q[j].col;
        sum[k].value=q[j].value;
        k++;
    }
   sum[0].value=k-1; 
}
int main(){
int p[10][10],q[10][10],m1,n1,m2,n2;
SPARSE sparse1[MAX], sparse2[MAX],trans1[MAX],trans2[MAX];
SPARSE sum[MAX],sumTrans[MAX];
printf("\nMATRIX_1");
printf("\nEnter the dimension of the matrix_1 : ");
scanf("%d%d",&m1,&n1);
readMatrix(m1,n1,p);
printf("\nMATRIX_2");
printf("\nEnter the dimension of the matrix_2 : ");
scanf("%d%d",&m2,&n2);
if(m1!=m2 || n1!=n2){
    printf("invalid dimension for addition");
    exit(1);
}
readMatrix(m2,n2,q);
toSparse(m1,n1,p,sparse1);
toSparse(m2,n2,q,sparse2);
toTrans(sparse1,trans1);
toTrans(sparse2,trans2);
addSparse(sparse1,sparse2,sum); 
toTrans(sum,sumTrans);
printf("-----MATRIX_1---");
    printf("\nTUPLE FORM \n");
    display(sparse1);
    printf("TRANSPOSE IN TUPLE FORM \n");
    display(trans1);
printf("-----MATRIX_2---");
    printf("\nTUPLE FORM \n");
    display(sparse2);
    printf("TRANSPOSE IN TUPLE FORM \n");
    display(trans2);
printf("SUM IN TUPLE FORM\n");
    display(sum);
printf("TRANSPOSE OF SUM IN TUPLE FORM\n");
    display(sumTrans);
}
/*
MATRIX_1
Enter the dimension of the matrix_1 : 2 2
Enter the matrix 
1 2 
3 4
MATRIX_2
Enter the dimension of the matrix_2 : 2 2
Enter the matrix 
1 2 
3 4
-----MATRIX_1---
TUPLE FORM 

ROW	COLUMN	VALUE
2	2	4
0	0	1
0	1	2
1	0	3
1	1	4
TRANSPOSE IN TUPLE FORM 

ROW	COLUMN	VALUE
2	2	4
0	0	1
0	1	3
1	0	2
1	1	4
-----MATRIX_2---
TUPLE FORM 

ROW	COLUMN	VALUE
2	2	4
0	0	1
0	1	2
1	0	3
1	1	4
TRANSPOSE IN TUPLE FORM 

ROW	COLUMN	VALUE
2	2	4
0	0	1
0	1	3
1	0	2
1	1	4
SUM IN TUPLE FORM

ROW	COLUMN	VALUE
2	2	4
0	0	2
0	1	4
1	0	6
1	1	8
TRANSPOSE OF SUM IN TUPLE FORM

ROW	COLUMN	VALUE
2	2	4
0	0	2
0	1	6
1	0	4
1	1	8
*/

