#include<stdio.h>
#include<stdlib.h>
#include<math.h>
static int count;
void print(int n,int board[n][n]){
	for(int j=0;j<n;j++){
		for(int i=0;i<n;i++){
			printf("%*d",3,board[j][i]);
		}printf("\n");
	}
	printf("\n");
}
void next_cell(int *row,int *col,int n){
	*col+=1;
	if(*col>(n-1)){
		*row+=1;
		*col=0;
	}
}
void set_value(int* r1,int *r2,int val){
	if(val<=2){
		*r1=0;
		*r2=2;
		}
	else if(val<=5){
		*r1=3;
		*r2=5;
	}
	else{
		*r1=6;
		*r2=8;
	}
}
int check(int n,int board[n][n],int row,int col,int val){
	for(int i=0;i<n;i++){
		if(board[row][i]==val)
			return 0;
		if(board[i][col]==val)
			return 0;
		}
	int r1=0,r2=0,c1=0,c2=0;
	set_value(&r1,&r2,row);
	set_value(&c1,&c2,col);
	for(int i=r1;i<=r2;i++)
		for(int j=c1;j<=c2;j++)
			if(board[i][j]==val)
				return 0;
	return 1;
}
void sudoku(int n,int board[n][n],int row,int col,int val){

	if(row>=0 && row<n && col>=0 && col<n && count!=1){
		if(check(n,board,row,col,val) ){
			board[row][col]=val;
				int t_row=row;
				int t_col=col;
				col++;
				if(col==n){
					row++;
					col=0;
				}
			while(board[row][col]!=0){
				col++;
				if(col==n){
					row++;
					if(row==n){
						count=1;
					}
					col=0;
				}
			}
			for(int i=1;i<=9;i++)
				sudoku(n,board,row,col,i);
		if(count!=1)
			board[t_row][t_col]=0;		
			}
		}
}
int main(){
int n=9;
int board[9][9]={{5,4,0,0,2,0,8,0,6},
             	{0,1,9,0,0,7,0,0,3},
                {0,0,0,3,0,0,2,1,0},
                {9,0,0,4,0,5,0,2,0},
		{0,0,1,0,0,0,6,0,4},
	        {6,0,4,1,3,2,0,8,0},
		{0,6,0,0,0,0,1,9,0},
		{4,0,2,0,0,9,0,0,5},
		{0,9,0,0,7,0,4,0,2}};

	int row=0,col=0;
	while(board[row][col]!=0){
		col++;
		if(col==n){
			row++;
			col=0;
		}
	}
	int r1=0,r2=0,c1=0,c2=0;
	set_value(&r1,&r2,row);
	set_value(&c1,&c2,col);
	for(int i=1;i<=n;i++)
		sudoku(n,board,row,col,i);
	print(n,board);
return 0;
}
