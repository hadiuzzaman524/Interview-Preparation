#include <bits/stdc++.h>
using namespace std;

void countSort(int arr[], int n, int maximum)
{
    int temp[maximum]={0};

    for(int i=0; i<n; i++){
        temp[arr[i]]++;
    }
    int i=0, j=0;

    while(i<maximum+1){

      if(temp[i]>0){
        arr[j++]= i;
        temp[i]--;
      }
      else{
        i++;
      }
    }

    for(int i=0; i<maximum; i++){
        cout<< temp[i]<< " ";
    }
    cout<<endl;
}
int main()
{
    int arr[]= {6,8,3,10,15,6,9,12,6,3};
    int n=sizeof(arr)/sizeof(int);

    int maximum=INT_MIN;
    for(int i=0; i<n; i++)
    {

        if(maximum< arr[i])
            maximum=arr[i];
    }
    countSort(arr,n,maximum);

    for(int i=0; i<n; i++)
    {
        cout<< arr[i]<< " ";
    }
    cout<<endl;
    return 0;
}
