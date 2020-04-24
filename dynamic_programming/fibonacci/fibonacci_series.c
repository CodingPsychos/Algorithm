#include<stdio.h>
#include<stdlib.h>
#include<time.h>
long long fibonacci(int n,int* arr){
	if(arr[n]!=NULL)
		return arr[n];
	if(n==1||n==2)
		return 1;
	else
		arr[n]=fibonacci((n-1),arr)+fibonacci((n-2),arr);
return arr[n];
}
int main(){
clock_t t;
int n;
printf("Enter the nth fibnacci number\n ");
scanf("%d",&n);
int* arr=malloc(n*sizeof(int*));
t=clock();
long long ans=fibonacci(n,arr);
t=clock()-t;
double time=((double)t)/CLOCKS_PER_SEC;
printf("%dth fibonacci number is %lld\ntime_taken=%f",n,ans,time);
}
