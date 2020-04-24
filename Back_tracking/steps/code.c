#include<stdio.h>
static int count;

int no_steps(int* step,int n,int n_steps,int val,int sum,int way){
	if(val<n_steps && sum<n){
		sum+=way;
		if(sum==n){
			val++;
			count++;
			}
		no_steps(step,n,n_steps,val,sum,step[val]);
		no_steps(step,n,n_steps,val+1,sum,0);
	}
return count;
}
int main(){
int n_steps,n;
printf("Enter the number of steps\n");
scanf("%d",&n);
printf("Enter the steps way\n");
scanf("%d",&n_steps);
int step[n_steps];
printf("Enter the steps took\n");
for(int i=0;i<n_steps;i++)
	scanf("%d",&step[i]);
int ans=no_steps(step,n,n_steps,0,0,0);
printf("Num of ways are %d\n",ans);
}
