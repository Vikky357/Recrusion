#include<bits/stdc++.h>
using namespace std;
int findmaximumpoints(int arr[], int start, int end) {
    if(start > end)
        return 0;
    
    int onepossible = arr[start] + min(findmaximumpoints(arr,start+2,end), findmaximumpoints(arr,start+1,end-1) );
    int anotherpossible = arr[end] + min(findmaximumpoints(arr,start,end-2), findmaximumpoints(arr,start+1,end-1) );
    
    return max(onepossible, anotherpossible);
}
int main() {

    system("cls");
    int n;
    cin >>n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >>arr[i];
    }

    cout<<findmaximumpoints(arr,0,n-1);

}

/*5 6 8 2 
2 8 6 5*/