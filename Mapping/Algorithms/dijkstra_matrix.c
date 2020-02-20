//Edward's Code
//Dijkstra's Pathfinding Algorithm (Matrix Edition)

#include "main.h"

//Define Maximum Sizes
#define DIJ_MAX_SIZE 9

//Debug Printer for printing all values in distance array
void debugPrint(int dist[DIJ_MAX_SIZE]){
	printf("Vertex tDistance from Source\n");
	for(int node = 0; node < DIJ_MAX_SIZE; node++){
		printf("%d t %d\n", node, dist[node]);
	}
}

//Function to get the shortest valid node
int shortestNode(int dist[DIJ_MAX_SIZE], int checked[DIJ_MAX_SIZE]){
	int min = INFINITY;
	int minIndex;
    //Loop through every node
	for(int i = 0; i < DIJ_MAX_SIZE; i++){
        //Check if its the new smallest node and it has not already been checked off.
		if(dist[i] < min && checked[i] == False){
			min = dist[i];
			minIndex = i;
		}
	}
	return minIndex;
}

//The meat of the the algorithm
//Takes In:
//map -> 2d matrix of distances between nodes
//cMap -> 2d matrix of Connectivity Booleans
//start -> Starting Node
int dijkstra(int map[DIJ_MAX_SIZE][DIJ_MAX_SIZE], int cMap[DIJ_MAX_SIZE][DIJ_MAX_SIZE], int start){
	//Distance Array -> Contains Values Of Current Smallest Distances
	int dist[DIJ_MAX_SIZE];
    //Set all to infinity
	for(int i = 0; i < DIJ_MAX_SIZE; i++){dist[i] = INFINITY;}

	//Checked Array -> Indicates What Arrays Has Already Been Checked
	int checked[DIJ_MAX_SIZE] = {false};

	//Set the distance of the starting node to 0
	dist[start] = 0;

	//Loop Through DIJ_MAX_SIZE Times To Go Through All From Nodes
	for(int cout = 0; cout < DIJ_MAX_SIZE; cout++){
		//Get Smallest Node In Distance Array
		int from = shortestNode(dist, checked);
		checked[from] = true;
		//Go Through Each Node, Checking Connections
		for(int to = 0; to < DIJ_MAX_SIZE; to++){
			//printf("%d\n", dist[to] > dist[from] + map[from][to]);
            //Checking If:
            //The Nodes Are Connected (using cMap)
            //The New Node Pair Are The Smallest Value
			//Checked Status Of To Node Is False
			if(cMap[from][to] == true && dist[to] > dist[from] + map[from][to] && checked[to] == false){
				//Change Distance To New Shortest Value
				dist[to] = dist[from] + map[from][to];
			}
		}
	}
	//Printing Debug Values
    #ifdef DEBUG
    debugPrint(dist);
    #endif
}


//Because C Does Not Like Redefinitions of Main, This Checks If Its Being Run Directly Or If Its Being Included
#ifdef _MANUALRUN
int main(){

	int map[DIJ_MAX_SIZE][DIJ_MAX_SIZE] = {
	{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
	{4, 0, 8, 0, 0, 0, 0, 11, 0}, 
	{0, 8, 0, 7, 0, 4, 0, 0, 2}, 
	{0, 0, 7, 0, 9, 14, 0, 0, 0}, 
	{0, 0, 0, 9, 0, 10, 0, 0, 0}, 
	{0, 0, 4, 14, 10, 0, 2, 0, 0}, 
	{0, 0, 0, 0, 0, 2, 0, 1, 6}, 
	{8, 11, 0, 0, 0, 0, 1, 0, 7}, 
	{0, 0, 2, 0, 0, 0, 6, 7, 0}};

	int cMap[DIJ_MAX_SIZE][DIJ_MAX_SIZE] = {
	{0, 1, 0, 0, 0, 0, 0, 1, 0}, 
	{1, 0, 1, 0, 0, 0, 0, 1, 0}, 
	{0, 1, 0, 1, 0, 1, 0, 0, 1}, 
	{0, 0, 1, 0, 1, 1, 0, 0, 0}, 
	{0, 0, 0, 1, 0, 1, 0, 0, 0}, 
	{0, 0, 1, 1, 1, 0, 1, 0, 0}, 
	{0, 0, 0, 0, 0, 1, 0, 1, 1}, 
	{1, 1, 0, 0, 0, 0, 1, 0, 1}, 
	{0, 0, 1, 0, 0, 0, 1, 1, 0}};

	dijkstra(map, cMap, 0);
}
#endif // _MANUALRUN