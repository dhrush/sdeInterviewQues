#include <iostream>
using namespace std;

void rearrange(int arr[], int size)
{
    for(int i=0; i<size-1; i++)
    {
        if(arr[i]>arr[i+1])
        {
            swap(arr[i], arr[i+1]);
        }
    }
}

int main() 
{
	int a[] = {1,4,7,8,10};
	int n1 = 5;
	int b[] = {2,3,9};
	int n2 = 3;
	int i=0;
	int j=0;
	
	while(i<n1 && j<n2)
	{
	    if(a[i] == b[j])
	    {
	        i++;
	        j++;
	    }
	    
	    else if(a[i]>b[j])
	    {
	        swap(a[i], b[j]);
	        i++;
	        //rearrange array b to maintain sorted property
	        rearrange(b,n2);
	        j = 0;
	    }
	    else if(a[i]<b[j])
	    {
	        i++; 
	    }
	}
	
	for(int i=0; i<n1; i++)
	{
	    cout<<a[i]<<" ";
	}
	cout<<"\n";
	for(int j=0; j<n2; j++)
	{
	    cout<<b[j]<<" ";
	}
	return 0;
}