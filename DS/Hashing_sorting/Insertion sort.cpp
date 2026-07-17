#include <stdio.h>
//Insertion sort
main()
{
	int arr[5]={90,78,66,54,32};
	int key;
	for (int i=0;i<5;i++)
	{
		key=arr[i];
		int j=i-1;
		while (j>=0 && arr[j]>key)	//j>=0 searches till the first from the ith position for the element smaller than the key element.
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;	//if j=-1 then same value remains inside the key.
	}
	for (int i=0;i<5;i++)
	{
		printf("%d ",arr[i]);
	}
}
