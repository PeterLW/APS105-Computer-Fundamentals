#include <stdio.h>
#include <stdlib.h>
//Name: WEi Lin, student#:999595193
//the program shows a game called connect6 by using a 2D array

//find the maximun
int maximun(int x,int y,int z,int m){
	int max=0;
	if (x>=y&&x>=z&&x>=m)
	max=x;
	else if(y>=z&&y>=m)
	max=y;
	else if(z>=m)
	max=z;
	else
	max=m;
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
	int i,j,f1=1,f2=1,f3=1,f4=1;
	int a,b;
	int x,y,c,k,max;
    int t,f,s,z;

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

	for(t=row-1,f=col+1;t>=0&&f<n;t--,f++){
	if(board[row][col]==board[t][f])
	f4++;
	else break;}
	for(s=row+1,z=col-1;s<n&&z>=0;s++,z--){
	if(board[row][col]==board[s][z])
	f4++;
	else break;}

	max=maximun(f1,f2,f3,f4);
	return max;
}
void checkwinner(char **board,int n){
	int i,j,longest,flag=1;
	for(i=0;i<n;i++){
	for(j=0;j<n;j++){
	longest=findLongest(board,n,i,j);
	if(longest>=6&&board[i][j]=='B'){
	printf("Black wins.\n");
	flag=0;
	break;}
	if(longest>=6&&board[i][j]=='W'){
	printf("White wins.\n");
	flag=0;
	break;}}
	if(flag==0) break;
	}
	if(flag==1){
		printf("No winner so far\n");}
	
	}

int main()
{
	int n,row,col,longest;
	int p1,p2;
	char **board;
	char colr;
	int a,b,c,d;
	int i,j,k,x;
    printf("Enter board dimensions (n): ");
    scanf("%d",&n);
    board=(char**)malloc(n*sizeof(char*));
    for(i=0;i<n;i++){
    board[i]=(char*)malloc(n*sizeof(char));}
    for(j=0;j<n;j++){
    for(k=0;k<n;k++)
    board[j][k]='U';}
    printBoard(board,n);
    do{
    printf("Enter stone (B|W): ");
    scanf(" %c",&colr);
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
    checkwinner(board,n);}
    //printf("%d%d%d%d",a,b,c,d);
    //if(a==0&&b==0&&c==0&&d==0){
    //printf("No winner so far.\n");}
    printf("Enter an occupied position to check for contiguous stones (ROW COL): ");
    scanf("%d %d",&p1,&p2);
    while(p1>=0&&p1<n&&p2>=0&&p2<n){
    longest=findLongest(board,n,p1,p2);
    printf("Number of contiguous stones: %d\n",longest);
    printf("Enter an occupied position to check for contiguous stones (ROW COL): ");
    scanf("%d %d",&p1,&p2);
    }
    
    for(x=0;x<n;x++)
    free(board[x]);
    free(board);
return 0;
}
