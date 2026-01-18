#include<iostream>
using namespace std;
// Binary search in a sorted array
int binary_search(int arr[], int n, int key){
    int s = 0;
    int e = n-1;
    while(s <= e){
        int mid = s + (e-s)/2; // to avoid overflow
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] < key){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return -1; // key not found
}

int main(){
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 23;
    int result = binary_search(arr, n, key);
    if(result != -1){
        cout << "Element is present at index " << result << endl;
    }
    else{
        cout << "Element is not present in array" << endl;
    }
    return 0;
}