#include <stdio.h>
//Selection sort
main()
{
	int arr[5]={12,3,45,67,19};
	int s,pos,temp;
	for (int i=0;i<5;i++)
	{
		s=arr[i];
		for (int j=i+1;j<5;j++)
		{
			if (s>arr[j])
			{
				s=arr[j];
				pos=j;
			}
		}
		arr[pos]=arr[i];
		arr[i]=s;
	}
	printf("Sorted Array:");
	for (int i=0;i<5;i++)
	{
		printf("%d ",arr[i]);
	}
}

