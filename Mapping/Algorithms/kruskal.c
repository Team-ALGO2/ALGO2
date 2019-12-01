
#include "main.h"
 
#define max 30
 
typedef struct edge{
	int u,v,w;
}edge;
 
typedef struct edgelist{
	edge data[max];
	int n;
}edgelist;
 
edgelist list;
edgelist slist;

 
int K[max][max],n;
 
void kruskal();
int find(int bel[],int vertexnum);
void un(int bel[],int c1,int c2);

void print();
 
void main(){
	int i,j,total_cost;
	
	printf("\nEnter number of vertices:");
	
	scanf("%d",&n);
	
	printf("\nAdjacency matrix:\n");
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&K[i][j]);
		}
	}	
	kruskal();
	int cost=0;
	
	for(i=0;i<slist.n;i++)
	{
		printf("\n%d\t%d\t%d",slist.data[i].u,slist.data[i].v,slist.data[i].w);
		cost=cost+slist.data[i].w;
	}
 
	printf("\n\nCost of the spanning tree=%d",cost);
}
 
void kruskal(){
	int bel[max],i,j,d1,d2;
	list.n=0;
 
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(K[i][j]!=0){
				list.data[list.n].u=i;
				list.data[list.n].v=j;
				list.data[list.n].w=K[i][j];
				list.n++;
			}
		}
 

	}
	edge temp;
	
	for(int i=1;i<list.n;i++){
		for(int j=0;j<list.n-1;j++){
			if(list.data[j].w>list.data[j+1].w)
			{
				temp=list.data[j];
				list.data[j]=list.data[j+1];
				list.data[j+1]=temp;
			}
		}
	}
	for(i=0;i<n;i++){
		bel[i]=i;
	}
	slist.n=0;
	
	for(i=0;i<list.n;i++){
		d1=find(bel,list.data[i].u);
		d2=find(bel,list.data[i].v);
		
		if(d1!=d2){
			slist.data[slist.n]=list.data[i];
			slist.n=slist.n+1;
			un(bel,d1,d2);
		}
	}
}
 
int find(int bel[],int vertexnum){
	return(bel[vertexnum]);
}
 
void un(int bel[],int c1,int c2){
	int i;
	
	for(i=0;i<n;i++)
		if(bel[i]==c2)
			bel[i]=c1;
}
 

 
