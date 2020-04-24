#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void array_zero(int* arr);
int main(){
	int n;
	
	printf("Enter the number of input\n");
	scanf("%d",&n);
	int* decimal_array=malloc(n*sizeof(int));
	int* input=malloc(n*sizeof(int));
	array_zero(decimal_array);
	
	printf("Enter the values\n");
	for(int i=0;i<n;i++){
		scanf("%d",&input[i]);
	}
	printf("Enter the limit value\n");
	int limit;
	scanf("%d",&limit);
	
	int end=0;
		for(int i=0;i<n;i++){
			end=end+pow(2,i);
		}
		int count=0;
		int ans=0;
		for(int i=0;i<=end;i++){
			int temp=i;
			int ref=n-1;
			while(temp!=0){
				decimal_array[ref]=temp%2;
				temp=temp/2;
				ref--;
			}
			for(int j=0;j<n;j++){
				if(decimal_array[j]==1){
				ans=ans+input[i];
				}
			}
			
			if(ans>=limit)
				count++;
			array_zero(decimal_array);
			ans=0;
				}//end
				printf("Final output is %d\n",count);
			return 0;
	
}


void array_zero(int* arr){
	for(int i=0;i<5;i++){
		arr[i]=0;
	}
}