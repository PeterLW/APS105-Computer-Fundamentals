/* Note:Your choice is C IDE */
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
//find the maximun
int maximun(int x,int y,int z){
	int max=0;
	if (x>=y&&x>=z)
	max=x;
	else if(y>=z)
	max=y;
	else
	max=z;
	return max;
	}
//print a 2D array
void printBoard(char **board, int n){
	int i,j;
	for(i=0;i<n;i++){
	for(j=0;j<n;j++){
	printf("%c",board[i][j]);}
	printf("\n");}
}
//find longest 
int findLongest(char **board, int n, int row, int col){
	int i,j,f1=1,f2=1,f3=1;
	int a,b;
	int x,y,c,k,max;
	
	for(i=row+1;i<n;i++){
	if(board[row][col]==board[i][col])
	f1++;
	else break;}
	for(j=row-1;j>=0;j--){
	if(board[row][col]==board[j][col])
	f1++;
	else break;}
	
	for(a=col+1;a<n;a++){
	if(board[row][col]==board[row][a])
	f2++;
	else break;}
	for(b=col-1;b>=0;b--){
	if(board[row][col]==board[row][b])
	f2++;
	else break;}
	
	for(x=row+1,y=col+1;x<n&&y<n;x++,y++){
	if(board[row][col]==board[x][y])
	f3++;
	else break;}
	for(c=row-1,k=col-1;c>=0&&k>=0;c--,k--){
	if(board[row][col]==board[c][k])
	f3++;
	else break;}
	max=maximun(f1,f2,f3);
	return max;
}
//check horizontal
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
		printf("Black win.\n");
		break;}
		if(flag==1&&board[i][j]=='W'){
		printf("White win.\n");
		break;}
}
	if(flag==1)
	break;
	}
	return flag;
}
//check vertical
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
	printf("Black win.\n");
	break;}
	if(flag==1&&board[i][j]=='W'){
	printf("White win.\n");
	break;}
	}
	}
	if(flag==1)
	break;
    }
    return flag;
}
//check diagnal
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
	printf("Black win.\n");
	break;}
	if(flag==1&&board[i][j]=='W'){
	printf("White win.\n");
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
	int n,row,col,longest;
	int p1,p2;
	char **board;
	char colr;
	int a,b,c;
	int i,j,k;
    printf("Enter board dimensions (n): ");
    scanf("%d",&n);
    //makeBoard(board,n);   
    board=(char**)malloc(n*sizeof(char*));
    for(i=0;i<n;i++){
    board[i]=(char*)malloc(n*sizeof(char));}
    for(j=0;j<n;j++){
    for(k=0;k<n;k++)
    board[j][k]='U';}
    printBoard(board,n); 
    do{
    getchar(); 
    printf("Enter stone (B|W): ");
    scanf("%c",&colr);
    getchar();
    if(colr!='E'){
    printf("Enter position (ROW COL): ");
    scanf("%d %d",&row,&col);
    if(board[row][col]=='U'){
    board[row][col]=colr;}
    else if(board[row][col]=='B'||board[row][col]=='W'){
    printf("Position is taken, try another move.\n");}
    printBoard(board,n);
    }
    }while(colr!='E');

    if(colr=='E'){
    a=checkH(board,n);
    b=checkV(board,n);
    c=checkD(board,n);
    if(a==0&&b==0&&c==0){
    printf("No winner so far.\n");}
    printf("Enter an occupied position to check for contiguous stones (ROW COL): ");
    scanf("%d %d",&p1,&p2);
    while(p1>=0&&p1<n&&p2>=0&&p2<n){
    longest=findLongest(board,n,p1,p2);
    printf("Number of contiguous stones: %d\n",longest);
    printf("Enter an occupied position to check for contiguous stones (ROW COL): ");
    scanf("%d %d",&p1,&p2);
    }
    }
}