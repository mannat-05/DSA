#include <stdio.h>
#include <stdlib.h>
main()
{
	int digits[3]={1,2,3};
	int digitsSize=3;
	int *returnSize;
	int* result = (int*)calloc((digitsSize + 1),sizeof(int));
    bool flag=false;
    for (int i=0;i<digitsSize;i++)
    {
        if (digits[i]!=9)
        {
            *returnSize=digitsSize;
            flag=true;
            break;
        }
        else
            *returnSize=digitsSize+1;
    }
    digits[digitsSize-1]++;
    if (digits[digitsSize-1] == 10 && flag==false)
    {
        for (int i=digitsSize-1;i>=0;i--)
        {
			result[i+1]+=digits[i];
			if (result[i+1]==10)
			{
				result[i+1]=0;
				result[i]++;
			}
        }
    }
    else if (digits[digitsSize-1] == 10 && flag==true)
    {
        for (int i=digitsSize-1;i>=0;i--)
        {
			result[i]+=digits[i];
			if (result[i]==10)
			{
				result[i]=0;
				result[i-1]++;
			}
        }
    }
    else
    {
        for (int i=digitsSize-1;i>=0;i--)
        {
            result[i]=digits[i];
        }
    }
    
    for (int i=0;i<*(returnSize);i++)
    {
    	printf("%d ",result[i]);
	}
}
