//Alex's Code

#include "main.h"
 
#define max 30
 
typedef struct edge{
	int u,v,w;
}edge;
 
typedef struct edgelist{
	edge data[max];
	int n;
}edgelist;
 
edgelist klist;
edgelist slist;

 
int K[max][max],n;
 
void kruskal();
int find(int bel[],int vertexnum);
void un(int bel[],int c1,int c2);


//Because C Does Not Like Redefinitions of Main, This Checks If Its Being Run Directly Or If Its Being Included
#ifdef _MANUALRUN
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
#endif // _MANUALRUN
 
void kruskal(){
	int bel[max],i,j,d1,d2;
	klist.n=0;
 
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(K[i][j]!=0){
				klist.data[klist.n].u=i;
				klist.data[klist.n].v=j;
				klist.data[klist.n].w=K[i][j];
				klist.n++;
			}
		}
 

	}
	edge temp;
	
	for(int i=1;i<klist.n;i++){
		for(int j=0;j<klist.n-1;j++){
			if(klist.data[j].w>klist.data[j+1].w)
			{
				temp=klist.data[j];
				klist.data[j]=klist.data[j+1];
				klist.data[j+1]=temp;
			}
		}
	}
	for(i=0;i<n;i++){
		bel[i]=i;
	}
	slist.n=0;
	
	for(i=0;i<klist.n;i++){
		d1=find(bel,klist.data[i].u);
		d2=find(bel,klist.data[i].v);
		
		if(d1!=d2){
			slist.data[slist.n]=klist.data[i];
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
 

 
