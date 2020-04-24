#include<stdio.h>
#include<stdlib.h>
static int count;
int change(int* coin,int n,int find,int val,int sum,int coin_values){
	sum+=coin_values;
	if(sum==find){
		count++;
		val++;
	}
	if(sum<find && val<n){
		change(coin,n,find,val,sum,coin[val]);
		change(coin,n,find,val+1,sum,0);
	}
return count;
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
printf("Enter the valure needed to be find\n");
scanf("%d",&find);
int ans=change(coin,n,find,0,0,0);
printf("Possible number of ways are %d\n",ans);

}
