#include<stdio.h>
#include<math.h>
float f1(float x)
{
	return x*x*x*x - x*x*x + x - 1;
}
float f11(float x)
{
	return 4*x*x*x - 3*x*x + 1;
}
int main()
{
	float xo,x1;
	printf("Enter the initial guess, x0:\n");
	scanf("%f",&xo);
	do
	{
		x1=xo-f1(xo)/f11(xo);
		if(fabs(x1-xo)<0.0000001)
		{
			break;
		}
		xo=x1;
	}
	while(1);
	printf("The real root is:%.10f\n",x1);
	return 0;
}
