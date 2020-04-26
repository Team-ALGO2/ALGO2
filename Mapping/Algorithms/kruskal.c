/**
 * @file kruskal.c
 * 
 * @brief Implementation of kruskal algorithm in C
 * 
 * Detailed walkthrought comming soon!
 *  
 */
#include "main.h"
 
#define max 30
/**
 * @brief An edge for the map -- kruskal.c
 * 
 */
typedef struct edge{
	int u,v,w;	///< Components of the edge
}edge;

/**
 * @brief List of edges -- kruskal.c
 * 
 */
typedef struct edgelist{
	edge data[max];		///< Array of edges
	int n;		///< N
}edgelist;
 
edgelist klist;		///< List k
edgelist slist;		///< list s

 
int K[max][max],n;	///< Map
 
void kruskal();
int find(int bel[],int vertexnum);
void un(int bel[],int c1,int c2);


/**
 * @brief Loads the map and starts the program
 * 
 */
#ifdef _DEFMAIN
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
#endif // _DEFMAIN
 

/**
 * @brief The main part of the algo
 * 
 */
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


/**
 * @brief Helper
 * 
 * @param bel  array
 * @param vertexnum number
 * @return int `bel[vertexnum]`
 */
int find(int bel[],int vertexnum){
	return(bel[vertexnum]);
}

/**
 * @brief ???
 * 
 * @param bel ???
 * @param c1  ???
 * @param c2  ???
 */
void un(int bel[],int c1,int c2){
	int i;
	
	for(i=0;i<n;i++)
		if(bel[i]==c2)
			bel[i]=c1;
}
 

 
