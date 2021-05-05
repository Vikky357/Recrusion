#include<bits/stdc++.h>
using namespace std;
int issubsetzero(int arr[], int start,int count, int n) {

    cout<<count<<" "<<start<<endl;
    if(count == 0)
        return true;
    int sum =count;
    for(int i=start+1; i<n; i++) {

       sum += arr[i];
       if(issubsetzero(arr,i,sum,n))
            return true;
       sum -= arr[i]; 
    }

    return false;

}
int main() {

    system("clear");
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >>arr[i];
    for(int i=0; i<n; i++) {
           if(issubsetzero(arr,i,arr[i],n)) {
               cout <<"Yes";
               break;
           }
    }

    return 0;
}

/*
4
1 3 2 -3
*/