#include "main.h"

#define MAX_SIZE 9

void debugPrint(int dist[MAX_SIZE]){
	printf("Vertex tDistance from Source\n");
	for(int node = 0; node < MAX_SIZE; node++){
		printf("%d t %d\n", node, dist[node]);
	}
}

int shortestDist(int dist[MAX_SIZE], int checked[MAX_SIZE]){
	int min = INFINITY;
	int minIndex;
	for(int i = 0; i < MAX_SIZE; i++){
		if(dist[i] < min && checked[i] == False){
			min = dist[i];
			minIndex = i;
		}
	}
	return minIndex;
}

int dijkstra(int map[MAX_SIZE][MAX_SIZE], int cMap[MAX_SIZE][MAX_SIZE], int start){
	int dist[MAX_SIZE];
	for(int i = 0; i < MAX_SIZE; i++){dist[i] = INFINITY;}

	int checked[MAX_SIZE];
	for(int i = 0; i < MAX_SIZE; i++){checked[i] = false;}

	dist[start] = 0;

	for(int cout = 0; cout < MAX_SIZE; cout++){
		int from = shortestDist(dist, checked);
		checked[from] = true;
		for(int to = 0; to < MAX_SIZE; to++){
			//printf("%d\n", dist[to] > dist[from] + map[from][to]);
			if(cMap[from][to] == true && dist[to] > dist[from] + map[from][to] && checked[to] == false){
				dist[to] = dist[from] + map[from][to];
			}
		}
	}
	debugPrint(dist);
}

int main(){

	int map[MAX_SIZE][MAX_SIZE] = {
	{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
	{4, 0, 8, 0, 0, 0, 0, 11, 0}, 
	{0, 8, 0, 7, 0, 4, 0, 0, 2}, 
	{0, 0, 7, 0, 9, 14, 0, 0, 0}, 
	{0, 0, 0, 9, 0, 10, 0, 0, 0}, 
	{0, 0, 4, 14, 10, 0, 2, 0, 0}, 
	{0, 0, 0, 0, 0, 2, 0, 1, 6}, 
	{8, 11, 0, 0, 0, 0, 1, 0, 7}, 
	{0, 0, 2, 0, 0, 0, 6, 7, 0}};

	int cMap[MAX_SIZE][MAX_SIZE] = {
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