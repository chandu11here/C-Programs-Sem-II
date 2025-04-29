#include<stdio.h>
#include<math.h>
int n;
void mat_vec_mult(float mat[100][100],float vec[100],float res[100])
{
	int i,j;
	
	for(i=0;i<n;i++)
	{
		res[i]=0;
		for(j=0;j<n;j++)
		{
			res[i]+=mat[i][j]*vec[j];
		}
	}
}
float vec_mag(float vec[100])
{
	int i;
	float sum=0;
	for(i=0;i<n;i++)
	{
		sum+=vec[i]*vec[i];
	}
	return(sqrt(sum));
}
void norm_vec(float vec[100])
{
	float mag=vec_mag(vec);
	for(int i=0;i<n;i++)
	{
		vec[i]=vec[i]/mag;
	}
}
float dom_eig_val(float mat[100][100],float ini_vec[100],float eig_vec[100])
{
	float new_vec[100];
	float eig_val=0;
	for(int i=0;i<n;i++)
	{
		new_vec[i]=ini_vec[i];
	}
	for(int iter=0;iter<1000;iter++)
	{
		mat_vec_mult(mat,new_vec,eig_vec);
		eig_val=vec_mag(eig_vec);
		norm_vec(eig_vec);
		float error=0;
		for(int i=0;i<n;i++)
		{
			error+=fabs(new_vec[i]-eig_vec[i]);
		}
		if(error<0.0000001)
		{
			break;
		}
		for(int i=0;i<n;i++)
		{
			new_vec[i]=eig_vec[i];
		}
	}
	return eig_val;
}
int main()
{
	int i,j;
	float mat[100][100],ini_vec[100],eig_vec[100],eig_val;
	printf("Enter the size of the Matrix:\n");
	scanf("%d",&n);
	printf("Enter the elements of the Matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%f",&mat[i][j]);
		}
	}
	printf("Enter the elements of the Initial Vector:\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&ini_vec[i]);
		eig_vec[i]=0;
	}
	eig_val=dom_eig_val(mat,ini_vec,eig_vec);
	printf("The Dominant Eigen Value is:%f\n",eig_val);
	printf("The corresponding Eigen Vector is:\n");
	for(i=0;i<n;i++)
	{
		printf("%f\n",eig_vec[i]);
	}
	return 0;
}
