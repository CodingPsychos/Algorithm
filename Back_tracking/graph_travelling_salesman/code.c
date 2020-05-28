#include<stdio.h>
#include<stdlib.h>
#include "sll.c"
#include "graph.c"

static int s_dist=1000;

void salesman(graph_list* g,int city,int distance,int count,int path,int* check,int start ){
	if(check[city]!=1 ||(city==start && count==(g->V)-1)){
		check[city]=1;
		count++;
		path+=distance;
	//printf("city=%d path=%d",city,path);
		if(path<s_dist && count==g->V && city==start){
			//printf("s_path=%d\n",path);
			s_dist=path;

		}
		printf("\n");
	sll_node* c=g->list[city].head;
	sll_node* d=g->list[city].weightHead;
		while(c!=NULL){
			salesman(g,c->data,d->data,count,path,check,start);
			c=c->next;
			d=d->next;
		}
		if(city!=start)
			check[city]=0;
	
	}
}
int main(){
int m=4;
graph_list* g=graph_create(m);
int path=0,count=0;
int starting_city=0;
graph_add_edge(g,0,1,3);
graph_add_edge(g,0,2,0);
graph_add_edge(g,0,3,2);
graph_add_edge(g,1,0,3);
graph_add_edge(g,1,2,4);
graph_add_edge(g,2,1,4);
graph_add_edge(g,2,0,0);
graph_add_edge(g,2,3,3);
graph_add_edge(g,3,0,2);
graph_add_edge(g,3,2,3);
graph_add_edge(g,1,3,1);
graph_add_edge(g,3,1,1);

int* check=(int*)calloc(m,sizeof(int*));
check[starting_city]=1;
	sll_node* city=g->list[starting_city].head;
	sll_node* distance=g->list[starting_city].weightHead;
	
	while(city!=NULL){
		salesman(g,city->data,distance->data,count,path,check,starting_city);
		city=city->next;
		distance=distance->next;
	}

printf("shortest distance=%d\n",s_dist);
return 0;
}
