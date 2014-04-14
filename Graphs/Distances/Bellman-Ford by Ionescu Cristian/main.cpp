#include"bellmanford.h"

int main()
{
	FILE *fp = fopen("test1000.txt", "r");
	int average;
	graph* G = loadGraph(fp);
	driverProgram("input.in", "output.out");
	average = speedTest(G);
	printf_s("average time: %d.%d seconds\n", average/1000,average%1000);
	testProgram();
	system("PAUSE");
	return 1;
}
