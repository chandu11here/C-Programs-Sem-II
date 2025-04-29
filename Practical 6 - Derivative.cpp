#include<stdio.h>
#include<math.h>
float fx(float x1)
{
	return(5*x1 + pow(x1,2));
}
float gx(float x2)
{
	return(6*pow(x2,4) - 2*pow(x2,3) + x2 -1);
}
float hx(float x3)
{
	return(x3*exp(x3*x3));
}
int main()
{
	float x1,x2,x3,d1,d2,d3,h;
	h=0.00001;
	
	printf("Enter the value of x1:\n");
	scanf("%f",&x1);
	d1=(fx(x1+h)-fx(x1))/h;
	printf("f'(x)=%f\n",d1);
	
	printf("Enter the value of x2:\n");
	scanf("%f",&x2);
	d2=(gx(x2+h)-gx(x2))/h;
	printf("g'(x)=%f\n",d2);
	
	printf("Enter the value of x3:\n");
	scanf("%f",&x3);
	d3=(hx(x3+h)-hx(x3))/h;
	printf("h'(x)=%f\n",d3);
	
}
