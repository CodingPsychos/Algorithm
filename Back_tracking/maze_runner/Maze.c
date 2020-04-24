#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct node node;
int check=0;

struct node{
	int data1;
	int data2;
	node** next;
};

node* create_node(int data1,int data2,int n){
	node* temp=(node*)malloc(sizeof(node));
	temp->next=(node**)malloc(n*sizeof(node));
	temp->data1=data1;
	temp->data2=data2;
	for(int i=0;i<n;i++){
		temp->next[i]=NULL;
	}
	return temp;
}

void print_ary(int n,int ary[n][n]){
for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		printf("%*d",5,ary[i][j]);
		}
		printf("\n");
	}
}

void solve_maze(int n,int ary[n][n],node* maze,int ans[n][n],int i,int j){
	int ii[4]={0,1,-1,0};
	int jj[4]={1,0,0,-1};
	
	if(i>=0 && i<n && j>=0 && j<n && ans[i][j]==0 && ary[i][j]==0 && check==0){
		ans[i][j]=1;
		if(i==(n-1) && j==(n-1))
			check=1;

		for(int k=0;k<n;k++){
			maze->next[k]=create_node(i+ii[k],j+jj[k],n);
			solve_maze(n,ary,maze->next[k],ans,i+ii[k],j+jj[k]);
		}
		if(check==0){
			ans[i][j]=0;
		}

	}

}
int main(){
	int n=4;
	int  question[4][4]={   {0,0,1,1},
       		                {1,0,1,0},
	                	{0,0,0,1},
	                	{0,1,0,0}};

	printf("MAZE:\n");
	print_ary(n,question);
	node* maze=create_node(0,0,n);
	int ans[4][4]={ {0,0,0,0},
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0}};
	int f_v=0;
	int s_v=0;
	while(question[f_v][s_v]!=0 && s_v<n)  {
		s_v++;
	}
	solve_maze(4,question,maze,ans,f_v,s_v);
	printf("ANSWER: \n");
	print_ary(n,ans);
}
