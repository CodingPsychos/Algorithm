#include<stdio.h>
#include<stdlib.h>
int max(int a,int b){
return (a>b)?a:b;
}
int lcs(char x[],char y[],int** dyn){
	int n=strlen(x);
	int m=strlen(y);
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0||j==0)
				dyn[i][j]=0;
			else
			if(x[i]==y[j])
				dyn[i][j]=1+dyn[i-1][j-1];
			else
				dyn[i][j]=max(dyn[i][j-1],dyn[i-1][j]);
		}}
return dyn[n][m];
}
int lcs_PART(char x[],char y[]){
	int** dyn=(int**)malloc((strlen(x)+1)*sizeof(int*));
	for(int i=0;i<strlen(x)+1;i++)
		dyn[i]=(int*)malloc((strlen(y)+1)*sizeof(int*));
	for(int i=0;i<=strlen(x);i++)
		for(int j=0;j<strlen(y);j++)
			dyn[i][j]=0;
		
	return lcs(x,y,dyn);
}
int main(){
int n,m;
printf("Enter the number of letters in both word\n");
scanf("%d%d",&n,&m);
char x[n],y[m];
printf("Enter the words\n");
scanf("%s%s",x,y);
int ans=lcs_PART(x,y);
printf("Ans is %d\n",ans);
}
