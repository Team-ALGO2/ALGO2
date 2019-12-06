#include "main.h"
 
#define max 30
 
typedef struct edge{
	int u,v,w;
}edge;
 
typedef struct edgelist{
	edge data[max];
	int n;
}edgelist;

typedef struct node{
    int id, visible;
}node;
 
typedef struct nodelist{
	node data[max];
	int n;
}edgelist;

edgelist list;
edgelist slist;

//makes the array used in the prim
int P[max][max],n;
 
void prim(int ToPrim[][]);

int i;
 
void main(){
	//imputs a matrix then shows the user what it got
    int j,total_cost;
	
	printf("\nEnter number of vertices:");
	
	scanf("%d",&n);

    //genertes all the nodes to be used
    for(int i = 0; i < n; i++)
    {

    }
	
	printf("\nAdjacency matrix:\n");
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&P[i][j]);
		}
	}

    printf("Done inputing the matrix\n");

    printf("======================\n\n");
    for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",P[i][j]);
		}
        printf("\n");
	}
}	

//functionn that imputs the matrix to be computed and prints a prim MST
void prim(int ToPrim[][])
{

}

//checks if all the nodes have been touched
int nodeCheck(void)
{
    for(int i = 0; i < n; i++){
        
    }
}