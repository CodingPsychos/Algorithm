#include<stdio.h>
#include<stdlib.h>
int max(int a,int b){
	int ans=(a>b)?a:b;
	return ans;
}
int longest_sub_sequence(char x[],char y[],int n,int m){
	if(x[n]==NULL || y[m]==NULL)
		return 0;
	if(x[n]==y[m])
		return 1+longest_sub_sequence(x,y,n+1,m+1);
	else
		return max(longest_sub_sequence(x,y,n+1,m),longest_sub_sequence(x,y,n,m+1));
}
int main(){
int a,b;
printf("Enter the number of letters in a and b\n");
scanf("%d%d",&a,&b);
char x[a];
char y[b];
printf("Enter the words\n");
scanf("%s%s",x,y);
int ans=longest_sub_sequence(x,y,0,0);
printf("Ans=%d\n",ans);
}
