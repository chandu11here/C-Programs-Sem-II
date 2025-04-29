#include<stdio.h>
#include<math.h>
void matrix_multiplication(float A[1][2],int m,int n,float B[2][2],int p,int q,float C[1][2])
{
	int i,j,k;
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
int main()
{
	int i,j;
	float TPM[2][2],ISV[1][2],S_after[1][2],S_temp[1][2];
	printf("Enter the elements of the Transition Probability Matrix:\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			scanf("%f",&TPM[i][j]);
		}
	}
	printf("Enter the Initial State Vector:\n");
	for(i=0;i<1;i++)
	{
		for(j=0;j<2;j++)
		{
			scanf("%f",&ISV[i][j]);
		}
	}
	matrix_multiplication(ISV,1,2,TPM,2,2,S_temp);
	matrix_multiplication(S_temp,1,2,TPM,2,2,S_after);
	printf("The Transition Probability Matrix is:\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%f\t",TPM[i][j]);
		}
		printf("\n");
	}
	printf("The number of students doing Mathematics after two periods are %f\n", 100*S_after[0][0]);
	printf("The number of students doing English after two periods are %f\n", 100*S_after[0][1]);
	return 0;
}
