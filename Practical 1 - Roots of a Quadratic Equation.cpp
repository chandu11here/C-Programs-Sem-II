#include<stdio.h>
#include<math.h>
int main()
{
    float a,b,c,d,x1,x2,x,xr,xim;
    printf("Enter the cooefficients of ax^2+bx+c \n");
    scanf("%f%f%f",&a,&b,&c);
    d=b*b-4*a*c;
    float e = sqrt(d);
    float f = sqrt(-d);
    if(d>0)
    {
        printf("Real and distinct roots\n");
        x1=(-b-e)/(2*a);
        x2=(-b+e)/(2*a);
        printf("Roots are x1=%f, x2=%f\n", x1,x2);
    }
    else if (d==0)
    {
        printf("Roots are equal\n");
        x=-b/(2*a);
        printf("Root is x=%f\n", x);
    }
    else
    {
        printf("Roots are imaginary\n");
        xr=-b/(2*a);
        xim=f/(2*a);
        printf("Roots are xr=%0.2f + i%0.2f, xr=%0.2f - i%0.2f\n",xr, xim, xr, xim);
    }
    return 0;
}
