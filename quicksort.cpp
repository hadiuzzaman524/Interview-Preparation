
#include <iostream>

using namespace std;
int partition(int ar[],int low,int high)
{
    int pivot=ar[low];
    int i=low;
    int j=high;
    do
    {
        do
        {
            i++;
        }while(pivot>=ar[i]);
        do
        {
            j--;
        }while(pivot<ar[j]);
        if(i<j)
            swap(ar[i],ar[j]);
    }while(i<j);

    swap(ar[low],ar[j]);
    return j;

}
void quick_sort(int ar[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=partition(ar,low,high);
        quick_sort(ar,low,mid);
        quick_sort(ar,mid+1,high);
    }
}
int main()
{
    int ar[]= {4,3,2,55,1,33,21,45,36,84,44,99};//1
    int n=sizeof(ar)/sizeof(int);
    quick_sort(ar,0,n-1);
    cout<< "the result of quick sort is: "<<endl;
    for(int i:ar)
        cout<<i<< " ";
    cout<<endl;
    return 0;
}


