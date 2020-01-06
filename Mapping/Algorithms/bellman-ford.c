#include "main.h"

#define MAX_SIZE 10

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

int bellmanFord(int map[MAX_SIZE][MAX_SIZE], int cMap[MAX_SIZE][MAX_SIZE], int start){
    int relaxOrderCache[MAX_SIZE];
    int relaxOrderCacheSet = false;

	int dist[MAX_SIZE];
	for(int i = 0; i < MAX_SIZE; i++){dist[i] = INFINITY;}

    dist[start] = 0;

    for(int j = 0; j < MAX_SIZE-1; j++){
        int changed = false;
        int checked[MAX_SIZE] = {false};
        for(int cout = 0; cout < MAX_SIZE; cout++){
            int from;
            if(!relaxOrderCacheSet){
                from = shortestDist(dist, checked);
                relaxOrderCache[cout] = from;
            }
            else{
                from = relaxOrderCache[cout];
            }
            checked[from] = true;
            for(int to = 0; to < MAX_SIZE; to++){
                if(cMap[from][to] == true && dist[to] > dist[from] + map[from][to]){
                    dist[to] = dist[from] + map[from][to];
                    changed = true;
                }
            }
        }
        relaxOrderCacheSet = true;
        if(!changed){
            break;
        }
        //debugPrint(dist);
    }
    for(int j = 0; j < MAX_SIZE-1; j++){
        int changed = false;
        int checked[MAX_SIZE] = {false};
        for(int cout = 0; cout < MAX_SIZE; cout++){
            int from = relaxOrderCache[cout];
            checked[from] = true;
            for(int to = 0; to < MAX_SIZE; to++){
                if(cMap[from][to] == true && dist[to] > dist[from] + map[from][to]){
                    dist[to] = NEG_INFINITY;
                    changed = true;
                }
                else if(cMap[from][to] == true && dist[from] == NEG_INFINITY){
                    dist[to] = NEG_INFINITY;
                    changed = true;
                }
            }
        }
        //debugPrint(dist);
        if(!changed){
            break;
        }
    }
    debugPrint(dist);
}

int main(){

    //todo
    //int vertexes = 13;
    //int nodes = 10;

	int map[MAX_SIZE][MAX_SIZE] = {
        {0, 5, 0, 0, 0, 0, 0, 0, 0, 0}, //0
        {0, 0, 20, 0, 0, 30, 60, 0, 0, 0}, //1
        {0, 0, 0, 10, 75, 0, 0, 0, 0, 0}, //2
        {0, 0, -15, 0, 0, 0, 0, 0, 0, 0}, //3
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 100}, //4
        {0, 0, 0, 0, 25, 0, 5, 0, 50, 0}, //5
        {0, 0, 0, 0, 0, 0, 0, -50, 0, 0}, //6
        {0, 0, 0, 0, 0, 0, 0, 0, -10, 0}, //7
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //8
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //9
    };

	int cMap[MAX_SIZE][MAX_SIZE] = {
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //0
        {0, 0, 1, 0, 0, 1, 1, 0, 0, 0}, //1
        {0, 0, 0, 1, 1, 0, 0, 0, 0, 0}, //2
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, //3
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //4
        {0, 0, 0, 0, 1, 0, 1, 0, 1, 0}, //5
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, //6
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, //7
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //8
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //9
    };

	bellmanFord(map, cMap, 0);
}