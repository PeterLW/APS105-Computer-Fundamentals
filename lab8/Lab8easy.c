/* Note:Your choice is C IDE */
#include "stdio.h"
#include "stdlib.h"
//Name: Wei Lin, student#:999595193
//the program scanf a list of number and output the numbers in descending order
void main()
{
	typedef struct list{
		int num;
		struct list *link;
		struct list *link2;
	}linklist;
	int temp;
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
    	newnum->link2=listhead;
    	listhead=newnum;
    	listtail=newnum;}
    	else{
    	newnum->link=NULL;
    	newnum->link2=listtail;
    	listtail->link=newnum;
    	listtail=newnum;}}
    }while(newnum->num!=-1);
    currentnum=listhead;
    printf("Original List:\n");
    while(currentnum!=NULL){
    	printf("%d\n",currentnum->num);
    	currentnum=currentnum->link;}
    cnum1=listhead;cnum2=cnum1->link;
    cnum3=listtail;
    while(cnum3!=listhead){
    while(cnum2!=NULL){
    	if((cnum1->num)<(cnum2->num)){
    		temp=cnum1->num;
    		cnum1->num=cnum2->num;
    		cnum2->num=temp;}
    	cnum1=cnum1->link;
    	cnum2=cnum2->link;}
    cnum1=listhead;
    cnum2=cnum1->link;
    cnum3=cnum3->link2;
}
    printf("Sorted List:\n");
    currentnum=listhead;
    while(currentnum!=NULL){
    	printf("%d\n",currentnum->num);
    	currentnum=currentnum->link;}
}