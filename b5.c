#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int *arr,int low,int high) {
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++) {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}
int quickSort(int *arr,int low,int high) {
    if(low<high) {
        int pivot=partition(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
}

int main() {
    int n;
    do {
        printf("Enter number: ");
        scanf("%d",&n);
        if (n<0|| n>1000) {
            printf("N phai nho hon 1000 va lon hon 0");
        }
    } while (n<0 || n>1000);
    int *arr=(int*)malloc(n*sizeof(int));
    if(arr==NULL) {
        printf("Cap phat bo nho khong hanh cong");
        free(arr);
        return 1;
    }
    printf("Nhap cac phan tu trong mang\n");
    for (int i=0; i<n; i++) {
        scanf("%d",&arr[i]);
    }
    printf("before:");
    for (int i=0; i<n; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    quickSort(arr,0,n-1);
    printf("after:");
    for (int i=0; i<n; i++) {
        printf("%d ",arr[i]);
    }
    return 0;
}
