#include "main.h"

#define max 100

typedef struct e{
    int u,v,w;
}e;

typedef struct elist{
    e data[max];
    int n;
}elist;

int B[max][max],n;




int main(){

    int i,j,total_cost, n;
	
	printf("\nEnter number of vertices:");
	
	scanf("%d",&n);
	
	printf("\nAdjacency matrix:\n");
	
	for(i=0; i<n; i++){
        for(j = 0; j<n;j++){
		scanf("%d",&B[i][j]);
        }
	}	

    



    
	/*printf("Done inputing the matrix");

    printf("======================\n");
    for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",B[i][j]);
		}
        printf("\n");
	}	
*/

}