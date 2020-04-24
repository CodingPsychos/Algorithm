#include<stdio.h>
int no_steps(int* step,int n,int steps_man_take){
	int dyn[steps_man_take][n+1];
	for(int i=0;i<steps_man_take;i++)
		for(int j=0;j<=n;j++)
			dyn[i][j]=0;

	for(int i=0;i<steps_man_take;i++)
		dyn[i][0]=1;
	
	for(int i=1;i<=n;i++)
		if(i%step[0]==0)
			dyn[0][i]=1;
	
	for(int i=1;i<steps_man_take;i++)
		for(int j=1;j<=n;j++)
			if(j>=step[i])
				dyn[i][j]=dyn[i-1][j]+dyn[i][j-step[i]];
			else
				dyn[i][j]=dyn[i-1][j];
	for(int i=0;i<steps_man_take;i++){
		for(int j=0;j<=n;j++){
			printf("%d-",dyn[i][j]);
		}
		printf("\n");
		}
	return dyn[steps_man_take-1][n];
}
int main(){
int n,man;
printf("Enter the number of steps and no steps person can take\n");
scanf("%d%d",&n,&man);
int step[man];
printf("Enter the steps taken\n");
for(int i=0;i<man;i++){
	scanf("%d",&step[i]);
}
int ans=no_steps(step,n,man);
printf("Ans is %d\n",ans);
}
