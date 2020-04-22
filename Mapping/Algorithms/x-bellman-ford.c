#include <stdio.h>
#include <stdlib.h>
#define INFINITY 99999

//struct for the edges of the graph
struct Edge {
	int u;	//start vertex
	int v;	//end vertex 
	int w;	//weight of the edge (u,v)

    int c;
};
//Graph - it consists of edges
struct Graph {
	int V;	//total number of vertices in the graph
	int E;	//total number of edges in the graph
	struct Edge *edge;	//array of edges
};

void bellman(struct Graph *g, int source);
void display(int arr[], int size);
int main(void) {

    int a,b,c[100][100];

    printf("Input number of vertices: ");
    scanf("%d", &a);

    printf("Input number of edges: ");
    scanf("%d", &b);

    printf("Input Adjacency matrix: \n");
    for(int i = 0; i< a; i++){
        for(int j= 0; j< a; j++){
            scanf("%d", &c[i][j]);
        }
    }
    
    /*printf("Input Adjacency matrix 2");
	for(int i = 0; i<a; i++){
		for(int j = 0; j<a; j++){
			scanf("%d", &n[i][j]);
		}
	}*/

	//create graph
	struct Graph *g = (struct Graph*)malloc(sizeof(struct Graph));
	g->V = a;	//total vertices
	g->E = b;	//total edges


	
	//array of edges for graph
	g->edge = (struct Edge*)malloc(g->E * sizeof(struct Edge));


    int d = 0;
	
	for(int i=1;i<a;i++){
		for(int j=0;j<i;j++){
			if(c[i][j]!=0){
            
            g->edge[d].u = i;
	        g->edge[d].v = j;
            g->edge[d].w = c[i][j];

            printf("%d, %d, %d\n",g->edge[d].u,g->edge[d].v,g->edge[d].w);
            d++;
            }
        }
    }
	//To array
	 d= 0;
    for(int i=0;i<a;i++){
		for(int j=a;j>0;j--){
			if(c[i][j]!=0){
            
            g->edge[d].u = i;
	        g->edge[d].v = j;
            g->edge[d].w = c[i][j];

            printf("%d, %d, %d\n",g->edge[d].u,g->edge[d].v,g->edge[d].w);
            d++;
            }
        }
    }
	
	bellman(g, 0);		//0 is the source vertex
	
	return 0;
}
void bellman(struct Graph *g, int source) {
	//variables
	int i, j, u, v, w;
	//total vertex in the graph g
	int tV = g->V;
	
	//total edge in the graph g
	int tE = g->E;
	
	//distance array
	//size equal to the number of vertices of the graph g
	int d[tV];
	
	//predecessor array
	//size equal to the number of vertices of the graph g
	int p[tV];
	
	//step 1: fill the distance array and predecessor array
	for (i = 0; i < tV; i++) {
		d[i] = INFINITY;
		p[i] = 0;
	}
	
	//mark the source vertex
	d[source] = 0;
	
	//Relax edges |V| - 1 times
	for(i = 1; i <= tV-1; i++) {
		for(j = 0; j < tE; j++) {
			//get the edge data
			u = g->edge[j].u;
			v = g->edge[j].v;
			w = g->edge[j].w;
			
			if(d[u] != INFINITY && d[v] > d[u] + w) {
				d[v] = d[u] + w;
				p[v] = u;
			}
		}
	}
	
	// Detect negative cycle
	
	for(i = 0; i < tE; i++) {
		u = g->edge[i].u;
		v = g->edge[i].v;
		w = g->edge[i].w;
		if(d[u] != INFINITY && d[v] > d[u] + w) {  
			printf("Error. Negative weight cycle. Fix your program lmao\n");
			return;
		}
	}
	//print the distance and predecessor array
	printf("Distance array: ");
	display(d, tV);
	printf("Predecessor array: ");
	display(p, tV);
}
void display(int arr[], int size) {
	int i;
	for(i = 0; i < size; i ++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}