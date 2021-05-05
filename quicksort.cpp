#include<bits/stdc++.h>
using namespace std;
int findpivot(int arr[], int start, int end) {
    int left = start, right = start;
    for(int right=start; right<end; ++right) {
        if(arr[right] < arr[end]) {
            swap(arr[left++],arr[right]);
        }
    } 

    swap(arr[left], arr[end]);
    return left;
}
void quicksort(int arr[], int start, int end) {
    
    if(start < end) {
        int pivot = findpivot(arr,start,end);
        quicksort(arr, start, pivot-1);
        quicksort(arr, pivot+1, end);
    }

    return;
}
int main() {
    
    system("clear");
    int n;
    cout<<"Enter the size and elements of an array: ";
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    quicksort(arr, 0 , n-1);

    cout<<"After Sorting: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] <<" ";
    }

    return 0;
}

//85 64 76 98 43 34 56 23 17 87