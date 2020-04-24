#include<stdio.h>
#include<time.h>
int fibonacci(int n){
if(n<=1)
	return n;
return (fibonacci(n-1)+fibonacci(n-2));
}
int main(){
clock_t t;
int n;
printf("Enter the nth fibnacci number\n ");
scanf("%d",&n);
t=clock();
int ans=fibonacci(n);
t=clock()-t;
double time=((double)t)/CLOCKS_PER_SEC;
printf("%dth fibonacci number is %d\n TIME=%f\n",n,ans,time);
}
