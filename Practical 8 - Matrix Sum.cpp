#include<stdio.h>
#include<math.h>
int main()
{
	int i,j,m,n,p,q;
	int A[10][10], B[10][10],C[10][10];
	printf("Enter the number of rows in 1st matrix:\n");
	scanf("%d",&m);
	printf("Enter the number of columns in 1st matrix:\n");
	scanf("%d",&n);
	printf("Enter the number of rows in 2nd matrix:\n");
	scanf("%d",&p);
	printf("Enter the number of columns in 2nd matrix:\n");
	scanf("%d",&q);
	if(m!=p && n!=q)
	{
		printf("Matrix addition is not possible.");
	}
	else
	{
		printf("Enter the elements of 1st matrix:\n");
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&A[i][j]);
			}
		}
		printf("Enter the elements of 2nd matrix:\n");
		for(i=0;i<p;i++)
		{
			for(j=0;j<q;j++)
			{
				scanf("%d",&B[i][j]);
			}
		}
		printf("The resultant matrix is:\n");
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				C[i][j]=A[i][j]+B[i][j];
				printf("%d\t",C[i][j]);
			}
			printf("\n");
		}
	}

}

