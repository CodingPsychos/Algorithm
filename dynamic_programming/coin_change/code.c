#include<stdio.h>
#include<stdlib.h>
int change(int* coin,int n,int find,int** dyn){
	for(int i=0;i<n;i++)
		dyn[i][0]=1;
	for(int i=1;i<=find;i++)
		if(i%coin[0]==0)
			dyn[0][i]=1;
	for(int i=1;i<n;i++){
		for(int j=1;j<=find;j++){
			if(j>=coin[i])
				dyn[i][j]=dyn[i-1][j]+dyn[i][j-coin[i]];
			else
				dyn[i][j]=dyn[i-1][j-1];
		}}
return dyn[n-1][find];
}
int change_UTIL(int* coin,int n,int find){
	int** dyn=(int**)malloc(n*sizeof(int*));
	for(int i=0;i<n;i++)
		dyn[i]=(int*)malloc((find+1)*sizeof(int*));
	for(int i=0;i<n;i++)
		for(int j=0;j<=find;j++)
			dyn[i][j]=0;
return change(coin,n,find,dyn);
}
int main(){
int n;
printf("Enter the number of coins\n");
scanf("%d",&n);
int coin[n];
printf("Enter the coin values\n");
for(int i=0;i<n;i++)
	scanf("%d",&coin[i]);
int find;
printf("Enter the value needed to be find\n");
scanf("%d",&find);
int ans=change_UTIL(coin,n,find);
printf("Number of possible ways are %d\n",ans);
}
