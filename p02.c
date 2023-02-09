// sorting a list of integers using quickSort  
#include<stdio.h>
void swap(int *arr, int x, int y){
	int temp=arr[x];
	arr[x]=arr[y];
	arr[y]=temp;
}
int partition(int *arr, int lb, int ub){
	int pivot=arr[lb];
	int i=lb+1,j=lb+1;
	while(j<=ub){
		if(arr[j] < pivot)
			swap(arr,i++,j);
		j++;
	}	
	swap(arr,i-1,lb);
	return i-1;
}

void quickSort(int * arr ,int lb, int ub){
	if(lb>=ub)
		return ;
	int pivotIndex= partition(arr, lb, ub);
	quickSort(arr,lb,pivotIndex);
	quickSort(arr,pivotIndex+1,ub);
}

int main(){
	int arr[50], limit;
	printf("enter the number of elements in the list :") ;
	scanf("%d",&limit);
	printf("enter the list to be sorted : ");
	for(int i=0;i< limit; i++)
		scanf("%d",&arr[i]);
	quickSort(arr,0,limit-1);
	printf("sorted list : ");
	for(int i= 0;i<limit; i++)
		printf("%d ",arr[i]);
}
