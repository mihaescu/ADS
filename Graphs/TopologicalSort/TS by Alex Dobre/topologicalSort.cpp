#include "topologicalSort.h"
#include <malloc.h>
#include <stdlib.h>
using namespace std;
/**
*This function implements depth-first search and checks if a specified graph contains any cycle.
*G - the graph to be checked.
*n - the node to be visited.
*list - a stack that stores visiting times for each vertex
*stackSize - stack's size.
* Returns 0 if this graph contains any cycle, 1 otherwise.
*/
int TopSortDFS(graph *G, int n, color* state, int* list,int* stackSize)
{
	int i = 0;
	state[n] = gray;
	std::vector<int>  adjNodes = getAdjNodes(G, n);
	std::vector<int>::iterator it = adjNodes.begin();
	for (it; it != adjNodes.end(); ++it)
	{
		if (state[*it] == white)
		{
			if (!TopSortDFS(G, *it, state, list, stackSize))
			{
				return 0;
			}
		}
		else
		{
			// if the vertex had been visited, the this graph contains a cycle.
			if (state[*it] == gray)
			{
				return 0;	
			}
		}
	}
	state[n] = black;
	list[--(*stackSize)] = n;
}

/**
*This function checks if a specified directed graph has cycles and sorts it if this graph is valid.
G - the graph to be sorted.
Returns an array with topological sorted vertices, or NULL if this graph contains cycles.
*/
int* TopologicalSort(graph *G)
{
	int *stack = (int*)(calloc(G->noOfVertices, sizeof(int)));
	color *state = (color*)(calloc(G->noOfVertices + 1, sizeof(color)));
	int i, stackSize = G->noOfVertices;

	for (i = 1; i <= G->noOfVertices; i++)
	{
		if (state[i] == white)
		{
			if (!TopSortDFS(G, i, state, stack, &stackSize))
			{
				return NULL;
			}
		}
	}
	return stack;
}

/**
*This function sorts a specified directed graph using the indegree algorithm.
*Returns an array  that contains the topological sorted vertices, if this graph is acyclic, NULL otherwise.
*/
int* TopSortIndegree(graph *G)
{
	int n = G->noOfVertices;
	int *nodes = (int*)(calloc(n + 1, sizeof(int)));
	int *sortedNodes = (int*)(calloc(n, sizeof(int)));
	int index = -1;
	int i = 1;

	std::vector<int> adjNodes;
	std::queue<int> indegree;
	std::vector<int>::iterator it;

	//store each vertex's indegree
	//all vertices that have indegree = 0 are pushed into a queue
	for (; i <= n; i++)
	{
		adjNodes = getAdjNodes(G, i);
		for (it = adjNodes.begin(); it != adjNodes.end(); ++it)
		{
			nodes[*it]++;
		}
		if (!nodes[i])
		{
			indegree.push(i);
		}
	}

	if (!indegree.size())
	{
		//if all vertices have incoming edges then this graph has a cycle.
		return NULL;
	}

	int cycle, size;
	while (indegree.size()) 
	{
		cycle = 0;
		int node = indegree.front();
		indegree.pop();
		size = indegree.size();

		// dequeue a vertex
		sortedNodes[++index] = node;

		//reduce indegree of all vertices adjacent to it by 1;
		adjNodes = getAdjNodes(G, node);
		for (it = adjNodes.begin(); it != adjNodes.end(); ++it)
		{
			if (!--nodes[*it])
			{
				indegree.push(*it);
			}
			else
			{
				cycle = 1;
			}
		}

		// if there are still vertices in the graph and none of them has indegree 0, then this graph has a cycle.
		if (size == indegree.size() && cycle)
		{
			return NULL;
		}

	}
	return sortedNodes;	
}
