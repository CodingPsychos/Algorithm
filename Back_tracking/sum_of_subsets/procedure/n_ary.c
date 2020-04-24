#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
static int count;

struct node{
	int data;
	node** next;
};

node* new_node(int data,int n){
	node* temp=(node*)malloc(sizeof(node*));
	temp->next =(node**)malloc(n*sizeof(node*));
	temp->data=data;
	for(int i=0;i<n;i++){
		temp->next[i]=NULL;
	}
	
	return temp;
}
void pre_order_traversal(node* temp,int n){
if(temp!=NULL){
		printf("%d",temp->data);
		printf("\n");
		for(int i=0;i<n;i++){
		pre_order_traversal(temp->next[i],n);
		}
	}		
}
/*
void create_tree(node* tree,int n){
	count++;
	if(count!=n+1){
		
		for(int i=0;i<n;i++){
			tree->next[i]=new_node(i,n);
			create_tree(tree->next[i],n);
		}
		
		
	}
	
}
*/
void create_tree(node* tree,int c,int n){
	if(c==count){
		tree = new_node(data,n); 
	}
	else {
		create_tree(tree->next,n);
	}
}	

int main(){
int n;
printf("Enter the N value\n");
scanf("%d",&n);
node* n_queen=new_node(-1,n);

create_tree(n_queen,0,n);

/*node* array=new_node(1,n);
array->next[0]=new_node(2,n);
array->next[1]=new_node(3,n);
array->next[2]=new_node(4,n);
array->next[0]->next[0]=new_node(5,n);
array->next[0]->next[1]=new_node(6,n);
array->next[0]->next[2]=new_node(7,n);
array->next[1]->next[0]=new_node(8,n);
array->next[1]->next[1]=new_node(9,n);
array->next[1]->next[2]=new_node(10,n);
array->next[2]->next[0]=new_node(11,n);
array->next[2]->next[1]=new_node(12,n);
array->next[2]->next[2]=new_node(13,n);
printf("Pre_order_traversal\n");*/
printf("count= %d\n",count);
printf("Pre_order_traversal\n");
printf("Ans = %d\n",n_queen->next[1]->data);
//printf("Ans2 = %d",n_queen->next[1]->next[1]->data);
//printf("Pre_order_traversal\n");
//pre_order_traversal(n_queen,n);


return 0;

}