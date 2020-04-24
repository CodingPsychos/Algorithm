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

void create_tree(int* arr,node* tree, int m, int n, int h,int sum,int target){
	if(h==m){
		//printf("Sum=%d\n",sum);
			if(sum > target)
				ans++;
			}		
	if(h<m)	{ 
				tree->next[0]=new_node(0*arr[h],n);
				create_tree(arr,tree->next[0],m,n,h+1,sum+(0*arr[h]),target);
				tree->next[1]=new_node(1*arr[h],n);
				create_tree(arr,tree->next[1],m,n,h+1,sum+(1*arr[h]),target);
	}
}

int main(){
				int m ;
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
				node* n_queen = new_node(0,2);
				create_tree(arr,n_queen,m,2,0,0,target);
				printf("Pre_order_traversal\n");
				pre_order_traversal(n_queen,2);
				printf("\n");
				printf("It has %d Subsets\n",ans);
				return 0;
}
