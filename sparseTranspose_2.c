#include<stdio.h>
typedef struct {
    int row;
    int col;
    int value;
}SPARSE;

void toSparse(int m,int n ,int matrix[][n],SPARSE sparse[100]){
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

void toTrans(SPARSE s[] ,SPARSE trans[]){
    trans[0].row=s[0].col;
    trans[0].col=s[0].row;
    trans[0].value=s[0].value;
    int k=1;
    for(int i=0;i<s[0].col;i++)
        for(int j=1;j<=s[0].value;j++){
            if(s[j].col== i){
                trans[k].value=s[j].value;
                trans[k].row=s[j].col;
                trans[k].col=s[j].row;
                k++;
            }
        }
}

void readMatrix (int m,int n,int arr[m][n]){  
    printf("Enter the matrix :\n");
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&arr[i][j]);
}

void printSparse(SPARSE s[]){
    printf("\nROW\tCOLUMN\tVALUE\n");
    for(int i=0;i<=s[0].value;i++){
        printf("%d\t%d\t%d\n",s[i].row,s[i].col,s[i].value);
    }
    printf("\n");
}

void printMatrix(int m, int n ,int arr[][n]){
    printf("\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            printf(" %d ",arr[i][j]);
        printf("\n");
    }
}

int main(){

    int m1,n1,m2,n2;
    int p[10][10], q[10][10];
    SPARSE sparse1[100],sparse2[100],trans1[100],trans2[100];
    printf("MATRIX 1");
    printf("\nEnter the row and column of matrix: ");
    scanf("%d%d",&m1,&n1);
    readMatrix(m1,n1,p);
    toSparse(m1,n1,p,sparse1);
    toTrans(sparse1,trans1);

    printf("MATRIX 2");
    printf("\nEnter the row and column of matrix: ");
    scanf("%d%d",&m2,&n2);
    readMatrix(m2,n2,q);
    toSparse(m2,n2,q,sparse2);
    toTrans(sparse2,trans2);

    printf("-----MATRIX_1---");
    printf("\nNORMAL FORM\n");
    printMatrix(m1,n1,p);
    printf("TUPLE FORM \n");
    printSparse(sparse1);
    printf("TRANSPOSE IN TUPLE FORM \n");
    printSparse(trans1);

    printf("-----MATRIX_2---");
    printf("\nNORMAL FORM\n");
    printMatrix(m2,n2,q);
    printf("TUPLE FORM \n");
    printSparse(sparse2);
    printf("TRANSPOSE IN TUPLE FORM \n");
    printSparse(trans2);
    

}




/*MATRIX 1
Enter the row and column of matrix: 3 3
Enter the matrix :
1 0 0
0 2 3
0 0 2
MATRIX 2
Enter the row and column of matrix: 3 3
Enter the matrix :
0 1 0 
0 2 0
0 3 0
-----MATRIX_1---
NORMAL FORM

 1  0  0
 0  2  3
 0  0  2
TUPLE FORM

ROW     COLUMN  VALUE
3       3       4
0       0       1
1       1       2
1       2       3
2       2       2

TRANSPOSE IN TUPLE FORM

ROW     COLUMN  VALUE
3       3       4
0       0       1
1       1       2
2       1       3
2       2       2

-----MATRIX_2---
NORMAL FORM

 0  1  0
 0  2  0
 0  3  0
TUPLE FORM

ROW     COLUMN  VALUE
3       3       3
0       1       1
1       1       2
2       1       3

TRANSPOSE IN TUPLE FORM

ROW     COLUMN  VALUE
3       3       3
1       0       1
1       1       2
1       2       3
*/
