#include<iostream>
using namespace std;

void merge(int arr[],int low, int mid, int high){
    int left = low;
    int right = mid +1;
    int temp[high-low+1];
    int k=0;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]){ 
            temp[k] = arr[left];
            left++;
        }else {
            temp[k] = arr[right];
            right++;
        }
        k++;
    }
    while (left <= mid) {
        temp[k] = arr[left];
        left++;
        k++;
    }
    while (right <= high) {
        temp[k] = arr[right];
        right++;
        k++;
    }
    for (int i = 0; i < k; i++) {
        arr[low + i] = temp[i];
    }
}
void mergeSort(int arr[], int low, int high){
     if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main(){
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr,0,n-1);

    cout << "Sorted array 1: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout<<endl;
    int arr2[] = {38, 27, 43, 3, 9, 82, 10};
    int n2 = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr2,0,n2-1);

    cout << "Sorted array 2: ";
    for (int i = 0; i < n2; i++)
        cout << arr2[i] << " ";
    
    return 0;
}