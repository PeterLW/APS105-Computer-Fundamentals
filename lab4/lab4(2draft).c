/* Note:Your choice is C IDE */
#include "stdio.h"
#include "math.h"
void main()
{
int i,m,n,a,b,j,g=0; 
scanf("%d",&n);
 
if(n<=0)
printf("All Done.");

else if(n>0&&n<4)
printf("The Integer %d is not Semiprime",n);

else if(n>=4){
for(m=2;m<n;m++){       
for(i=2;i<=sqrt(m);i++){
 if(m%i==0)
   break;}
if(i>sqrt(m)&&sqrt(m)!=1){
a=m;
if(n%a==0){
b=n/a;
for(j=2;j<=sqrt(b);j++)
 if(b%j==0)
   break;
if(j>sqrt(b)&&sqrt(b)!=1)
printf("The Integer %d is Semiprime, with the two primes being %d and %d",n,a,b);
g++; 
}
}
}
}
printf("The Integer %d is not Semiprime",n);
}