#include<iostream>
using namespace std;
void selection_sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int minIndex=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minIndex])
            {
                minIndex=j;
            }
        }
        if(minIndex!=i)
        {
            int temp=arr[i];
            arr[i]=arr[minIndex];
            arr[minIndex]=temp;
        }
    }
}
int main()
{
    int n;
    cout<<"\nEnter total no. of elements:";
    cin>>n;
    int arr[n];
    cout<<"\nEnter elements in the array:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"\nOriginal Array :";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    selection_sort(arr,n);
    cout<<"\nSorted Array is:";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}