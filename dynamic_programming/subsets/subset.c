#include<stdio.h>
int subsets(int* arr,int n,int find){

	int dyn[n][find+1];
	for(int i=0;i<n;i++)
		for(int j=0;j<find+1;j++)
			dyn[i][j]=0;

	for(int i=0;i<n;i++)
		dyn[i][0]=1;

	for(int i=1;i<find+1;i++){
		if(i==arr[0])
			dyn[0][i]=1;
		else
		dyn[0][i]=0;}

	for(int i=1;i<n;i++)
		for(int j=1;j<find+1;j++){
			if(j>=arr[i]){
				dyn[i][j]=dyn[i-1][j] | dyn[i-1][j-arr[i]];			
			}else{
				dyn[i][j]=dyn[i-1][j];}
		}
	int ans=0;
	if(dyn[n-1][find]==1)
		ans=1;
	return ans;


}

int main(){
int n;
printf("Enter the number of terms\n");
scanf("%d",&n);
printf("Enter the sequence\n");
int arr[n];
for(int i=0;i<n;i++)
	scanf("%d",&arr[i]);	
int find;
printf("Enter the number you need to check if present as subset in sequence\n");
scanf("%d",&find);
int ans=subsets(arr,n,find);
printf("ANS is %d\n",ans);
}
