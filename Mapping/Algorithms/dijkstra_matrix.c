#include "main.h"

#define max 9

void debugPrint(int dist[max]){
	printf("Vertex tDistance from Source\n");
	for(int node = 0; node < max; node++){
		printf("%d t %d\n", node, dist[node]);
	}
}

int shortestDist(int dist[max], int checked[max]){
	int min = INFINITY;
	int minIndex;
	for(int i = 0; i < max; i++){
		if(dist[i] < min && checked[i] == False){
			min = dist[i];
			minIndex = i;
		}
	}
	return minIndex;
}

int dijkstra(int map[max][max], int cMap[max][max], int start){
	int dist[max];
	for(int i = 0; i < max; i++){dist[i] = INFINITY;}

	int checked[max];
	for(int i = 0; i < max; i++){checked[i] = false;}

	dist[start] = 0;

	for(int cout = 0; cout < max; cout++){
		int from = shortestDist(dist, checked);
		checked[from] = true;
		for(int to = 0; to < max; to++){
			//printf("%d\n", dist[to] > dist[from] + map[from][to]);
			if(cMap[from][to] == true && dist[to] > dist[from] + map[from][to] && checked[to] == false){
				dist[to] = dist[from] + map[from][to];
			}
		}
	}
	debugPrint(dist);
}

int main(){

	int map[max][max] = {
	{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
	{4, 0, 8, 0, 0, 0, 0, 11, 0}, 
	{0, 8, 0, 7, 0, 4, 0, 0, 2}, 
	{0, 0, 7, 0, 9, 14, 0, 0, 0}, 
	{0, 0, 0, 9, 0, 10, 0, 0, 0}, 
	{0, 0, 4, 14, 10, 0, 2, 0, 0}, 
	{0, 0, 0, 0, 0, 2, 0, 1, 6}, 
	{8, 11, 0, 0, 0, 0, 1, 0, 7}, 
	{0, 0, 2, 0, 0, 0, 6, 7, 0}};

	int cMap[max][max] = {
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