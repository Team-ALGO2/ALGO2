//Edward's Code
//Floyd Warshall Pathfinding Algorithm

#include "main.h"

//Define Maximum Sizes
#define FW_MAX_SIZE 9

//Debug Printer for printing all values in distance array
void debugPrint(int distMap[FW_MAX_SIZE][FW_MAX_SIZE]){
    printf("DBG PRINT\n");
    for(int x = 0; x < FW_MAX_SIZE; x++){
        for(int y = 0; y < FW_MAX_SIZE; y++){
            printf("%d ", distMap[x][y]);
        }
        printf("\n");
    }
}

//The meat of the the algorithm
//Takes In:
//map -> 2d matrix of distances between nodes
//cMap -> 2d matrix of Connectivity Booleans
//start -> Starting Node
int floydWarshall(int map[FW_MAX_SIZE][FW_MAX_SIZE], int cMap[FW_MAX_SIZE][FW_MAX_SIZE], int start){
    //2d Matrix Of All Distances in Map
    int distMap[FW_MAX_SIZE][FW_MAX_SIZE] = {false};

    //Go Through All Values Of Map, Setting Distance Values Either Self Values Or Infinity
    for(int i = 0; i < FW_MAX_SIZE; i++){
        for(int j = 0; j < FW_MAX_SIZE; j++){
            if(cMap[i][j]){
                distMap[i][j] = map[i][j];  
            }
            else{
                distMap[i][j] = INFINITY;
            }
        }
    }
    /*
     * This is the FUN part of the algorithm
     * It took me around AN HOUR to wrap my head around this, so I'll try the explain this as well as I can
     * The Formula Loops Through a, b, and c. (Hench Why Its O(n^3))
     * 
     * For This Formula, I have Chosen:
     * a -> From Destination
     * b -> Alternative Node
     * c -> To Destination
     * 
     * These Variables Result In:
     * (a to c) -> Original Connection
     * (a to b) -> Alternative Connection
     * (b to c) -> Connect Alternative Back To Destination
     * 
     * To Sum It Up:
     * The Computer Loops Through All Possible "From" Nodes
     * The Computer Loops Through All Possible "To" Nodes
     * The Computer Loops Through All Possible "Alternative" Nodes
     * The Computer Checkes If The Connection From The "From" Node To The "Alternative" Node
     * Plus The "Alternative" Node To The "To" Node Is Shorter Than 
     * Connection From The "From" Node To The "To" Node
     * 
     * This is the best explination I have for this algorithm for now!
    */
    for(int a = 0; a < FW_MAX_SIZE; a++){
        for(int b = 0; b < FW_MAX_SIZE; b++){
            for(int c = 0; c < FW_MAX_SIZE; c++){
                if(distMap[a][b] != INFINITY && distMap[b][c] != INFINITY){
                    if(distMap[a][c] > distMap[a][b] + distMap[b][c]){
                        distMap[a][c] = distMap[a][b] + distMap[b][c];
                    }
                }
            }
        }
    }

    //Checking For Negative Cycles (If the Value Of Self Is Negative)
    for(int v = 0; v < FW_MAX_SIZE; v++){
        if(distMap[v][v] < 0){
            distMap[v][v] = NEG_INFINITY;
        }
    }
    
    //memcpy(distMap, map, sizeof(distMap));
    //Printing Debug Values
    #ifdef DEBUG
    debugPrint(distMap);
    #endif
}

// Because C Does Not Like Redefinitions of Main, This Checks If Its Being Run Directly Or Is It Being Run By A Function Call
#ifndef _MANUALRUN
int main(){

    /*
	int map[FW_MAX_SIZE][FW_MAX_SIZE] = {
        {0, 5, 0, 10}, 
		{0, 0, 3, 0}, 
		{0, 0, 0, 1}, 
		{0, 0, 0, 0} 
	};

	int cMap[FW_MAX_SIZE][FW_MAX_SIZE] = {
        {1, 1, 0, 1}, 
		{0, 1, 1, 0}, 
		{0, 0, 1, 1}, 
		{0, 0, 0, 1} 
	};
    */

    /*
    int map[FW_MAX_SIZE][FW_MAX_SIZE] = {
        {0, 1, 0, 0}, 
        {0, 0, -1, 0}, 
        {0, 0, 0, -1}, 
        {-1, 0, 0, 0}
    }; 

    int cMap[FW_MAX_SIZE][FW_MAX_SIZE] = {
        {1, 1, 0, 0}, 
        {0, 1, 1, 0}, 
        {0, 0, 1, 1}, 
        {1, 0, 0, 1}
    }; 
    */

	int map[FW_MAX_SIZE][FW_MAX_SIZE] = {
	{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
	{4, 0, 8, 0, 0, 0, 0, 11, 0}, 
	{0, 8, 0, 7, 0, 4, 0, 0, 2}, 
	{0, 0, 7, 0, 9, 14, 0, 0, 0}, 
	{0, 0, 0, 9, 0, 10, 0, 0, 0}, 
	{0, 0, 4, 14, 10, 0, 2, 0, 0}, 
	{0, 0, 0, 0, 0, 2, 0, 1, 6}, 
	{8, 11, 0, 0, 0, 0, 1, 0, 7}, 
	{0, 0, 2, 0, 0, 0, 6, 7, 0}};

	int cMap[FW_MAX_SIZE][FW_MAX_SIZE] = {
	{0, 1, 0, 0, 0, 0, 0, 1, 0}, 
	{1, 0, 1, 0, 0, 0, 0, 1, 0}, 
	{0, 1, 0, 1, 0, 1, 0, 0, 1}, 
	{0, 0, 1, 0, 1, 1, 0, 0, 0}, 
	{0, 0, 0, 1, 0, 1, 0, 0, 0}, 
	{0, 0, 1, 1, 1, 0, 1, 0, 0}, 
	{0, 0, 0, 0, 0, 1, 0, 1, 1}, 
	{1, 1, 0, 0, 0, 0, 1, 0, 1}, 
	{0, 0, 1, 0, 0, 0, 1, 1, 0}};


	floydWarshall(map, cMap, 0);
}

#endif // _MANUALRUN