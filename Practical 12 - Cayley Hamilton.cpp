#include<stdio.h>
#include<math.h>
void matrix_multiplication(float A[100][100],int m,int n,float B[100][100],int p,int q,float C[100][100])
{
	int i,j,k;
	if(n!=p)
	{
		printf("Matrix Multiplication is not possible");
	}
	else
	{
		for(i=0;i<m;i++)
		{
			for(j=0;j<q;j++)
			{
				C[i][j]=0;
				for(k=0;k<p;k++)
				{
					C[i][j]+=A[i][k]*B[k][j];
				}
			}
		}
	}
}
int main()
{
	int n,i,j,k,count=0;
	float A[100][100],A2[100][100],A3[100][100],A4[100][100],I[100][100],sol[100][100];
	printf("Enter the order of the matrix A:\n");
	scanf("%d",&n);
	printf("Enter the elements of Matrix A:\n");
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
	matrix_multiplication(A,n,n,A,n,n,A2);
	matrix_multiplication(A,n,n,A2,n,n,A3);
	matrix_multiplication(A2,n,n,A2,n,n,A4);
	printf("\nMatrix (A^4-8A^3+21A^2-20A+5I)\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			sol[i][j]=A4[i][j]-8*A3[i][j]+21*A2[i][j]-20*A[i][j]+5*I[i][j];
			if(sol[i][j]==0)
			{
				count+=1;
				printf("%f\t",sol[i][j]);
			}
		}
		printf("\n");
	}
	if(count==n*n)
	{
		printf("Cayley Hamilton Theorem has been verified");
	}
	else
	{
		printf("Cayley Hamilton Theorem has not been verified");
	}
}

