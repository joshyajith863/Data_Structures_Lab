#include <stdio.h>
struct term
{
	int coefficient;
	int exponent;};
int main(){
	struct term p1[10],p2[10],p3[10];
	int n1,n2,n3;
	int i,j,k=0;
	printf("Enter the degree of the first polynomial :");
	scanf("%d",&n1);
	printf("Enter the degree of the second polynoial :");
	scanf("%d",&n2);
	printf("Enter the first polynomial (Coefficients and Exponents ):");
	for(i =0;i<n1;i++)
	{
		scanf("%d",&p1[i].coefficient);
		scanf("%d",&p1[i].exponent);
		
	}
	printf("Enter the second polynomial (Coefficients and Exponents ):");
	for(i =0;i<n1;i++)
	{
		scanf("%d",&p2[i].coefficient);
		scanf("%d",&p2[i].exponent);
	}
	i =0;
	j =0;
	k =0;
	while(i < n1 && j <n2)
	{
		if(p1[i].exponent > p2[j].exponent)
		{
			p3[k].coefficient = p1[i].coefficient;
			p3[k].exponent = p1[i].exponent;
			i++;
			k++;
		}
		else if(p1[i].exponent < p2[j].exponent)
		{
			p3[k].coefficient = p2[j].coefficient;
			p3[k].exponent = p2[j].exponent;
			j++;
			k++;
		}
		else
		{
			p3[k].coefficient = p1[i].coefficient + p2[j].coefficient;
			p3[k].exponent = p1[i].exponent;
			i++;
			j++;
			k++;
		}
	}
	while(i < n1)
	{
		p3[k].coefficient = p1[i].coefficient;
		p3[k].exponent = p1[i].exponent;
		i++;
		k++;
	}
	while(j<n2)
	{
		p3[k] = p2[j];
		j++;
		k++;
	}
	n3 = k;
	printf("Resultant polynomial :");
	for (k=0;k<n3;k++)
	{
		printf("%dx^(%d)",p3[k].coefficient,p3[k].exponent);
		if(k < n3 -1 && p3[k+1].coefficient >= 0){
			printf("+");
		}
	}
	printf("\n");
	return 0;
	}
	

