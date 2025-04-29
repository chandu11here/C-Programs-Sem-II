#include<stdio.h>
#include<math.h>
int main()
{
	int n,i;
	float x=0,sum=0,sumsq=0,sample_mean,sample_var,s,t1,t2;
	float lower_limit1,upper_limit1,lower_limit2,upper_limit2;
	t1=2.16;
	t2=3.012;
	printf("Enter the number of samples:\n");
	scanf("%d",&n);
	float arr[]={16,18,20,34,26,22,28,32,21,20,14,30,35,25};
	for(i=0;i<n;i++)
	{
		sum=sum+arr[i];
		sumsq=sumsq+arr[i]*arr[i];
	}
	sample_mean=sum/n;
	sample_var=(sumsq/n)-(sample_mean*sample_mean);
	s=sqrt(sample_var);
	lower_limit1=sample_mean-(t1*s/sqrt(n-1));
	upper_limit1=sample_mean+(t1*s/sqrt(n-1));
	lower_limit2=sample_mean-(t2*s/sqrt(n-1));
	upper_limit2=sample_mean+(t2*s/sqrt(n-1));
	printf("The 95%% Confidence Interval for mean is:(%f,%f)\n",lower_limit1,upper_limit1);
	printf("The 99%% Confidence Interval for mean is:(%f,%f)\n",lower_limit2,upper_limit2);
}
