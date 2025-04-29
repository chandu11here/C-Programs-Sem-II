#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,j,k,s=0,count;
	float A[10][10],det,f,temp;
	printf("Enter the one dimension of the square matrix:\n");
	scanf("%d",&n);
	printf("Enter the elements of A are:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%f",&A[i][j]);
		}
	}
	det=1;
	count=0;
	for(j=0;j<n;j++)
	{
		if(A[j][j] == 0)
		{
			s=j+1;
			while(s<n && A[s][j]==0)
			{
				s=s+1;
			}
			if(s==n)
			{
				printf("A is Singular Matrix and |A| = 0");
				return 0;
			}
			for(k=0;k<n;k++)
			{
				temp=A[j][k];
				A[j][k]=A[s][k];
				A[s][k]=temp;
			}
			count+=1;
		}
		for(i=j+1;i<n;i++)
		{
			f=A[i][j]/A[j][j];
			for(k=0;k<n;k++)
			{
				A[i][k]=A[i][k]-f*A[j][k];
			}
		}
	}
	for(i=0;i<n;i++)
	{
		det*=A[i][i];
	}
	if(count%2!=0)
	{
		det=-det;
	}
	printf("The determinant of matrix A is:%0.2f",det);
}
