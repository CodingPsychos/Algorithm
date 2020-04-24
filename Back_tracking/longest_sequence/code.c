#include<stdio.h>
#include<stdlib.h>

typedef struct node node;
static int large_count;
struct node{
	int data;
	node** next;
}; 

node* create_node(int data,int n){
	node* temp=(node*)malloc(sizeof(node));
	temp->next=(node**)malloc(n*sizeof(node));
	temp->data=data;
	for(int i=0;i<n;i++){
		temp->next[i]=NULL;
	}
return temp;
}
void long_sub_seq(node* seq,int* ary,int n,int count,int allow,int large,int check,int num){
if(num<=n){
	if(allow!=0){
		if(check>large){
			large=check;
			count++;
				}
			}
	if(count>large_count){
		large_count=count;
	}
		for(int i=0;i<2;i++){
			seq->next[i]=create_node(i*ary[num],2);
			long_sub_seq(seq->next[i],ary,n,count,i,large,ary[num],num+1);
		}
}
}
int main(){
	int n;
	printf("Enter the number of terms\n");
	scanf("%d",&n);
	int ary[n];
	printf("Enter the sequence\n");
	for(int i=0;i<n;i++){
		scanf("%d",&ary[i]);
	}
	node* seq=create_node(0,2);
	long_sub_seq(seq,ary,n,0,1,0,0,0);
	printf("Ans=%d\n",large_count);

}
