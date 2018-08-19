#include "stdio.h"
#include "stdlib.h"
int main () {
    double low,high,val,gap,mid,i;
    double *index;
    int *freq;
    int N,k=0,j,f;

printf("Enter the limits (low high): ");
scanf("%lf %lf",&low,&high);
printf("Enter N: ");
scanf("%d",&N);

gap=(high-low)/N;
index=(double*)malloc((N+1)*sizeof(double));
freq=(int*)malloc(N*sizeof(int));

for(i=low;i<=high;i+=gap){
index[k]=i;
k++;}
printf("Enter the values.\n");
scanf("%lf",&val);

while(val>=low&&val<=high){
for(j=0;j<N;j++){
if(val>=index[j]&&val<index[j+1])
freq[j]++;}
scanf("%lf",&val);
}
printf("The histogram values are: \n");
for(f=0;f<N;f++){
mid=(index[f]+index[f+1])/2;
printf("%.2lf %d\n",mid,freq[f]);}
return 0;
}


