#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(char* name,int a,int b){
	char temp=name[a];
	name[a]=name[b];
	name[b]=temp;
}
void permutation(char* name,int a){
	int n=strlen(name);
	for(int i=0;i<n;i++){
		if((a+i)<n){
			swap(name,a,a+i);
			if(a==(n-2))
				printf("%s\n",name);
			permutation(name,a+1);	
			swap(name,a,a+i);
		}
	}	

}

int main(){
int n=0;
printf("Enter the number of letters in string\n");
scanf("%d",&n);
char* name=malloc(n*(sizeof(char*)));
printf("Enter the string\n");
scanf("%s",name);
printf("possible combinations\n");
permutation(name,0);
}
