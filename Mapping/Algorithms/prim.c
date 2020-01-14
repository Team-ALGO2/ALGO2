#include "main.h"

#define MAX_SIZE 5

int prim(int map[MAX_SIZE][MAX_SIZE], int cMap[MAX_SIZE][MAX_SIZE], int start){
	int cost = 0;
	int lowestFrom = -1, lowestTo = -1, currentCost = INFINITY;
    int visited[MAX_SIZE] = {false};
    visited[start] = true;

	for(int i = 0; i < MAX_SIZE-1; i++){
		lowestFrom = -1;
		lowestTo = -1;
		currentCost = INFINITY;
		for(int from = 0; from < MAX_SIZE; from++){
			if(visited[from]){
				for(int to = 0; to < MAX_SIZE; to++){
					if(cMap[from][to] && visited[to] == false){
						if(map[from][to] < currentCost){
							currentCost = map[from][to];
							lowestFrom = from;
							lowestTo = to;
						}
					}
				}
			}
		}
		if(lowestFrom != -1 && lowestTo != -1){
			cost = cost + currentCost;
			visited[lowestTo] = true;
			printf("Vertex From %d to %d Cost %d (Now Cost %d)\n", lowestFrom, lowestTo, currentCost, cost);
		}
		else{
			break;
		}
	}
	printf("%d\n", cost);
}

int main(){


	/*
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
	*/

	int map[MAX_SIZE][MAX_SIZE] = {
		{0, 2, 0, 6, 0}, 
        {2, 0, 3, 8, 5}, 
        {0, 3, 0, 0, 7}, 
        {6, 8, 0, 0, 9}, 
        {0, 5, 7, 9, 0}};

	int cMap[MAX_SIZE][MAX_SIZE] = {
		{0, 1, 0, 1, 0}, 
        {1, 0, 1, 1, 1}, 
        {0, 1, 0, 0, 1}, 
        {1, 1, 0, 0, 1}, 
        {0, 1, 1, 1, 0}};

	prim(map, cMap, 0);
}