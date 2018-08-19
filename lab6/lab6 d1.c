/* Note:Your choice is C IDE */
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

void makeBoard(char **board, int n){
int i,j,k;
board=(char**)malloc(n*sizeof(char*));
for(i=0;i<n;i++){
board[i]=(char*)malloc(n*sizeof(char));}
for(j=0;j<n;j++){
for(k=0;k<n;k++){
board[j][k]='U';}
}
}

void printBoard(char **board, int n){
	int i,j;
	for(i=0;i<n;i++){
	for(j=0;j<n;j++){
	printf("%c",board[i][j]);}
	printf("\n");}
}

int findLongest(char **board, int n, int row, int col){
	
}

int checkH(char **board, int n){
	int i,j,k,flag;
	for(i=0;i<n;i++){
	for(j=0;j<n;j++){
	if(board[i][j]!='U'){
		flag=1;
		for(k=j+1;k<n&&k-j<6&&flag==1;k++){
		if(board[i][j]!=board[i][k])
		flag=0;}
}
		if(flag==1&&board[i][j]=='B'){
		printf("Black win");
		break;}
		if(flag==1&&board[i][j]=='W'){
		printf("White win");
		break;}
}
	if(flag==1)
	break;
	}
	return flag;
}
int checkV(char **board, int n){
	int i,j,k,flag;
    for(i=0;i<n;i++){
	for(j=0;j<n;j++){
	if(board[i][j]!='U'){
	flag=1;
    for(k=i+1;k<n&&k-j<6&&flag==1;k++){
	if(board[i][j]!=board[k][j])
	flag=0;}
	if(flag==1&&board[i][j]=='B'){
	printf("Black win");
	break;}
	if(flag==1&&board[i][j]=='W'){
	printf("White win");
	break;}
	}
	}
	if(flag==1)
	break;
    }
    return flag;
	}
int checkD(char **board,int n){
	int i,j,k,h,flag;
    for(i=0;i<n;i++){
	for(j=0;j<n;j++){
			flag=1;
	if(board[i][j]!='U'){
    for(k=j+1,h=i+1;k<n&&k-j<6&&h-i<6&&flag==1;k++,h++){
	if(board[i][j]!=board[h][k])
	flag=0;}
	if(flag==1&&board[i][j]=='B'){
	printf("Black win");
	break;}
	if(flag==1&&board[i][j]=='W'){
	printf("White win");
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
	int n,row,col;
	int p1,p2;
	char **board;
	char colr;
	int a,b,c;
    printf("Enter board dimensions (n): ");
    scanf("%d",&n);
    makeBoard(board,n);
    
    do{
    printf("Enter stone (B|W): ");
    scanf("%c",&colr);
    printf("Enter position (ROW COL): ");
    scanf("%d %d",&row,&col);
    if(colr!='E'){
    if((colr=='B'||colr=='W')&&board[row][col]=='U')
    board[row][col]=colr;
    else
    printf("Position is taken, try another move.\n");
    }
    printBoard(board,n);
    }while(colr!='E');

    if(colr=='E'){
    a=checkH(board,n);
    b=checkV(board,n);
    c=checkD(board,n);
    if(a==0&&b==0&&c==0){
    printf("No winner so far.\n");}
    printf("Enter an occupied position to check for contiguous stones (ROW COL): ");
    scanf("%d %d",&p1,&p2);
    findLongest(board,n,p1,p2);}
}