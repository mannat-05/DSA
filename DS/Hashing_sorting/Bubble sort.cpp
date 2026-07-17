#include <stdio.h>
//Bubble sort
main()
{
	int arr[5]={90,78,66,54,32};
	int temp;
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<5-i-1;j++)
		{
			if (arr[j]>arr[j+1])
			{
				temp=arr[j];	//storing the smallest value in the last positions.
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	for (int i=0;i<5;i++)
	{
		printf("%d ",arr[i]);
	}
}
