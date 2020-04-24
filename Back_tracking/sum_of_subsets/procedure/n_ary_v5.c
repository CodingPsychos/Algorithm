#include<stdio.h>
#include<stdlib.h>
static int ans;
void create_tree(int* arr, int m, int n, int h,int sum,int target){
	if(h==m){
			if(sum > target)
				ans++;
			}		
	if(h<m)	{ 
				create_tree(arr,m,n,h+1,sum+(0*arr[h]),target);
				create_tree(arr,m,n,h+1,sum+(1*arr[h]),target);
	}
}
int main(){
				int m ;
				int target;
				printf("Enter the number of elements\n");
				scanf("%d",&m);
				printf("Enter the values\n");
				int* arr=malloc(m*sizeof(int*));
				for(int i=0;i<m;i++){
					scanf("%d",&arr[i]);
				}
				printf("Enter the target value\n");
				scanf("%d",&target);
				create_tree(arr,m,2,0,0,target);
				printf("\n");
				printf("It has %d Subsets\n",ans);
				return 0;
}
