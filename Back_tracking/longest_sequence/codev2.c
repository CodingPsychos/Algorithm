#include<stdio.h>
#include<stdlib.h>
#include<time.h>

static int large_count;

void long_sub_seq(int* ary,int n,int count,int allow,int large,int check,int num){
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
	long_sub_seq(ary,n,count,0,large,ary[num],num+1);
	long_sub_seq(ary,n,count,1,large,ary[num],num+1);
}
}
int main(){
	
	clock_t t;

	int n;
	printf("Enter the number of terms\n");
	scanf("%d",&n);
	int ary[n];
	printf("Enter the sequence\n");
	for(int i=0;i<n;i++){
		scanf("%d",&ary[i]);
	}

	t=clock();

	long_sub_seq(ary,n,0,1,0,0,0);

	t=clock()-t;
	double time_taken=((double)t)/CLOCKS_PER_SEC;

	printf("Ans=%d\nTIME TAKEN=%f\n",large_count,time_taken);

}
