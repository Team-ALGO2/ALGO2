#include "../main.h"

/* The cache system for the calc
 * It creates an array of caches of length MAX_VARIABLE_NUMBER
 * Each cache as a name and a value
 * The structure is like this to iterate easier
 * 
 * cacheGET return the value in cache of the input
 * cacheSET sets the value in cache of the input,
 *          creating it if needed
 */


struct cache
{
    char name[MAX_VARIABLE_LENGTH];
    int value;
};

struct cacheList
{
    struct cache caches[MAX_VARIABLE_NUMBER];
};

struct cacheList list;


int cacheGET(char get[MAX_VARIABLE_LENGTH])
{
    for (int i = 0; i < MAX_VARIABLE_NUMBER; i++)  // For every cache in list
    {
        if (strcmp(list.caches[i].name, get) == 0)      // If found
        {
            return list.caches[i].value;
        } 
        
    }
    return NEG_INFINITY; // Chance are user didn't cache NEG_INFINITY so it is error code
}

int cacheSET(char get[MAX_VARIABLE_LENGTH], int value)
{
    for (int i = 0; i < MAX_VARIABLE_NUMBER; i++)
    {
        if (strcmp(list.caches[i].name, get) == 0)   // Replacing
        {
            strcpy(list.caches[i].name, get);
            list.caches[i].value = value;
            return 0;
        } else if (strcmp(list.caches[i].name, "\0") == 0) {  // Creating
            strcpy(list.caches[i].name, get);
            list.caches[i].value = value;
            return 0;
        }
        
    }
    return 1; // Cache full
}
/*
int main(void)
{
    cacheSET("hello", -1);
    cacheSET("hi", 1);
    cacheSET("hello", -1);
    cacheGET("hi");
    return 0;
}
*/