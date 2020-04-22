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

struct cacheList clist;


int cacheGET(char get[MAX_VARIABLE_LENGTH])
{
    for (int i = 0; i < MAX_VARIABLE_NUMBER; i++)  // For every cache in clist
    {
        if (strcmp(clist.caches[i].name, get) == 0)      // If found
        {
            return clist.caches[i].value;
        } 
        
    }
    return NEG_INFINITY; // Chance are user didn't cache NEG_INFINITY so it is error code
}

int cacheSET(char get[MAX_VARIABLE_LENGTH], int value)
{
    for (int i = 0; i < MAX_VARIABLE_NUMBER; i++)
    {
        if (strcmp(clist.caches[i].name, get) == 0)   // Replacing
        {
            strcpy(clist.caches[i].name, get);
            clist.caches[i].value = value;
            return 0;
        } else if (strcmp(clist.caches[i].name, "\0") == 0) {  // Creating
            strcpy(clist.caches[i].name, get);
            clist.caches[i].value = value;
            return 0;
        }
        
    }
    return 1; // Cache full
}


//Main Function For Testing! Uncomment When needed
//Because C Does Not Like Redefinitions of Main, This Checks If Its Being Run Directly Or If Its Being Included
#ifdef _DEFMAIN
int main(void)
{
    cacheSET("hello", -1);
    cacheSET("hi", 1);
    cacheSET("hello", -1);
    cacheGET("hi");
    return 0;
}
#endif // _DEFMAIN