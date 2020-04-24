#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int check=0;
void print_ary(int n,int ary[n][n]){
for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		printf("%*d",5,ary[i][j]);
		}
		printf("\n");
	}
}
void solve_maze(int n,int ary[n][n],int ans[n][n],int i,int j){
	int ii[4]={0,1,-1,0};
	int jj[4]={1,0,0,-1};
	
	if(i>=0 && i<n && j>=0 && j<n && ans[i][j]==0 && ary[i][j]==0 && check==0){
		ans[i][j]=1;
		if(i==(n-1) && j==(n-1))
			check=1;
		
		solve_maze(n,ary,ans,i+ii[0],j+jj[0]);
		solve_maze(n,ary,ans,i+ii[1],j+jj[1]);
		solve_maze(n,ary,ans,i+ii[2],j+jj[2]);
		solve_maze(n,ary,ans,i+ii[3],j+jj[3]);

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

	int ans[4][4]={ {0,0,0,0},
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0}};
	int f_v=0;
	int s_v=0;
	while(question[f_v][s_v]!=0 && s_v<n)  {
		s_v++;
	}
	solve_maze(4,question,ans,f_v,s_v);
	printf("ANSWER: \n");
	print_ary(n,ans);
}
