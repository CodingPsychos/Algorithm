#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
static int position;
struct node{
	int i;
	int j;
	node** next;
};
node* create_node(int i,int j,int n){
	node* temp=(node*)malloc(sizeof(node));
	temp->next=(node**)malloc(n*sizeof(node));
	temp->i=i;
	temp->j=j;
	for(int i=0;i<n;i++){
		temp->next[i]=NULL;
	}
	return temp;
}

void trace_knight(node* knight,int** ary,int i,int j,int n,int height,int f){
	int ii[8]={2,1,-1,-2,-1,2,-2,1};
	int jj[8]={1,2,-2,-1,2,-1,1,-2};

	if(height<=25 && position<=25){
		if(i>=0 && i<5 && j>=0 && j<5 && ary[i][j]==0){
			ary[i][j]=position+1;
		height++;
		position++;
		for(f=0;f<n;f++){
			knight->next[f]=create_node(i+ii[f],j+jj[f],n);
			trace_knight(knight->next[f],ary,i+ii[f],j+jj[f],n,height,f);
			}
		}else{
			if(f==7){
			ary[i-ii[7]][j-jj[7]]=0;
			position--;
			}
			
		}
}
}

void print_traced_knight(int** ary){
	for(int  i=0;i<5;i++){
		for(int j=0;j<5;j++){
			printf("%*d",5,ary[i][j]);
		}
		printf("\n");
	}	
}
int main(){
	int val=0;
	int** ary=(int**)malloc(8*sizeof(int*));
	for(int i=0;i<8;i++){
		ary[i]=(int*)malloc(8*sizeof(int*));
	}
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			ary[i][j]=0;
		}
	}
	node* knight=create_node(0,0,8);
	trace_knight(knight,ary,0,0,8,val,0);
	print_traced_knight(ary);
}