#include<bits/stdc++.h>
using namespace std;
int partitions(int arr[], int low, int high)
{
    int pi= arr[high];
    int i= low-1;


    for(int j=low; j<=high-1; j++)
    {
        if(arr[j]<=pi){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);

    return i+1;
}
void quicksort(int arr[], int low, int high)
{

    if(low<high)
    {

        int p= partitions(arr, low, high);

        quicksort(arr, low, p-1);
        quicksort(arr, p+1, high);

    }
}
int main()
{
    int arr[]= {8,5,7,2,1,9 ,13,17,22,5,88,586,11         };
    int n=sizeof(arr)/sizeof(int);

    quicksort(arr,0,n-1);

    for(int i=0; i<n; i++)
        cout<< arr[i]<< " ";
    cout<<endl;

    return 0;
}
