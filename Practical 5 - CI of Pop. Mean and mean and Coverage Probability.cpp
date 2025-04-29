#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int i,j,k;
	float mu,sigma2,z,mean,var,x,countmu=0,countsigma2=0;
	float lower_limit_mu[500],upper_limit_mu[500],lower_limit_sigma2[500],upper_limit_sigma2[500];
	float sum_lower_limit_mu=0,sum_upper_limit_mu=0,sum_lower_limit_sigma2=0,sum_upper_limit_sigma2=0;
	printf("Enter the value of populatin mean:\n");
	scanf("%f",&mu);
	printf("Enter the value of populatin variance:\n");
	scanf("%f",&sigma2);
	for(k=0;k<200;k++)
	{
		float sum=0,sum_sq=0;
		for(j=0;j<25;j++)
		{
			float u=0;
			for(i=0;i<500;i++)
			{
				u=u+rand()/(1.0+RAND_MAX);
			}
			z=(u-(500.0/2))/sqrt(500.0/12);
			x=mu+z*sqrt(sigma2);
			sum=sum+x;
			sum_sq=sum_sq+x*x;
		}
		mean=sum/25;
		var=sum_sq/25-mean*mean;
		lower_limit_mu[k]=mean-1.96*sqrt(var/25);
		upper_limit_mu[k]=mean+1.96*sqrt(var/25);
		lower_limit_sigma2[k]=25*var/39.364;
		upper_limit_sigma2[k]=25*var/12.401;
		sum_lower_limit_mu+=lower_limit_mu[k];
		sum_upper_limit_mu+=upper_limit_mu[k];
		sum_lower_limit_sigma2+=lower_limit_sigma2[k];
		sum_upper_limit_sigma2+=upper_limit_sigma2[k];
		if(lower_limit_mu[k] < mu && upper_limit_mu[k] > mu)
		{
			countmu+=1;
		}
		if(lower_limit_sigma2[k] < sigma2 && upper_limit_sigma2[k] > sigma2)

		{
			countsigma2+=1;
		}
	}
	printf("The 95%% CI for population mean is: (%f,%f)\n",sum_lower_limit_mu/200,sum_upper_limit_mu/200);
	printf("The 95%% CI for population sigma2 is: (%f,%f)\n",sum_lower_limit_sigma2/200,sum_upper_limit_sigma2/200);
	float coveragemu=countmu/200;
	float coveragesigma2=countsigma2/200;
	printf("The Coverage Probability for population mean is: %f\n",coveragemu);
	printf("The Coverage Probability for population variance is: %f\n",coveragesigma2);
}
