#include <stdio.h>
#define MAX 50
typedef struct{
    int row;
    int col;
    int value;
} SPARSE;
int matrix1[50][50],matrix2[50][50];
SPARSE sparse1[MAX],sparse2[MAX];
SPARSE trans1[MAX],trans2[MAX];
void toSparse(int m,int n ,int matrix[][n],SPARSE sparse[MAX]){
    int k=0;
    sparse[k].row=m;
    sparse[k].col=n;
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
            if (matrix[i][j]){
                k++;
                sparse[k].row=i;
                sparse[k].col=j;
                sparse[k].value=matrix[i][j];
            }
    sparse[0].value=k;
}
void toTrans(SPARSE sparse[MAX], SPARSE trans[MAX]){
    int k=0;
    trans[k].row =sparse[0].col; 
    trans[k].col =sparse[0].row;
    trans[k].value=sparse[0].value; 
    for (int i=0;i<sparse[0].col;i++)
        for(int j=1;j<=sparse[0].value;j++)
            if (sparse[j].col==i){
                k++;
                trans[k].row=sparse[j].col;
                trans[k].col=sparse[j].row;
                trans[k].value=sparse[j].value;
            }
}
void display(SPARSE sparse[MAX],int num,int flag){
    if(flag)
        printf("\nMATRIX_%d IN TUPLE FORM \n",num);
    else
        printf("\nTRANSPOSE OF MATRIX_%d IN TUPLE FORM\n",num);
    printf("ROW  COLUMN  VALUE");
    for (int i=0;i<=sparse[0].value;i++)
        printf("\n%d\t%d\t%d",sparse[i].row,sparse[i].col,sparse[i].value);
}
void readMatrix(int m,int n,int A[][n]){
    printf("ENTER MATRIX \n");
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&A[i][j]);
}
int main(){
    int m1,n1,m2,n2;
    printf("ENTER MATRIX_1 DIMENSIONS :");
    scanf("%d%d",&m1,&n1);
    readMatrix(m1,n1,matrix1);
    printf("ENTER MATRIX_2 DIMENSIONS :");
    scanf("%d%d",&m2,&n2);
    readMatrix(m2,n2,matrix2);
    toSparse(m1,n1,matrix1,sparse1);
    toSparse(m2,n2,matrix2,sparse2);
    display(sparse1,1,1);
    display(sparse2,2,1);
    toTrans(sparse1,trans1);
    toTrans(sparse2,trans2);
    display(trans1,1,0);
    display(trans2,2,0);
}
