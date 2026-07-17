#include <stdio.h>
  
int binary(int n)
{
	int r;
	if(n==0) 
		return 1;
	else
	{
		r=n%2;
		n=n/2;
	    binary(n);
	    printf("%d",r);
	}
}
  
int main()
{
	int n;
	printf("Enter the number to be converted:");
	scanf("%d",&n);
	binary(n);
}

