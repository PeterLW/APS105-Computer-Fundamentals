#include "stdio.h"
#include "stdlib.h"
//Name: Wei Lin, student#:999595193
//the program scanf a list of number and output the numbers in descending order
int main()
{
	typedef struct list{
		int num;
		struct list *link;
	}linklist;
	int len=0,i;
	linklist *listhead=NULL,*listtail=NULL;
	linklist *newnum,*currentnum;
	linklist *cnum1,*cnum2,*cnum3;
    do{
    	newnum=(linklist*)malloc(sizeof(linklist));
    	printf("Enter Number (-1 to finish): ");
    	scanf("%d",&newnum->num);
    	if(newnum->num!=-1){
    	if(listhead==NULL){
    	newnum->link=NULL;
    	listhead=newnum;
    	listtail=newnum;}
    	else{
    	newnum->link=NULL;
    	listtail->link=newnum;
    	listtail=newnum;}
    	len++;}
    }while(newnum->num!=-1);
    currentnum=listhead;
    printf("Original List:\n");
    while(currentnum!=NULL){
    	printf("%d\n",currentnum->num);
    	currentnum=currentnum->link;}
    for(i=1;i<len;i++){
    	cnum1=listhead;cnum2=cnum1->link;cnum3=listhead;
    	while(cnum2!=NULL){
    		if((cnum1->num)<(cnum2->num)){
    		if(cnum1==listhead){	
    		listhead=cnum2;
    		cnum1->link=cnum2->link;
    		cnum2->link=cnum1;
    		cnum3=cnum2;
    		cnum2=cnum1->link;}
    		else{
    			cnum3->link=cnum2;
    			cnum1->link=cnum2->link;
    			cnum2->link=cnum1;
    			cnum3=cnum2;
    		    cnum2=cnum1->link;}}
    		else{
    		cnum3=cnum1;
    		cnum1=cnum1->link;
    		cnum2=cnum2->link;}}}
    printf("Sorted List:\n");
    currentnum=listhead;
    while(currentnum!=NULL){
    	printf("%d\n",currentnum->num);
    	currentnum=currentnum->link;}
    return 0;
}