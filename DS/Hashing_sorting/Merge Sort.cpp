#include <stdio.h>
void merge(int arr[],int l,int mid,int r)
{
	int n1=mid-l+1;
	int n2=r-mid;
	int a[n1],b[n2];
	//Creating different merged arrays.
	for(int i=0;i<n1;i++)
	{
        a[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++)
	{
        b[j]=arr[mid+1+j];
    }
    int i=0,j=0,k=l;
    //Checking the mergeed array and joining two sorted arrays.
    while(i<n1 && j<n2)
	{
        if(a[i]>=b[j])
		{
            arr[k++]=b[j++];
        }
        else
		{
            arr[k++]=a[i++];
        }
    }
    //Appending the remaining elements to the array.
    while(i<n1)
	{
        arr[k++]=a[i++];
    }
    while(j<n2)
	{
        arr[k++]=b[j++];
    }
}

void merge_sort(int arr[],int l,int r)
{
	int mid=(l+r)/2;
	if (l>=r)
	{
		return;
	}
		merge_sort(arr,l,mid);		//recursive call for left side array
		merge_sort(arr,mid+1,r);	//recursive call for right side array
		merge(arr,l,mid,r);			//Merging the two divided arrays
}

main()
{
	int arr[5]={12,3,45,90,56};
	int l=0,r=4;
	merge_sort(arr,l,r);
	printf("Sorted array:");
	for (int i=0;i<5;i++)
	{
		printf("%d ",arr[i]);
	}
}
