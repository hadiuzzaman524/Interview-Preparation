#include <bits/stdc++.h>
using namespace std;

int main(){

    int arr[]={3,4,1,7,2,9};
    int n=sizeof(arr)/sizeof(int);

    for(int i=0; i<n-1; i++){

        for(int j=0; j<n-1-i; j++){

            if(arr[j]> arr[j+1])
            swap(arr[j], arr[j+1]);
        }
    }

    for(int i=0; i<n; i++)
    cout<< arr[i]<< " ";


return 0;
}
