/* Note:Your choice is C IDE */
#include "stdio.h"
#include "math.h"
double poly(double a,double b,double c,double d,double e,double x){
	double result;
	result=a*pow(x,4)+b*pow(x,3)+c*pow(x,2)+d*pow(x,1)+e;
	return result;
}
double sum(double a,double b,double c,double d,double e,double low,double high,int n){
	double x,sum=0;
	int i;
	for(i=1;i<n;i++){
	x=low+i*((high-low)/n);
	sum+=poly(a,b,c,d,e,x);}
	return sum;
	}
void main()
{
    double a,b,c,d,e,low, high,integral;
    int n;
    printf("Enter the coefficients (a b c d e): ");
    scanf("%lf %lf %lf %lf %lf",&a,&b,&c,&d,&e);
    
    printf("Enter the integral limits (low high): ");
    scanf("%lf %lf",&low,&high);
    
    printf("Enter the number of subintervals (n): ");
    scanf("%d",&n);
    
    integral=((high-low)/n)*((poly(a,b,c,d,e,low)/2)+(poly(a,b,c,d,e,high)/2)+(sum(a,b,c,d,e,low,high,n)));
    printf("The value of the integral is: %.2lf",integral);
}