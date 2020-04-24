#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
static int ans;

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
		printf("\n");
		for(int i=0;i<n;i++){
		pre_order_traversal(temp->next[i],n);
		}
	}		
}

void create_tree(int* arr,node* tree, int m, int n, int h,int val){
	if(h<m)	{ 
			for(int i=0;i<n;i++){
				tree->next[i]=new_node(i*arr[val],n);
				create_tree(arr,tree->next[i],m,n,h+1,val+1);
			}
	}
}

int sum_of_subsets(node* queen,int target,int n,int sum){
	if(queen!=NULL){
		sum=sum+queen->data;
		if(sum>target){
			ans++;
			sum=0;
		}
		for(int i=0;i<n;i++){
			sum_of_subsets(queen->next[i],target,n,sum);
		}
	
	}
	//printf("It has %d subsets\n",ans);
	return ans;
};

int main(){
				int m ;
				int n = 2;
				int target;
				printf("Enter the number of elements\n");
				scanf("%d",&m);
				printf("Enter the values\n");
				int* arr=malloc(m*sizeof(int*));
				for(int i=0;i<m;i++){
					scanf("%d",&arr[i]);
				}
				
				printf("Enter the target value\n");
				scanf("%d",&target);
				node* n_queen = new_node(0,n);
				create_tree(arr,n_queen,m,n,0,0);
				printf("Pre_order_traversal\n");
				pre_order_traversal(n_queen,n);
				printf("\n");
				printf("It has %d subsets",sum_of_subsets(n_queen,target,n,0));
				return 0;
}
