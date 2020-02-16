//Edward's Code
//Bellman Ford Pathfinding Algorithm

#include "main.h"

//Define Maximum Sizes
#define BF_MAX_SIZE 10

//Debug Printer for printing all values in distance array
void debugPrint(int dist[BF_MAX_SIZE]){
	printf("Vertex tDistance from Source\n");
	for(int node = 0; node < BF_MAX_SIZE; node++){
		printf("%d t %d\n", node, dist[node]);
	}
}

//Function to get the shortest valid node (Similar To One Used In Dijkstras)
int shortestNode(int dist[BF_MAX_SIZE], int checked[BF_MAX_SIZE]){
	int min = INFINITY;
	int minIndex;
    //Loop through every node
	for(int i = 0; i < BF_MAX_SIZE; i++){
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
int bellmanFord(int map[BF_MAX_SIZE][BF_MAX_SIZE], int cMap[BF_MAX_SIZE][BF_MAX_SIZE], int start){
    //Define Relax Order Cache
    //NOTE: This is really hacky but it does solve a few very nasty bugs and slightly improves Oavg
    //I am pretty sure this is not the most elegant solution, but it works!!!
    //WHAT IT DOES:
    //This Array Saves The Order In Which The Nodes Are Calculated In.
    //This Increases Oavg (As It Saves The Previous Calculations And Reuses Those), But It Fixes One Major Problem!
    //If the value of one node surpasses another node mid-calculation
    //The order in which the matrix is travelled gets changed
    //Breaking the algorithm by throwing it off track.
    //Relax Order Cache saves the original order and enforces it.
    int relaxOrderCache[BF_MAX_SIZE];
    int relaxOrderCacheSet = false;

    //Distance Array -> Contains Values Of Current Smallest Distances
	int dist[BF_MAX_SIZE];
    //Set all to infinity
	for(int i = 0; i < BF_MAX_SIZE; i++){dist[i] = INFINITY;}

    //Set the distance of the starting node to 0
    dist[start] = 0;

    //PART 1 -> GENERATING DISTANCE ARRAY VALUES
    //Loop Through BF_MAX_SIZE-1 Times To Make Sure All Values Propagate Throught The Matrix
    //(Algorithm Clains That Thats The Minimum Ammount Of Times For It To Work)
    for(int j = 0; j < BF_MAX_SIZE-1; j++){
        //Changed Flag. Indicates If Any Values Were Changed
        //(Improves Oavg By Removing Useless Loops)
        int changed = false;
        //Checked Array -> Indicates What Arrays Has Already Been Checked
        int checked[BF_MAX_SIZE] = {false};
        //Loop Through All Nodes
        for(int cout = 0; cout < BF_MAX_SIZE; cout++){
            int from;
            //Check If Order Cache Set Has Been Generates
            //If Not, Generate New Order Cache Set
            //If So, Use Order Cache Set
            if(!relaxOrderCacheSet){
                //Find Shortest Node Meathod (Used In Dijkstras)
                from = shortestNode(dist, checked);
                relaxOrderCache[cout] = from;
            }
            else{
                from = relaxOrderCache[cout];
            }
            //Go Through Each Node, Checking Connections
            checked[from] = true;
            for(int to = 0; to < BF_MAX_SIZE; to++){
                //Checking If:
                //The Nodes Are Connected (using cMap)
                //The New Node Pair Are The Smallest Value
                if(cMap[from][to] == true && dist[to] > dist[from] + map[from][to]){
                    //Change Distance To New Shortest Value
                    dist[to] = dist[from] + map[from][to];
                    //Set Changed Flag
                    changed = true;
                }
            }
        }
        //Set Order Cache Set Flag (Only Makes Difference First Time)
        relaxOrderCacheSet = true;

        //Printing Debug Values
        #ifdef DEBUG
        debugPrint(dist);
        #endif

        //End Loop If Nothing Gets Changed
        if(!changed){
            break;
        }
    }

    //PART 2 -> DETECTING NEGATIVE CYCLES
    //Similar Idea To PART 1, But Instead Of Changing The Value Of Shortest Node To Value, Set To Negative Infinty
    //Because There Should Not Be Any More Changes
    for(int j = 0; j < BF_MAX_SIZE-1; j++){
        //Changed Flag. Indicates If Any Values Were Changed
        //(Improves Oavg By Removing Useless Loops)
        int changed = false;
        //Checked Array -> Indicates What Arrays Has Already Been Checked
        int checked[BF_MAX_SIZE] = {false};
        //Loop Through All Nodes
        for(int cout = 0; cout < BF_MAX_SIZE; cout++){
            //Order Cache SHOULD be already generated at this point!
            int from = relaxOrderCache[cout];
            checked[from] = true;
            //Go Through Each Node, Checking Connections
            for(int to = 0; to < BF_MAX_SIZE; to++){
                //Checking If:
                //The Nodes Are Connected (using cMap)
                //The New Node Pair Are The Smallest Value
                if(cMap[from][to] == true && dist[to] > dist[from] + map[from][to]){
                    //Set The Negative Infinity Because It Is A Negative Cycle
                    dist[to] = NEG_INFINITY;
                    //Set Changed Flag
                    changed = true;
                }
                //Checking If:
                //The Nodes Are Connected (using cMap)
                //The From Node Is Negative Infinity
                else if(cMap[from][to] == true && dist[from] == NEG_INFINITY){
                    //Set The Negative Infinity Because It is reachable from a Negative Cycle
                    dist[to] = NEG_INFINITY;
                    //Set Changed Flag
                    changed = true;
                }
            }
        }
        
        //Printing Debug Values
        #ifdef DEBUG
        debugPrint(dist);
        #endif

        //End Loop If Nothing Gets Changed
        if(!changed){
            break;
        }
    }
    //Printing Debug Values
    #ifdef DEBUG
    debugPrint(dist);
    #endif
}

// Because C Does Not Like Redefinitions of Main, This Checks If Its Being Run Directly Or Is It Being Run By A Function Call
#ifndef _MANUALRUN
int main(){

    //todo
    //int vertexes = 13;
    //int nodes = 10;

    //Test Values

	int map[BF_MAX_SIZE][BF_MAX_SIZE] = {
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

	int cMap[BF_MAX_SIZE][BF_MAX_SIZE] = {
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

#endif // _MANUALRUN