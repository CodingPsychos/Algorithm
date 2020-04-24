#include<stdio.h>
#include<stdlib.h>
static int count;
int knapsack(int* value,int* weight,int n,int find,int v_sum,int w_sum,int ary,int val,int wht){
	if(ary<=n){
		v_sum+=val;
		w_sum+=wht;
		if(w_sum<=find && v_sum>count)
			count=v_sum;
	knapsack(value,weight,n,find,v_sum,w_sum,ary+1,value[ary],weight[ary]);
	knapsack(value,weight,n,find,v_sum,w_sum,ary+1,0,0);
	}
return count;
}
int main(){
int n;
printf("Enter the number of values\n");
scanf("%d",&n);
int find;
int value[n],weight[n];
printf("Enter the values\n");
for(int i=0;i<n;i++)
	scanf("%d",&value[i]);
printf("Enter the weight\n");
for(int i=0;i<n;i++)
	scanf("%d",&weight[i]);
printf("Enter the weight needed to be find\n");
scanf("%d",&find);
int ans=knapsack(value,weight,n,find,0,0,0,0,0);
printf("The knapsack value is %d\n",ans);
}
