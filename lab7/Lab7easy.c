/* Note:Your choice is C IDE */
#include "stdio.h"
#include "stdlib.h"
//check draw
int draw(char**board,int n){
	int i,j,flag=1;
	for(i=0;i<n;i++){
	for(j=0;j<n;j++)
	if(board[i][j]=='U')
	flag=0;}
	if(flag==1){
	printf("Draw!\n");}
	return flag;
	}
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
int checkwinner(char **board,int n){
	int i,j,longest,flag=0;
	for(i=0;i<n;i++){
	for(j=0;j<n;j++){
	longest=findLongest(board,n,i,j);
	if(longest>=6&&board[i][j]=='B'){
	printf("Black player wins.\n");
	flag=1;
	break;}
	if(longest>=6&&board[i][j]=='W'){
	printf("White player wins.\n");
	flag=1;
	break;}}
	if(flag==1) break;
	}
	return flag;
}
int Hmove(char **board,int n,char colr,int bp){
	char colr2;
	int a,b,k,f,score,min=1000;
	if(colr=='B') colr2='W';
	else colr2='B';
	for(k=0;k<n;k++){
	for(f=0;f<n;f++){
	if(board[k][f]=='U'){
	board[k][f]=colr;
	b=findLongest(board,n,k,f);
	a=bp;
	score=a-b;
	if(score<min){
		min=score;}
	board[k][f]='U';}}}
	return min;
	}
int Cmove(char **board,int n,char colr,int times,int bp){
	int i,j,k,f,max=-100,score,min;
	int a,b,p1,p2;
	char colr2;
    if(times==0) return 0;
	//find best way for human minimize score
	if(times%2!=0){
	min=Hmove(board,n,colr,bp);
	Cmove(board,n,colr2,times-1,0);
	return min;
	}
	
	if(times%2==0){
	if(colr=='B') colr2='W';
	else colr2='B';
	for(i=0;i<n;i++){
	for(j=0;j<n;j++){
	if(board[i][j]=='U'){
	if(colr=='B') board[i][j]='B';
	else board[i][j]='W';
	a=findLongest(board,n,i,j);
	//recursive call
	min=Cmove(board,n,colr2,times-1,a);
	if(min>max){
	max=min;
	p1=i;
	p2=j;}
	if(min==max){
		if(i<p1){
		p1=i;
		p2=j;}
		else if(i==p1){
			if(j<p2){
			p1=i;
			p2=j;}}}
	min=100;
	board[i][j]='U';
	}}}
	board[p1][p2]=colr;
	printf("Computer lays a stone at ROW %d COL %d.\n",p1,p2);
	return 0;
	}
	return 0;
	}
int main()
{
   	int n,row,col;
   	int a,b;
	char **board;
	char colr;
	int i,j,k;
    printf("Enter board dimensions (n): ");
    scanf("%d",&n);
    board=(char**)malloc(n*sizeof(char*));
    for(i=0;i<n;i++){
    board[i]=(char*)malloc(n*sizeof(char));}
    for(j=0;j<n;j++){
    for(k=0;k<n;k++)
    board[j][k]='U';}
    printBoard(board,n);
    printf("Computer playing B or W?: ");
    scanf(" %c",&colr); 
    if(colr=='B'){
    do{
    Cmove(board,n,colr,2,0);
    printBoard(board,n);
    a=checkwinner(board,n);
    b=draw(board,n);
    if(a==0&&b==0){
    printf("Lay down a stone (ROW COL): ");
    scanf("%d %d",&row,&col);
    if(board[row][col]=='U'){
    board[row][col]='W';
    }
    else if(board[row][col]=='B'||board[row][col]=='W'){
    do{
    printf("That square is occupied.\n");
    printf("Lay down a stone (ROW COL): ");
    scanf("%d %d",&row,&col);
    }while(board[row][col]!='U');
    board[row][col]='W';
    }
    printBoard(board,n);
    a=checkwinner(board,n);
    b=draw(board,n);
    if(a==1||b==1) break;
    }
    else break;
    }while(a==0&&b==0);}
    
    if(colr=='W'){
    	do{
    printf("Lay down a stone (ROW COL): ");
    scanf("%d %d",&row,&col);
    if(board[row][col]=='U'){
    board[row][col]='B';
    }
    else if(board[row][col]=='B'||board[row][col]=='W'){
    do{
    printf("That square is occupied.\n");
    printf("Lay down a stone (ROW COL): ");
    scanf("%d %d",&row,&col);
    }while(board[row][col]!='U');
    board[row][col]='B';
    }
    printBoard(board,n);
    a=checkwinner(board,n);
    b=draw(board,n);
    if(a==0&&b==0){
    Cmove(board,n,colr,2,0);
    printBoard(board,n);
    a=checkwinner(board,n);
    b=draw(board,n);
    if(a==1&&b==1) break;
    	}
    }while(a==0&&b==0);
    }
    return 0;
}