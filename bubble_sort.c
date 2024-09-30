#include <stdio.h>
void main()
{
	int n,i,ar[20],temp,count =0,space =1;
	space = 4 * sizeof(int);
	space += 20*sizeof(int);
	printf("Enter the limit :");
	scanf("%d",&n);
	printf("Enter the elements :");
	count += 4;
	for (i =0;i<n;i++){
		scanf("%d",&ar[i]);
		count++;
	}
	count++;
	for ( i = 0;i < n;i++)
	{
		for(int j = 0; j<n;j++)
		{
			if(ar[j] < ar[j+1])
			{
				temp = ar[j];	
				ar[j] = ar[j+1];
				ar[j+1] = temp;
				count += 3;
			}
			count++;
		}
		count++;
	}
	count++;
	printf("The sorted array is :");
	for (i =0;i<n;i++){
		printf("%d ",ar[i]);
		count++;
	}count+=2;
	printf("\nTime Complexity= %d\n", count);
    printf("Space Complexity: %d bytes\n", space);
	
	
}
