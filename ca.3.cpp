#include<iostream>

using namespace std;

void merge(int arr[],int low,int mid,int high)
{
    int m = mid - low + 1;
    int n = high - mid;
    int arr1[m];
    int arr2[n];
    for(int i = 0;i < m;i++)
        arr1[i] = arr[low + i];
    for(int i = 0;i < n;i++)
        arr2[i] = arr[mid + 1 + i];
    
    int i,j,k;
    i = j = 0;
    k = low;
    while(i < m && j < n)
    {
        if(arr1[i] < arr2[j])
            arr[k++] = arr1[i++];
        else
            arr[k++] = arr2[j++];
    }
    while(i < m)
        arr[k++] = arr1[i++];
    while(j < n)
        arr[k++] = arr2[j++];
}

void mergeSort(int arr[],int low,int high)
{
    if(low < high)
    {
        int mid = low + (high - low)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

void display(int arr[],int size)
{
    cout<<endl;
    for(int i = 0;i < size;i++)
        cout<<arr[i]<<"   ";
    cout<<endl;
}

int main()
{
    cout<<"Merge Sort"<<endl;
    int array[] = {12,34,12,23,76,78,89,0,67,54,97,93,5,23,52,54,76};
    display(array,(sizeof(array)/sizeof(array[0])));

    mergeSort(array,0,((sizeof(array)/sizeof(array[0]))-1));
    display(array,(sizeof(array)/sizeof(array[0])));
    return 0;
}