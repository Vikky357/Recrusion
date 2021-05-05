#include<bits/stdc++.h>
using namespace std;
void merge(int arr[], int start, int mid, int end) {
    int i = start;
    int  j = mid+1;
    int k = start;
    int temparr[start+end];
    while(i <= mid && j<=end) {
        if(arr[i] <= arr[j]) {
            temparr[k++] = arr[i++];
        }
        else {
            temparr[k++] = arr[j++];
        }
    }

    while(i <= mid) {
        temparr[k++] = arr[i++];
    }

    while(j <= end) {
        temparr[k++] = arr[j++];
    }

    for(int index=start; index<=end; index++) {
        arr[index] = temparr[index];
    } 

    return ;
}
void mergesort(int arr[] , int start, int end) {
    if(start < end) {
       // cout<<"Executed:"<<endl;
        int mid = start + (end-start)/2;
        mergesort(arr, start, mid);
        mergesort(arr, mid+1, end);
        merge(arr, start , mid, end);
    }

    return ;
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

    mergesort(arr, 0 , n-1);

    cout<<"After Sorting: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] <<" ";
    }

    return 0;
}