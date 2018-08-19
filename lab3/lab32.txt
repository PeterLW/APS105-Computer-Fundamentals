/* Note:Your choice is C IDE */
#include "stdio.h"
#include "math.h"
void main()
{
	const double PI=3.1415926;
	char operatr;
	double degree,result,rad;
    printf("Enter the desired operation:\n");
    scanf("%c",&operatr);
    if(operatr!='s'&&operatr!='c'&&operatr!='t'&&operatr!='e'&&operatr!='n')
    printf("This operation is not supported.");
    else
    printf("Enter the angle in degrees:\n");
    scanf("%lf",&degree);
    rad=degree/180*PI;
    //sine
    if(operatr=='s'){
      result=sin(rad);
      printf("The sine of %.2lf RAD is %.2lf.",rad,result);}
    //cosine
    if(operatr=='c'){
      result=cos(rad);
      printf("The cosine of %.2lf RAD is %.2lf.",rad,result);}
    //tangent
    if(operatr=='t'&&(int)degree%90!=0){
      result=tan(rad);
      printf("The tangent of %.2lf RAD is %.2lf.",rad,result);}
    if(operatr=='t'&&(int)degree%90==0){
      printf("The tangent of %.2lf RAD is undefined.",rad);}
    //exponential
    if(operatr=='e'){
      result=exp(degree);
      printf("The exponential of %.2lf is %.2lf.",degree,result);}
    //Natural Logarithm
    if(operatr=='n'){
      result=log(degree);
      printf("The Natural Logarithm of %.2lf is %.2lf.",degree,result);}
    
}