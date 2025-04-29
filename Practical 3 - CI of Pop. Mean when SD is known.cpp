#include<stdio.h>
#include<math.h>
int main()
{
	int n,i;
	float s_mean=0,sd,z1,z2,x=0;
	float lower_limit1,upper_limit1,lower_limit2,upper_limit2;
	sd=3;
	z1=1.96;
	z2=2.58;
	printf("Enter the sample size:\n");
	scanf("%d",&n);
	float arr[]={72,69,71,70,62,64,67,69,73,82,75,70,69,78,73,70,91,59,85,74};
	for(i=0;i<n;i++)
	{
		x=x+arr[i];
	}
	s_mean=x/n;
	printf("Sample Mean is:%f\n",s_mean);
	
	lower_limit1 = s_mean - z1 * (sd / sqrt(n));
    upper_limit1 = s_mean + z1 * (sd / sqrt(n));

    lower_limit2 = s_mean - z2 * (sd / sqrt(n));
    upper_limit2 = s_mean + z2 * (sd / sqrt(n));

    printf("The 95%% Confidence Interval for mean is: (%f, %f)\n", lower_limit1, upper_limit1);
    printf("The 99%% Confidence Interval for mean is: (%f, %f)\n", lower_limit2, upper_limit2);
    
	printf("For 95% CI:\n");
	if(lower_limit1<75 && upper_limit1>75)
	{
		printf("It is resonable to conclude that the mean exam score is 75\n");
	}
	else
	{
		printf("It is not resonable to conclude that the mean exam score is 75\n");
	}
	printf("For 99% CI:\n");
	if(lower_limit2<75 && upper_limit2>75)
	{
		printf("It is resonable to conclude that the mean exam score is 75\n");
	}
	else
	{
		printf("It is not resonable to conclude that the mean exam score is 75\n");
	}
}

