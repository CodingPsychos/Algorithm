#include<stdio.h>
#include<stdlib.h>
typedef struct node node;

struct node{
	int data;
	node** next;
};

node* new_node(int data,int n){
	node* temp=(node*)malloc(sizeof(node));
	temp->next =(node**)malloc(n*sizeof(node));
	temp->data=data;
	for(int i=0;i<n;i++){
		temp->next[i]=NULL;
	}
	return temp;
}

void pre_order_traversal(node* temp,int n){
if(temp!=NULL){
		printf("%d",temp->data);
		//printf("\n");
		for(int i=0;i<n;i++){
		pre_order_traversal(temp->next[i],n);
		}
	}		
}

void create_tree(node* tree, int m, int n, int h){
	if(h<m)	{ 
			for(int i=0;i<n;i++){
				tree->next[i]=new_node(i,n);
				create_tree(tree->next[i],m,n,h+1);
			}
	}
}

int main(){
				int m = 3;
				int n = 3;
				node* n_queen = new_node(-1,n);
				create_tree(n_queen,m,n,0);
				printf("Pre_order_traversal\n");
				pre_order_traversal(n_queen,n);
				printf("\n");
				return 0;
}
