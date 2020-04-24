#include<stdio.h>
#include<stdlib.h>
static int ans;
void create_tree_greater(int* arr, int m, int n, int h,int sum,int target){
	if(h==m){
			if(sum > target)
				ans++;
			}		
	if(h<m && sum > target)	{ 
				create_tree_greater(arr,m,n,h+1,sum-(0*arr[h]),target);
				create_tree_greater(arr,m,n,h+1,sum-(1*arr[h]),target);
	}
}

void create_tree_lesser(int* arr, int m, int n, int h,int sum,int target){
	if(h==m){
			if(sum < target && sum!=0)
				ans++;
			}		
	if(h<m && sum<target){ 
				create_tree_lesser(arr,m,n,h+1,sum+(0*arr[h]),target);
				create_tree_lesser(arr,m,n,h+1,sum+(1*arr[h]),target);
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
				printf("a-Subsets lesser than target\nb-Subsets greater than target\n");
				char giv;
				scanf(" %c",&giv);
				if(giv=='a'){
					create_tree_lesser(arr,m,2,0,0,target);
				}
				if(giv=='b'){
					int sum=0;
					for(int i=0;i<m;i++){
						sum=sum+arr[i];
					}
					create_tree_greater(arr,m,2,0,sum,target);
				}
				
				printf("\n");
				printf("It has %d Subsets\n",ans);
				return 0;
}
