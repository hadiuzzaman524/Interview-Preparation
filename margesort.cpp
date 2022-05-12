#include <bits/stdc++.h>
using namespace std;

void marge(int arr[], int low, int mid, int high)
{

    int n1= mid-low+1;
    int n2= high-mid;
    int la[n1];
    int ra[n2];
    for(int i=0; i<n1; i++)
        la[i]=arr[low+i];
    for(int i=0; i<n2; i++)
        ra[i]=arr[mid+1+i];

    int i=0;
    int j=0;
    int k=low;

    while(i<n1 && j<n2)
    {

        if(la[i]<ra[j])
        {
            arr[k]=la[i];
            i++;
        }
        else
        {
            arr[k]=ra[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        arr[k]=la[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=ra[j];
        j++;
        k++;
    }
}
void marge_sort(int arr[], int low, int high)
{

    if(low<high)
    {
        int mid= low+ (high-low) / 2;
        marge_sort(arr, low, mid);
        marge_sort(arr, mid+1, high);

        marge(arr, low, mid, high);
    }
}
int main()
{
    int ar[]= {4,3,2,55,33,21,45,36,84,44,99,1};
    int n=sizeof(ar)/sizeof(int);
    marge_sort(ar,0,n-1);
    cout<< "the marge sort result is: "<<endl;
    for(int i=0; i<n; i++)
        cout<< ar[i]<< " ";
    cout<<endl;
    return 0;
}
