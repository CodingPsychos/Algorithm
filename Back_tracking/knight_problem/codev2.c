#include<stdio.h>
#include<stdlib.h>

int check=0;
void trace_knight(int** ary,int i,int j,int n,int val){
	int ii[8]={2,1,-1,-2,-2,-1, 1, 2};
	int jj[8]={1,2, 2, 1,-1,-2,-2,-1};
	if(i>=0 && i<n && j>=0 && j<n && check==0 && ary[i][j]==0){
		ary[i][j]=val+1;
		val++;
		if(val==(n*n)) {
			check=1;
		}
		for(int f=0;f<8;f++){
			trace_knight(ary,i+ii[f],j+jj[f],n,val);
		}
		if(check==0)
		ary[i][j] = 0;		
		}
}

void print_traced_knight(int** ary, int n){
	for(int  i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%*d",5,ary[i][j]);
		}
		printf("\n");
	}	
}
int main(){
	int val=0;
	int n=8;
	int** ary=(int**)malloc(n*sizeof(int*));
	for(int i=0;i<n;i++){
		ary[i]=(int*)malloc(n*sizeof(int*));
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ary[i][j]=0;
		}
	}
	trace_knight(ary,0,0,n,val);
	print_traced_knight(ary,n);
}
