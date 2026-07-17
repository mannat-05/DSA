#include <stdio.h>
//Logic:elements left of the pivot should be less than the pivot and to the right must be greater than pivot.
void swap(int *a,int *b) 
{
    int temp=*a;
    *a =*b;
    *b=temp;
}

void Q_sort(int *nums,int left,int right)
{
    int base=nums[right];	
    int j=left-1;
    if(left<right)
	{
        for(int i=left;i<right;i++)
		{
            if(base>nums[i])
			{
                j++;
                swap(&nums[j],&nums[i]);	//Swapping the ith and jth value indices.
            }
        }
        //Recursive call begins....
        swap(&nums[j+1],&nums[right]);		//This swapping ensures correct position of pivot at (j+1) in the array.
        Q_sort(nums,left,j);	//Recursive call for again sorting left side.
        Q_sort(nums,j+2,right);	//Recursive call for again sorting right side.
    }
}

main() 
{
	int nums[5]={12,3,4,45,19};
	int numsSize=5;
    Q_sort(nums,0,numsSize-1);	//Assigning left and right with extreme values.
    printf("Sorted Array:");
    for (int i=0;i<numsSize;i++)
    {
    	printf("%d ",nums[i]);
	}
}
