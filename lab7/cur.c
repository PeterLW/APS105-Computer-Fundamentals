/* Note:Your choice is C IDE */
#include "stdio.h"
#include "stdlib.h"
//check draw
draw(char**board,int n){
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
//check horizontal
int checkH(char **board, int n){
	int i,j,k,flag;
	for(i=0;i<n;i++){
	for(j=0;j<n;j++){
	if(board[i][j]!='U'){
		flag=1;
		if(j+6>n)
		flag=0;
		else
		for(k=j+1;k<n&&k-j<6&&flag==1;k++){
		if(board[i][j]!=board[i][k])
		flag=0;}
}
		if(flag==1&&board[i][j]=='B'){
		printf("Black player wins.\n");
		break;}
		if(flag==1&&board[i][j]=='W'){
		printf("White player wins.\n");
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
	if(i+6>n)
	flag=0;
	else
    for(k=i+1;k<n&&k-j<6&&flag==1;k++){
	if(board[i][j]!=board[k][j])
	flag=0;}
	if(flag==1&&board[i][j]=='B'){
	printf("Black player wins.\n");
	break;}
	if(flag==1&&board[i][j]=='W'){
	printf("White player wins.\n");
	break;}
	}
	}
	if(flag==1)
	break;
    }
    return flag;
}
//check diagnal
int checkD1(char **board,int n){
	int i,j,k,h,flag;
    for(i=0;i<n;i++){
	for(j=0;j<n;j++){
	if(board[i][j]!='U'){
    flag=1;
	if(i>n-6||j>n-6)
	flag=0;
	else{
    for(k=j+1,h=i+1;k<n&&k-j<6&&h<n&&h-i<6&&flag==1;k++,h++){
	if(board[i][j]!=board[h][k])
	flag=0;}
	}
	if(flag==1&&board[i][j]=='B'){
	printf("Black player wins.\n");
	break;}
	if(flag==1&&board[i][j]=='W'){
	printf("White player wins.\n");
	break;}
	}
	}
	if(flag==1)
	break;
    }
    return flag;
}
int checkD2(char **board,int n){
	int i,j,flag,a,b;
    for(i=0;i<n;i++){
	for(j=0;j<n;j++){
	if(board[i][j]!='U'){
    flag=1;
    if(j==0){flag=0;}
	if(j-6<0||i+6>n){
	flag=0;}
	else{
    for(a=j-1,b=i+1;a>=0&&j-a<6&&b<n&&b-i<6&&flag==1;a--,b++){
    if(board[i][j]!=board[b][a])
    flag=0;}
	}
	if(flag==1&&board[i][j]=='B'){
	printf("Black player wins.\n");
	break;}
	if(flag==1&&board[i][j]=='W'){
	printf("White player wins.\n");
	break;}
	}
	}
	if(flag==1)
	break;
    }
    return flag;
}
int Cmove(char **board,int n,char colr,int times,int bp){
	int i,j,k,f,max=-100,score,min=100;
	int a,b,p1,p2;
	char colr2;

	//find best way for human minimize score
	if(times==1){
	for(k=0;k<n;k++){
	for(f=0;f<n;f++){;
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
	
	if(times==2){
	if(colr=='B') colr2='W';
	else colr2='B';
	for(i=0;i<n;i++){
	for(j=0;j<n;j++){
	if(board[i][j]=='U'){
	if(colr=='B') board[i][j]='B';
	else board[i][j]='W';
	a=findLongest(board,n,i,j);
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
	board[p1][p2]='B';
	printf("Computer lays a stone at ROW %d COL %d.\n",p1,p2);
	return 0;
	}
	return 0;
	}
void main()
{
   	int n,row,col;
   	int a,b,c,d,e;
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
    a=checkH(board,n);
    b=checkV(board,n);
    c=checkD1(board,n);
    d=checkD2(board,n);
    e=draw(board,n);
    if(a+b+c+d+e==0){
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
    a=checkH(board,n);
    b=checkV(board,n);
    c=checkD1(board,n);
    d=checkD2(board,n);
    e=draw(board,n);
    if(a+b+c+d+e!=0) break;
    }
    else break;
    }while(a+b+c+d+e==0);}
    
    if(colr=='W'){
    	do{
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
    a=checkH(board,n);
    b=checkV(board,n);
    c=checkD1(board,n);
    d=checkD2(board,n);
    e=draw(board,n);
    if(a+b+c+d+e==0){
    Cmove(board,n,colr,2,0);
    printBoard(board,n);
    a=checkH(board,n);
    b=checkV(board,n);
    c=checkD1(board,n);
    d=checkD2(board,n);
    e=draw(board,n);
    if(a+b+c+d+e!=0) break;
    	}
    }while(a+b+c+d+e==0);
    }
}