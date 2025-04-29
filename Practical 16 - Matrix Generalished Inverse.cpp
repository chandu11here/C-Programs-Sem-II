#include<stdio.h>
#include<math.h>
int main()
{
	int m,n,i,j;
	float A[100][100],B[2][2],B_det,B_inv[2][2],G[100][100];
	printf("Enter the number of rows of Matrix A:\n");
	scanf("%d",&m);
	printf("Enter the number of columns of Matrix A:\n");
	scanf("%d",&n);
	printf("Enter the elements of Matrix A:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			{
				scanf("%f",&A[i][j]);
			}
	}
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
			{
				B[i][j]=A[i][j];
			}
	}
	B_det=B[0][0]*B[1][1]-B[1][0]*B[0][1];
	B_inv[0][0]=(B[1][1]/B_det);
	B_inv[1][0]=-(B[1][0]/B_det);
	B_inv[0][1]=-(B[0][1]/B_det);
	B_inv[1][1]=(B[0][0]/B_det);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			{
				G[i][j]=0.0;
			}
	}
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
			{
				G[i][j]=B_inv[i][j];
			}
	}
	printf("The Generalised Inverse of A is:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			{
				printf("%0.3f\t",G[i][j]);
			}
			printf("\n");
	}
	return 0;
}
