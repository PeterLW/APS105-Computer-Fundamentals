/* Note:Your choice is C IDE */
#include "stdio.h"
#include "math.h"
void main()
{
int i,j,m,Num,prime1,prime2,flag=0; 
printf("Enter input integer above 0: ");
scanf("%d",&Num);

if(Num<=0)
printf("All Done.");

else if(Num>0&&Num<4)
printf("The Integer %d is not Semiprime",Num);

else if(Num>=4){
for(m=2;m<Num;m++){       
for(i=2;i<=sqrt(m);i++){
 if(m%i==0)
   break;}
if(i>sqrt(m)&&sqrt(m)!=1){
prime1=m;
if(Num%prime1==0){
prime2=Num/prime1;
for(j=2;j<=sqrt(prime2);j++)
 if(prime2%j==0)
   break;
if(j>sqrt(prime2)&&sqrt(prime2)!=1){
printf("The Integer %d is Semiprime, with the two primes being %d and %d",Num,prime1,prime2);
flag++; 
break;}
}
}
}
}
if(flag==0){
printf("The Integer %d is not Semiprime",Num);}
}