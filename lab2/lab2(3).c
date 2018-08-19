/* Note:Your choice is C IDE */
#include "stdio.h"
#include "math.h"
void main()
{
	double x,y,h,a,pi;
	pi=3.1415926;
    printf("Enter X: ");
    scanf("%lf",&x);
    printf("Enter Y: ");
    scanf("%lf",&y);
    h=sqrt(x*x+y*y);
    a=180/pi*asin(y/h);
    printf("\nThe Hypotenuse Length is: %5.1lf\n",h);
    printf("The Angle Theta is: %5.1lf",a,"degrees\n");
}