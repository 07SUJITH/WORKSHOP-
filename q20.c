#include<stdio.h>
#include<stdlib.h>
int arr[50],size;
void printArray(){
    printf("Sorted array:");
    for(int i=0 ;i<size;i++)
        printf("%d ", *(arr+i) );
}
void readArray(){
    printf("Enter the limit: ");
    scanf("%d", &size);
    printf("Enter the integers: ");
    for(int i=0;i<size;i++)
        scanf("%d", arr+i );
}
void swap(int *arr,int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr,j,j+1);
}
void insertionSort(int *arr, int n){
    for (int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
            arr[j-- + 1] = arr[j];
        arr[j + 1] = key;
    }
}
void selectionSort(int* arr, int size) {
for (int i = 0; i < size - 1; i++) {
    int min_index = i;
    for (int j = i + 1; j < size; j++)
        if (arr[j] < arr[min_index])
            min_index = j;
    if(i!=min_index)
        swap(arr,i,min_index);
}
}
int partition(int *arr, int left, int right) {
    int i = left + 1,j;
    int pivot = arr[left];
    int tmp;
    for (j = left + 1; j <= right; j++)
        if (arr[j] < pivot) {
            swap(arr,i,j);
            i++;
        }
    swap(arr,left,i-1);
    return i - 1;
}
void quickSort(int *arr, int left, int right) {
    if (left >= right)
        return;
    int pivot_index = partition(arr, left, right);
    quickSort(arr, left, pivot_index - 1);
    quickSort(arr, pivot_index + 1, right);
}
void merge(int *arr, int left, int mid, int right){
    int i = left;
    int j = mid + 1;
    int temp[right - left + 1];
    int k = 0;
    while (i <= mid && j <= right)
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}
void mergeSort(int *arr, int left, int right){
    if ( left >= right )
        return;
    int mid = ( left + right ) / 2;
    mergeSort( arr , left , mid );
    mergeSort( arr, mid + 1, right);
    merge( arr, left, mid, right);
}
int main(){
    int choice;
    while(1){
        printf("\nEnter \n1.Bubble Sort\n2.Insertion Sort"
        "\n3.Selection Sort\n4.Quick Sort\n5.Merge Sort\n6.Exit\n:");
        scanf("%d",&choice);
        if(choice == 6)
            exit(1);
        readArray();
        switch(choice){
            case 1 : bubbleSort(arr,size);break;
            case 2 : insertionSort(arr,size);break;
            case 3 : selectionSort(arr,size);break;
            case 4 : quickSort( arr,0,size-1);break;
            case 5 : mergeSort(arr,0,size-1);break;
        }
        printArray();
    }
}
