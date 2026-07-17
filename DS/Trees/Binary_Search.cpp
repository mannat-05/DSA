#include <stdio.h>
#include <math.h>
#include <stdlib.h>
sort (int arr[],int n)
{
	int temp,count;
	for (int i=0;i<n-1;i++)
	{
		for (int j=0;j<n-i-1;j++)
		{
			if (arr[j]>arr[j+1])
			{
				temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
				count=1;
			}
			if (count==0)
				break;
		}
	}
	printf("Sorted array:");
	for (int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

main()
{
	int n,element,c=0;
	printf("Enter the number of elements of array:");
	scanf("%d",&n);
	int min=0,max=n,mid;
	int arr[n];
	printf("Enter the elements of the array:");
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	sort(arr,n);
	printf("Enter the search element:");
	scanf("%d",&element);
	while (min<max)
	{
		mid=(min+max)/2;
		if (arr[mid]==element)
			break;
		else if (element>arr[mid])
		{
			min=mid+1;
		}
		else
		{
			max=mid-1;
		}	
	}
	if (arr[mid]==element)
		printf("Search element is %d at index %d",arr[mid],mid);
	else
		printf("Search element is not found");
}
