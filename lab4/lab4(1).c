/* Note:Your choice is C IDE */
#include "stdio.h"
void main()
{
    int movRate,movNum=1;
    do{
    printf("Enter movie rating from 0 to 100: ");
    scanf("%d",&movRate);
    if(movRate<0||movRate>100){
    printf("Goodbye");
    break;}
    else if(movRate>=0&&movRate<=19){
    printf("Movie number %d rated at %d%% has 0 star: \n",movNum,movRate);
    printf("Rotten Tomatoes says this movie is ROTTEN\n\n");}
    else if(movRate>=20&&movRate<=39){
    printf("Movie number %d rated at %d%% has 1 star: *\n",movNum,movRate);
    printf("Rotten Tomatoes says this movie is ROTTEN\n\n");}
    else if(movRate>=40&&movRate<=59){
    printf("Movie number %d rated at %d%% has 2 star: **\n",movNum,movRate);
    printf("Rotten Tomatoes says this movie is ROTTEN\n\n");}
    else if(movRate>=60&&movRate<=79){
    printf("Movie number %d rated at %d%% has 3 star: ***\n",movNum,movRate);
    printf("Rotten Tomatoes says this movie is FRESH\n\n");}
    else if(movRate>=80&&movRate<=100){
    printf("Movie number %d rated at %d%% has 4 star: ****\n",movNum,movRate);
    printf("Rotten Tomatoes says this movie is FRESH\n\n");}
    movNum++;}while(movRate>=0||movRate<=100);
    
    
}