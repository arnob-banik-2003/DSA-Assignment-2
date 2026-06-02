#include<iostream>
using namespace std;

int partition(int arr[],int low, int high){
    int pivot = arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    int pivotIndex = i+1;
    swap(arr[pivotIndex],arr[high]);
    return pivotIndex;
}

void QuickSort(int arr[], int low, int high){
    //base case
    if(low>=high)
        return;

    //divide
    int pivotIndex=partition(arr,low,high);

    //conquer
    QuickSort(arr,low,pivotIndex-1);
    QuickSort(arr,pivotIndex+1,high);
}

int main(){
    int arr[7] = {8, 3, 1, 5, 2, 7, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    QuickSort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

