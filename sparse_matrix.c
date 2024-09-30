#include <stdio.h>
void main()
{
	int sparse[5][5],triplet[10][3],i,j,k=1,col,row;
	printf("Enter the number of rows :");
	scanf("%d",&row);
	printf("Enter the number of columns :");
	scanf("%d",&col);
	printf("Enter the elements of the matrix :");
	for (i = 0;i<row;i++)
	{
		for(j = 0;j<col;j++)
		{	
			scanf("%d", &sparse[i][j]);
		}	
	}
	for(i = 0;i<row;i++)
	{
		for(j = 0;j<col;j++)
		{
			if(sparse[i][j] != 0)
			{
				triplet[k][0] = i;
				triplet[k][1] = j;
				triplet[k][2] = sparse[i][j];
				k++;
			}
		}
	}
	triplet[0][0] = row;
	triplet[0][1] = col;
	triplet[0][2] = k-1;
	
	printf("Sparse matrix:");
	for (i = 0;i<row;i++)
	{ printf("\n");
		for(j = 0;j<col;j++)
		{	
			printf("%d, ", sparse[i][j]);
		}	
	}
	printf("\n");
	printf("triplet representation :\n");
	printf("row\tcol\tvalue\n");
	for(i = 0;i<k;i++)
	{
		printf("%d\t%d\t%d\n",triplet[i][0],triplet[i][1],triplet[i][2]);
	}
}
