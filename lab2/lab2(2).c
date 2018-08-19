/* Note:Your choice is C IDE */
#include "stdio.h"
void main()
{
	int a,b,c,d,md,d1,d2,ld;
    printf("Enter number to convert to base 2: ");
    scanf("%d",&a);
    ld=a%2;
    b=a/2;
    d2=b%2;
    c=b/2;
    d1=c%2;
    d=c/2;
    md=d%2;
    printf("The four digits of that number are as follows: \n");
           printf("Most significant digit: %d\n", md);
           printf("Next digit: %d\n", d1);
           printf("Next digit: %d\n", d2);
           printf("Least significant digit: %d\n", ld);
           
}