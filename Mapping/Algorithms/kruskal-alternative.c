/**
 * @file kruskal-alternative.c
 * 
 * @brief Implementation of kruskal algorithm in C, TODO
 * 
 * Detailed walkthrought comming soon!
 *  
 */

#include "main.h"

//Define Maximum Sizes
#define KS_ALT_MAX_SIZE 9

/**
 * @brief TODO
 */
int kruskals_alt(int map[KS_ALT_MAX_SIZE][KS_ALT_MAX_SIZE], int cMap[KS_ALT_MAX_SIZE][KS_ALT_MAX_SIZE], int start){
    //TODO
}


/**
 * @brief TODO
 */
#ifdef _DEFMAIN
int main(){
	/*
	int map[KS_ALT_MAX_SIZE][KS_ALT_MAX_SIZE] = {
	{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
	{4, 0, 8, 0, 0, 0, 0, 11, 0}, 
	{0, 8, 0, 7, 0, 4, 0, 0, 2}, 
	{0, 0, 7, 0, 9, 14, 0, 0, 0}, 
	{0, 0, 0, 9, 0, 10, 0, 0, 0}, 
	{0, 0, 4, 14, 10, 0, 2, 0, 0}, 
	{0, 0, 0, 0, 0, 2, 0, 1, 6}, 
	{8, 11, 0, 0, 0, 0, 1, 0, 7}, 
	{0, 0, 2, 0, 0, 0, 6, 7, 0}};

	int cMap[KS_ALT_MAX_SIZE][KS_ALT_MAX_SIZE] = {
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

	int map[KS_ALT_MAX_SIZE][KS_ALT_MAX_SIZE] = {
		{0, 2, 0, 6, 0}, 
        {2, 0, 3, 8, 5}, 
        {0, 3, 0, 0, 7}, 
        {6, 8, 0, 0, 9}, 
        {0, 5, 7, 9, 0}
    };

	int cMap[KS_ALT_MAX_SIZE][KS_ALT_MAX_SIZE] = {
		{0, 1, 0, 1, 0}, 
        {1, 0, 1, 1, 1}, 
        {0, 1, 0, 0, 1}, 
        {1, 1, 0, 0, 1}, 
        {0, 1, 1, 1, 0}
    };

	prim(map, cMap, 0);
}
#endif // _DEFMAIN