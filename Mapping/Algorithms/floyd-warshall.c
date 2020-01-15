#include "main.h"

#define MAX_SIZE 9

void debugPrint(int distMap[MAX_SIZE][MAX_SIZE]){
    printf("DBG PRINT\n");
    for(int x = 0; x < MAX_SIZE; x++){
        for(int y = 0; y < MAX_SIZE; y++){
            printf("%d ", distMap[x][y]);
        }
        printf("\n");
    }
}

int floydWarshall(int map[MAX_SIZE][MAX_SIZE], int cMap[MAX_SIZE][MAX_SIZE], int start){
    int distMap[MAX_SIZE][MAX_SIZE] = {false};

    for(int i = 0; i < MAX_SIZE; i++){
        for(int j = 0; j < MAX_SIZE; j++){
            if(cMap[i][j]){
                distMap[i][j] = map[i][j];  
            }
            else{
                distMap[i][j] = INFINITY;
            }
        }
    }

    for(int a = 0; a < MAX_SIZE; a++){
        for(int b = 0; b < MAX_SIZE; b++){
            for(int c = 0; c < MAX_SIZE; c++){
                if(distMap[a][b] != INFINITY && distMap[b][c] != INFINITY){
                    if(distMap[a][c] > distMap[a][b] + distMap[b][c]){
                        distMap[a][c] = distMap[a][b] + distMap[b][c];
                    }
                }
            }
        }
    }

    for(int v = 0; v < MAX_SIZE; v++){
        if(distMap[v][v] < 0){
            distMap[v][v] = NEG_INFINITY;
        }
    }

    // a : c Direct
    // a : b Rand Dir
    // b : c Connect Back
    
    //memcpy(distMap, map, sizeof(distMap));
    debugPrint(distMap);
}

int main(){

    /*
	int map[MAX_SIZE][MAX_SIZE] = {
        {0, 5, 0, 10}, 
		{0, 0, 3, 0}, 
		{0, 0, 0, 1}, 
		{0, 0, 0, 0} 
	};

	int cMap[MAX_SIZE][MAX_SIZE] = {
        {1, 1, 0, 1}, 
		{0, 1, 1, 0}, 
		{0, 0, 1, 1}, 
		{0, 0, 0, 1} 
	};
    */

    /*
    int map[MAX_SIZE][MAX_SIZE] = {
        {0, 1, 0, 0}, 
        {0, 0, -1, 0}, 
        {0, 0, 0, -1}, 
        {-1, 0, 0, 0}
    }; 

    int cMap[MAX_SIZE][MAX_SIZE] = {
        {1, 1, 0, 0}, 
        {0, 1, 1, 0}, 
        {0, 0, 1, 1}, 
        {1, 0, 0, 1}
    }; 
    */

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


	floydWarshall(map, cMap, 0);
}