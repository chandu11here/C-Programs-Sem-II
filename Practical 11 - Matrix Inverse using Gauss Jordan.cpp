#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,j,k;
	float A[100][100],I[100][100],var,f;
	
	printf("Enter the dimension of matrix A:\n");
	scanf("%d",&n);
	
	printf("Enter the elements of A:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%f",&A[i][j]);
			if(i==j)
			{
				I[i][j]=1;
			}
			else
			{
				I[i][j]=0;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		var=A[i][i];
		for(j=0;j<n;j++)
		{
			A[i][j]=A[i][j]/var;
			I[i][j]=I[i][j]/var;
		}
		for(k=0;k<n;k++)
		{
			if(k!=i)
			{
				f=A[k][i];
				for(j=0;j<n;j++)
				{
					A[k][j]=A[k][j]-f*A[i][j];
					I[k][j]=I[k][j]-f*I[i][j];
				}
			}
		}
	}
	printf("The Inverse of Matrix A is:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		printf("%0.3f\t", I[i][j]);
		}
		printf("\n");
	}
}
