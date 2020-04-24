#include<stdio.h>
int main(){
int n;
printf("Enter the number of values\n");
scanf("%d",&n);
int arr[n];
int large_count=0;
printf("Enter the sequence\n");
for(int i=0;i<n;i++)
	scanf("%d",&arr[i]);
int dyn[n];
for(int i=0;i<n;i++)
	dyn[i]=1;
for(int i=0;i<n;i++)
	for(int j=0;j<i;j++){
		if(arr[j]<arr[i])
			if(dyn[j]>large_count)
				large_count=dyn[j];
	dyn[i]=1+large_count;
	}


int ans=0;
for(int i=0;i<n;i++)
	if(dyn[i]>ans)
		ans=dyn[i];
printf("Longest subsequence is %d\n",ans);
}
