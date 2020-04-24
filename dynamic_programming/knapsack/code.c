#include<stdio.h>
int max(int a,int b){
	return (a>b)?a:b;
}
int knapsack(int* val,int* wht,int find,int n){
	int dyn[n+1][find+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=find;j++){
			if(i==0 || j==0)
				dyn[i][j]=0;
			else if(j>=wht[i-1])
				dyn[i][j]=max(dyn[i-1][j],dyn[i-1][j-wht[i-1]]+val[i-1]);
			else
				dyn[i][j]=dyn[i-1][j];
		}
//	for(int i=0;i<=n;i++)
//		for(int j=0;j<=find)
	return dyn[n][find];
}
int main(){
int n;
printf("Enter the number of terms\n");
scanf("%d",&n);
int val[n],wht[n];
printf("Enter the values\n");
for(int i=0;i<n;i++)
	scanf("%d",&val[i]);
printf("Enter the weight\n");
for(int i=0;i<n;i++)
	scanf("%d",&wht[i]);
int find;
printf("Enter the weight needed to find\n");
scanf("%d",&find);
int ans=knapsack(val,wht,find,n);
printf("Ans is %d\n",ans);
}
