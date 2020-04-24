#include<stdio.h>
#include<stdlib.h>
/* 						it is the normal method which directlt uses the formula.
 *  						for more optimized method use the way use given below.
int fac(int a){
	if(a==1)
		return a;
return a*fac(a-1);
}
int binomial(int n,int k,int* dyn){
int ans=0;
ans=fac(n)/(fac(k)*fac(n-k));
return ans;
}*/
int binomial(int n,int k,int** dyn){
	if(dyn[n-1][k-1]!=0)
		return dyn[n-1][k-1];
	if(k==0||  k==n)
		return 1;
	dyn[n-1][k-1]= binomial(n-1,k-1,dyn)+binomial(n-1,k,dyn);
return dyn[n-1][k-1];
}
int main(){
int n,k;
printf("Enter the values\n");
scanf("%d %d",&n,&k);
int** dyn=(int**)malloc((n)*sizeof(int*));
for(int i=0;i<n;i++){
	dyn[i]=(int* )malloc((k)*sizeof(int*));
}
	for(int i=0;i<n;i++)
		for(int j=0;j<k;j++)
			dyn[i][j]=0;
	
int ans=binomial(n,k,dyn);
printf("Binomial of (%d %d) is %d\n",n,k,ans);
}


