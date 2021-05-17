#include <iostream>
using namespace std;

int merger(int arr[], int temp[], int left, int mid, int right)
{
    int inversion_count = 0;
    int i=left;
    int j=mid;
    int k=left;
    
    while(i<=mid-1 && j<=right)
    {
        if(arr[i]<arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            
            inversion_count += mid-i;
        }
    }
    
    while(i<=mid-1)
    {
        temp[k++] = arr[i++];
    }
    
    while(j<=right)
    {
        temp[k++] = arr[j++];
    }
    
    for(int i=left; i<=right; i++)
    {
        arr[i] = temp[i];
    }
    
    return inversion_count;
}

int mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inversion_count=0;
    
    if(left<right)
    {
        mid = (left+right)/2;
        inversion_count += mergeSort(arr, temp, left, mid);
        inversion_count += mergeSort(arr, temp, mid+1, right);
        
        inversion_count += merger(arr, temp, left, mid+1, right);
    }
    
    return inversion_count;
}

int main() 
{
    int arr[] = {5,4,3,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int temp[size];
    
    int count = mergeSort(arr, temp, 0, size-1);
    cout<<"The total number of inversions are: "<<count;
	return 0;
}
