#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n){

    for(int i=1; i<n; i++){q

        int j=i-1;
        int x=arr[i];

        while(j>-1 && arr[j]>x){
            arr[j+1]= arr[j];
            j--;
        }
        arr[j+1]= x;
    }
}
int main()
{
    int arr[]={8,5,7,3,2};
    int n= sizeof(arr)/sizeof(int);
    insertionSort(arr,n);

    for(int i=0; i<n; i++)
        cout<< arr[i]<< " ";
    cout<<endl;

    return 0;
}
