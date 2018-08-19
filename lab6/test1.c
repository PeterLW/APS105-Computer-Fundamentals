/* Note:Your choice is C IDE */
#include "stdio.h"
#include "stdlib.h"
int checkD2(char **board,int n){
	int i,j,flag,a,b;
    for(i=0;i<n;i++){
	for(j=0;j<n;j++){
	if(board[i][j]!='U'){
    flag=1;
	if(j-6<0||i+6>n)
	flag=0;
	else{
    for(a=j-1,b=i+1;a>=0&&j-a<6&&b<n&&b-i<6&&flag==1;a--,b++){
    if(board[i][j]!=board[b][a])
    flag=0;}
	}
	if(flag==1&&board[i][j]=='B'){
	printf("Black wins.\n");
	break;}
	if(flag==1&&board[i][j]=='W'){
	printf("White wins.\n");
	break;}
	}
	}
	if(flag==1)
	break;
    }
    return flag;
    }
void main()
{
char **board; int n;
int a;
int i,j,k,s,f;
scanf("%d",&n);
board=(char**)malloc(n*sizeof(char*));
for(i=0;i<n;i++){
board[i]=(char*)malloc(n*sizeof(char));}

for(j=0;j<n;j++){
for(k=0;k<n;k++){
if(k!=n-j-1)
board[j][k]='U';
else
board[j][k]='W';
}}
board[0][9]='U';
board[1][8]='U';
for(s=0;s<n;s++){
for(f=0;f<n;f++){
	printf("%c",board[s][f]);}
printf("\n");}
a=checkD2(board,n);
printf("%d",a);
}