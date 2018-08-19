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
	linklist **link;
	linklist *listhead=NULL,*listtail=NULL;
	linklist *newnum,*currentnum;
	int flag=0;
	linklist *cnum1,*cnum2,*cnum3,*cnum4,*cnum5;
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
    cnum3=listtail;cnum4=listhead;cnum5=cnum2->link;
    while(cnum3!=listhead){
    while(cnum2!=NULL){
    	if((cnum1->num)>(cnum2->num)){
    		cnum1=cnum1->link;
    		cnum2=cnum2->link;
    		//cnum4=cnum1->link2;
    		}
    	if(cnum5!=NULL&&flag==0&&(cnum1->num)<(cnum2->num)){
    	listhead=cnum2; 
    	cnum2->link2=listhead;
    	cnum1->link=cnum5; 
    	cnum2->link=cnum1;
    	cnum5->link2=cnum1; 
    	cnum1->link2=cnum2;
    	cnum4=cnum2;
    	cnum2=cnum1->link;
    	cnum5=cnum5->link;
    	//printf("%d %d %d",cnum4->num,cnum1->num,cnum2->num);
    	//printf("%d",cnum5->num);
    		}
    	/*if(cnum5!=NULL&&flag!=0&&(cnum1->num)<(cnum2->num)){
    		cnum4->link=cnum2; cnum2->link2=cnum4;
    		cnum1->link=cnum5; cnum5->link2=cnum1;
    	    cnum2->link=cnum1; cnum1->link2=cnum2;
    	    cnum4=cnum4->link;
    	    cnum2=cnum1->link;
    	    cnum5=cnum2->link;
    	}*/
    	if(cnum5==NULL&&flag!=0&&(cnum1->num)<(cnum2->num)){
    		cnum4->link=cnum2; 
    		cnum2->link2=cnum1->link2;
    		cnum1->link=NULL;
    		cnum2->link=cnum1; 
    		cnum1->link2=cnum2;
    		cnum4=cnum2;
    		cnum2=cnum1->link;
    		}
    	/*if(cnum5==NULL&&flag==0&&(cnum1->num)<(cnum2->num)){
    		listhead=cnum2; 
    		cnum2->link2=listhead;
    		cnum1->link=NULL;
    		cnum2->link=cnum1;
    		cnum1->link2=cnum2;
    		cnum4=cnum2;
    		cnum2=cnum1->link;
    	}*/
flag++;
    }
    printf("s");
    flag=0;
    cnum3=cnum1->link2;
    cnum1=listhead;
    cnum2=cnum1->link;
    printf("%d",cnum3->num);
    cnum4=listhead;
    cnum5=cnum2->link;
    }
    
    
    
    printf("Sorted List:\n");
    currentnum=listhead;
    while(currentnum!=NULL){
    	printf("%d\n",currentnum->num);
    	currentnum=currentnum->link;}
}