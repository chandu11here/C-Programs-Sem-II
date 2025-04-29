#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,j,k,s=0,count;
	float A[10][10],x[10],det,f,temp;
	printf("Enter the one dimension of the square matrix:\n");
	scanf("%d",&n);
	printf("Enter the elements of augmented matrix A|b:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n;j++)
		{
			scanf("%f",&A[i][j]);
		}
	}
	det=1;
	count=0;
	for(j=0;j<n;j++)
	{
		if(fabs(A[j][j]) < 1e-6)
		{
			s=j+1;
			while(s<n && fabs(A[s][j]) < 1e-6)
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
			for(k=0;k<=n;k++)
			{
				A[i][k]=A[i][k]-f*A[j][k];
			}
		}
	}
	// Back Substitution
    for(i=n-1; i>=0; i--)
    {
        x[i]=A[i][n];
        for(j=i+1; j<n; j++)
        {
            x[i]=x[i]-A[i][j]*x[j];
        }
        x[i]=x[i]/A[i][i];
    }

    printf("\nThe solution of the system is:\n");
    for(i=0; i<n; i++)
    {
        printf("x[%d] = %f\n",i+1,x[i]);
    }

    return 0;
}
