#include <stdio.h> 
#include<windows.h>
#define MAXNUM 30 /* Maximum number of points */ 
#define MINIMUM 10000 /* Initial value when searching for minimum */ 
int n; /* Number of points */
int d[MAXNUM][MAXNUM]; /* Distance matrix */
int path[MAXNUM]; /* Path of the traveling salesman; contains the indexes of the visited
				  points*/
int visited[MAXNUM]; /* Array that contains information about what points have been visited*/


/*Function that chooses which point will be visited next */
void choose(int last, int *min, int *j_min) {
	int j;
	/* The minimum distance to a point not yet visited is searched */
	*min = MINIMUM; *j_min = -1;
	for (j = 0; j<n; j++)
	if (!visited[j]) {
		if ((d[last][j] < *min) && (d[last][j]>0)) {
			*min = d[last][j];
			*j_min = j;
		}
	}
}

int main() {

	FILE *fin;
	int i, j, index, count, cost, min, j_min, save_cost = MINIMUM, save_path[MAXNUM];
	fin = fopen("euristic.txt", "rt"); if (!fin) {
		printf("ERROR: cannot open file.\n");
		return -1;
	}
	fscanf(fin, "%d", &n); /* Read input from file */
	for (i = 0; i<n; i++)
	for (j = 0; j<n; j++)
		fscanf(fin, "%d", &(d[i][j]));
	printf("%d points.\n", n);
	printf("Distances between points:\n");
	for (i = 0; i<n; i++) {
		for (j = 0; j<n; j++)
			printf("%d ", d[i][j]);
		printf("\n");
	}
	printf("\n");

	/* First point visited is of index 0 */
	for (index = 0; index<n; index++){
		printf("We start at point %d\n", index + 1);
		min = MINIMUM;
		j_min = MINIMUM;
		for (i = 0; i<n; i++){
			visited[i] = 0; /* Initially no point is visited */
			path[i] = 0;
		}
		path[0] = index; visited[index] = 1;
		count = 1; cost = 0;
		/* The rest of the points are visited */
		for (i = 0; i<n - 1; i++) {
			/* We choose next point to be visited */
			choose(path[count - 1], &min, &j_min);
			printf("Connected (%d, %d) of cost %d.\n", path[count - 1] + 1, j_min + 1,
				min);
			path[count] = j_min;
			visited[j_min] = 1;
			count++;
			cost += min;
		}
		/* We go through the path from the last visited point
		to the first one and we update the total cost*/
		cost += d[path[n - 1]][index];
		/* Display chosen path */
		printf("\nPath has cost %d and is:\n", cost);
		for (i = 0; i<n; i++)
			printf("%d ", path[i] + 1);
		printf("%d\n\n\n\n", index + 1);
		if (cost<save_cost){
			for (i = 0; i<n; i++)
				save_path[i] = path[i];
			save_cost = cost;
		}
	}
	/* Display chosen path */
	printf("\nShortest path starts at point %d has cost %d and is:\n", save_path[0]+1, save_cost);
	for (i = 0; i<n; i++)
		printf("%d ", save_path[i] + 1);
	printf("%d\n\n\n\n", save_path[0]+1);
	return 0;

}
