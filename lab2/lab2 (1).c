/* Note:Your choice is C IDE */
#include "stdio.h"
void main()
{
	double a,b,c;
printf("Enter conversion rate: ");
scanf("%lf",&a);
printf("Enter amount to be converted (in foreign currency): ");
scanf("%lf",&b);
c=a*b;
printf("\nThe amount in Canadian Dollars is: %5.2lf\n",c);
}