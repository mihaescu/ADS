#include "core/graph.h"

#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define INFINITE 10000000

/*Push-Relabel function 
@param adjMatrixGraph *G - flow network
@param int source - start node
@param int sink - destination node

@return maxFlow value
*/
int pushRelabel(adjMatrixGraph *G, int source, int sink);
