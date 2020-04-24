#include<stdio.h>
#include<stdlib.h>
#include<time.h>

static int larger_number;
int max(int a,int b){
	int ans=a;
	if(b>a)
		ans=b;
	return ans;
}
int long_sub_seq(int* ary,int* dyn,int value,int allow,int num,int n,int count,int large){
	if(num<=n ){
		int adjust=num;
		if(allow==0)
			adjust=adjust+n;
		if(dyn[adjust]!=0){ 
			return dyn[adjust];
		}
		else{
			if(allow==1){
			if(value>large){	
				large=value;
				count++;
			}}	


		if(count>larger_number)	
			larger_number=count;
		
		if(num<n)
		dyn[adjust]=(max(long_sub_seq(ary,dyn,ary[num],1,num+1,n,count,value),long_sub_seq(ary,dyn,0,0,num+1,n,count,value)));	
	}
	}
	return count;
	}

int main(){

        clock_t t;

        int n;
        printf("Enter the number of terms\n");
        scanf("%d",&n);
        int ary[n];
	int check[(n*2)+1];
        printf("Enter the sequence\n");
        for(int i=0;i<n;i++){
                scanf("%d",&ary[i]);
	
        }
	for(int i=0;i<(n*2)+1;i++){
		check[i]=0;
	}

        t=clock();
	int ans=long_sub_seq(ary,check,0,0,0,n,0,0 );
             t=clock()-t;
        double time_taken=((double)t)/CLOCKS_PER_SEC;


        printf("Ans=%d\nTIME TAKEN=%f\n",larger_number,time_taken);

}

