// Online C compiler to run C program online
#include <stdio.h>

void bubbleSort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertion(int arr[],int n){
    for(int i=0;i<n;i++){
        int j=i;
        while(j-1>=0 && arr[j-1]>arr[j]){
            int temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--;
        }
    }
}
void selection(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int mini=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[mini]){
                mini=j;
            }
        }
        int temp=arr[i];
        arr[i] = arr[mini];
        arr[mini] = temp;
    }
}
int p(int arr[],int low,int high){
    int pivot = low;
    int i=low;
    int j=high;
    
    while(i<j){
        while(arr[pivot]>=arr[i] && i<=high) i++;
        while(arr[pivot] < arr[j] && j>=low) j--;
        if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[pivot];
    arr[pivot]= arr[j];
    arr[j]=temp;
    return j;
}
//Qsort
void qsortt(int arr[],int low,int high){
    if(low<high){
        int part=p(arr,low,high);
        qsortt(arr,low,part-1);
        qsortt(arr,part+1,high);
    }
}

void merge(int arr[],int low,int mid,int high){
    int i=low;
    int j=mid+1;
    int b[100]={0};
    int k=0;
    while(i<=mid &&j<=high){
        if(arr[i]<arr[j]){
            b[k++] = arr[i++];
        }
        else{
            b[k++] = arr[j++];
        }
    }
    for(;i<=mid;i++){
        b[k++] = arr[i++];
    }
    for(;j<=high;j++){
        b[k++] = arr[j++];
    }
    
    k = 0;
    for (i = low; i <= high; i++) {
        arr[i] = b[k++];
    }
}
void mergeSort(int arr[], int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
int main() {
    // Write C code here
    printf("Try programiz.pro");
    int arr[] = {4,5,6,2,1};
    int n=sizeof(arr)/sizeof(int);
    
    //qsortt(arr,0,n-1);
    //selection(arr,n);
    //insertion(arr,n);
    //bubbleSort(arr,n);
    mergeSort(arr,0,n);
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    return 0;
}
