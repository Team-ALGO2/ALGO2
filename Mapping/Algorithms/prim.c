//Edward's Code
//Prim Minimum Spanning Tree

#include "main.h"

//Define Maximum Sizes
#define PRIM_MAX_SIZE 5

//The meat of the the algorithm
//Takes In:
//map -> 2d matrix of distances between nodes
//cMap -> 2d matrix of Connectivity Booleans
//start -> Starting Node
int prim(int map[PRIM_MAX_SIZE][PRIM_MAX_SIZE], int cMap[PRIM_MAX_SIZE][PRIM_MAX_SIZE], int start){
	//Set Total Cost, Lowest From Node, Lowest To Node, and Current Vertex Cost 
	int cost = 0;
	int lowestFrom, lowestTo, currentCost;
	//Set List Of Visited Nodes
    int visited[PRIM_MAX_SIZE] = {false};
    visited[start] = true;

	//TODO: Make More Efficient
	//Loop Through PRIM_MAX_SIZE-1 So All Nodes Gets Touched
	for(int i = 0; i < PRIM_MAX_SIZE-1; i++){
		//Set lowestFrom, lowestTo, and , and currentCost to default value
		//lowestFrom and lowestTo to -1. (Set to -1 to check if value has been changed)
		//CurrentCost to INFINITY (Used for checking if cost is lowest)
		lowestFrom = -1;
		lowestTo = -1;
		currentCost = INFINITY;
		//Check for all visited nodes
		for(int from = 0; from < PRIM_MAX_SIZE; from++){
			if(visited[from]){
				//Check connection to all possible nodes
				for(int to = 0; to < PRIM_MAX_SIZE; to++){
					//Checking If:
					//The Nodes Are Connected (using cMap)
					//The Node Is Not Part Of The Visited Nodes (Prevents Self Looping)
					//Current Cost Is Lowest Cost
					if(cMap[from][to] && visited[to] == false && map[from][to] < currentCost){
						currentCost = map[from][to];
						lowestFrom = from;
						lowestTo = to;
					}
				}
			}
		}
		//Checking If lowestFrom and lowestTo has been changed
		if(lowestFrom != -1 && lowestTo != -1){
			//Has Been Changed, Adding CurrentCost to Cost
			cost = cost + currentCost;
			visited[lowestTo] = true;
			//Printing Debug Text
			#ifdef DEBUG
			printf("Vertex From %d to %d Cost %d (Now Cost %d)\n", lowestFrom, lowestTo, currentCost, cost);
			#endif
		}
		else{
			//Has Not Been Changed, Exiting Loop!
			break;
		}
	}
	printf("%d\n", cost);
}

// Because C Does Not Like Redefinitions of Main, This Checks If Its Being Run Directly Or Is It Being Run By A Function Call
#ifndef _REDEFGUARD
int main(){


	/*
	int map[PRIM_MAX_SIZE][PRIM_MAX_SIZE] = {
	{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
	{4, 0, 8, 0, 0, 0, 0, 11, 0}, 
	{0, 8, 0, 7, 0, 4, 0, 0, 2}, 
	{0, 0, 7, 0, 9, 14, 0, 0, 0}, 
	{0, 0, 0, 9, 0, 10, 0, 0, 0}, 
	{0, 0, 4, 14, 10, 0, 2, 0, 0}, 
	{0, 0, 0, 0, 0, 2, 0, 1, 6}, 
	{8, 11, 0, 0, 0, 0, 1, 0, 7}, 
	{0, 0, 2, 0, 0, 0, 6, 7, 0}};

	int cMap[PRIM_MAX_SIZE][PRIM_MAX_SIZE] = {
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

	int map[PRIM_MAX_SIZE][PRIM_MAX_SIZE] = {
		{0, 2, 0, 6, 0}, 
        {2, 0, 3, 8, 5}, 
        {0, 3, 0, 0, 7}, 
        {6, 8, 0, 0, 9}, 
        {0, 5, 7, 9, 0}};

	int cMap[PRIM_MAX_SIZE][PRIM_MAX_SIZE] = {
		{0, 1, 0, 1, 0}, 
        {1, 0, 1, 1, 1}, 
        {0, 1, 0, 0, 1}, 
        {1, 1, 0, 0, 1}, 
        {0, 1, 1, 1, 0}};

	prim(map, cMap, 0);
}
#endif // _REDEFGUARD