#include<stdio.h>
int find_min(int* arr,int n){
	int count=0;
	for(int i=0;i<n;i++)
		count+=arr[i];
	int half=count/2;
	int dyn[n][half+1];

	for(int i=0;i<n;i++)
		dyn[i][0]=1;
	for(int i=1;i<half+1;i++){
		if(i==arr[0])
			dyn[0][i]=1;
		else
			dyn[0][i]=0;
	}

	for(int i=1;i<n;i++){
		for(int j=1;j<half+1;j++){
			if(j>=arr[i]){
				dyn[i][j]=dyn[i-1][j] | dyn[i-1][j-arr[i]];	
			}else{
			dyn[i][j]=dyn[i-1][j];
			}
		}
	}
	int part1=0;
	for(int i=half;i>=0;i++){
		if(dyn[n-1][i]==1){
			part1=i;
			break;
		}

	}
	int part2=(count-part1);
	int ans=(part2-part1);
	
return ans;
}
int main(){
int n=0;
printf("Enter the number of terms\n");
scanf("%d",&n);
printf("Enter the values\n");
int arr[n];
for(int i=0;i<n;i++)
	scanf("%d",&arr[i]);
int ans=find_min(arr,n);
printf("Min diff is %d\n",ans);
}
