#include<stdio.h>
#include<math.h>
float f1(float x)
{
	return(exp(-(x*x)/2));
}
float f2(float x)
{
	return(sqrt(1+x*x));
}
float f3(float x)
{
	return(pow(cos(x),2)*sqrt(1+x*x*x));
}
int main()
{
	int n,i,a1,b1,a2,b2,a3,b3;
	float h1,h2,h3,I1,I2,I3;
	float sum1=0,sum2=0,sum3=0;
	printf("Enter the number of subintervals:\n");
	scanf("%d", &n);
	a1=0,b1=2,a2=1,b2=6,a3=-1,b3=2;
	h1=(float)(b1-a1)/n;
	h2=(float)(b2-a2)/n;
	h3=(float)(b3-a3)/n;
	for(i=1;i<n;i++)
	{
		sum1+=2*f1(a1+i*h1);
		sum2+=2*f2(a2+i*h2);
		sum3+=2*f3(a3+i*h3);
	}
	I1=(h1/2)*(f1(a1)+f1(b1)+sum1);
	printf("The value of the first integral is:%f\n",I1);
	
	I2=(h2/2)*(f2(a2)+f2(b2)+sum2);
	printf("The value of the second integral is:%f\n",I2);
	
	I3=(h3/2)*(f3(a3)+f3(b3)+sum3);
	printf("The value of the third integral is:%f\n",I3);
}
