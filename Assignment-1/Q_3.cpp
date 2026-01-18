#include<iostream>
using namespace std;

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i] <= pivot && i<= high-1){
            i++;
        }
        while(arr[j] > pivot && j>= low+1){
            j--;
        }
        if(i<j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void qs(int arr[], int low, int high){
    if (low < high){
        int pIndex = partition(arr,low,high);
        qs(arr,low,pIndex-1);
        qs(arr,pIndex+1,high);
    }
}

int main(){
    int arr[] = {4, 2, 6, 9, 2};
    int n= sizeof(arr)/sizeof(arr[0]);

    qs(arr,0,n-1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}