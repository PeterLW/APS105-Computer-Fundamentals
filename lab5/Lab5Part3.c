/* Note:Your choice is C IDE */
#include "stdio.h"
#include "math.h"
double fac(double n){
double i,sum=1;
for(i=1;i<=2*n+1;i++)
sum=sum*i;
return sum;
}

double approxSine(double x, int N){
int i;
double sum=0;
for(i=0;i<N;i++)
sum+=(pow(-1,i)/fac(i))*pow(x,2*i+1);
return sum;
}

void main()
{
	int N;
	double i,low,high,step,result;
    printf("Enter N: ");
    scanf("%d",&N);
    printf("Enter low: ");
    scanf("%lf",&low);
    printf("Enter high: ");
    scanf("%lf",&high);
    printf("Enter step: ");
    scanf("%lf",&step);
    for(i=low;i<=high;i+=step){
    result=approxSine(i,N);
    printf("%.2lf %.2lf\n",i,result);}
    
}