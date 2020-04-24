#include<stdio.h>
#include<stdlib.h>
static int count;
int check(int** chess_board,int n,int row,int col){
	if(row<0 || row>=n || col<0 || col>=n)
		return 0;
	if(chess_board[row][col]==1)
		return 0;
	for(int i=0;i<n;i++)
		if(chess_board[row][i]==1)
			return 0;
	for(int i=0;i<n;i++)	
		if(chess_board[i][col])
			return 0;
	for(int i=0;i<n;i++){
		if((row+i)<n && (col+i)<n)
			if(chess_board[row+i][col+i]==1)
				return 0;
		if((row+i)<n && (col-i)>=0)
			if(chess_board[row+i][col-i]==1)
				return 0;
		if((row-i)>=0 && (col-i)>=0)
			if(chess_board[row-i][col-i]==1)
				return 0;
		if((row-i)>=0 && (col+i)<n)
			if(chess_board[row-i][col+i]==1)
				return 0;
	}
return 1;
}
void printboard(int** chess_board,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%*d",5,chess_board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void clearboard(int** chess_board,int n){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			chess_board[i][j]=0;
}
void n_queen(int** chess_board,int n,int row,int col,int flag){

	if(((check(chess_board,n,row,col)==1 && (row<n) && (col<n))) || flag==1){
		if(row>=0 && row<n && col>=0 && col<n)
			chess_board[row][col]=1;

		if(row==n-1){
			printboard(chess_board,n);
			count++;
			}
		if(row<n)
		for(int i=0;i<n;i++)
			n_queen(chess_board,n,row+1,i,0);
		if(row<n && row>=0 && col<n && col>=0)	
			chess_board[row][col]=0;
	}
}
int main(){
int n;
printf("Enter the n value\n");
scanf("%d",&n);
int** chess_board=(int**)malloc(n*sizeof(int**));
for(int i=0;i<n;i++)
	chess_board[i]=(int*)malloc(n*sizeof(int*));
clearboard(chess_board,n);
n_queen(chess_board,n,-1,-1,1);
printf("Ans is %d\n",count);
return 0;
}
