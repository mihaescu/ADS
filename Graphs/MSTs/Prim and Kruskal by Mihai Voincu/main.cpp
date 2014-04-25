#include "Prim.h"
#include <D:\Programs\Visual Probl\MST\MST\Kruskall.h>

int main(){

	int a[50][50], Q[50], H[50], n = 0, r = 0, k=0;			//----|  Data for
	int i = 0, x, y, z, f1, f2;								//----|		  Prim's Alg

	int p, m, L[20];										//----|  Data for
	muchie u[20];											//----|		  Kruskall's Alg

	char go = 'a';

	struct g{
		int a, b, c;
	}v[50];

	FILE* f;
	f = fopen("cost.txt", "r");

	fscanf(f, "%d", &f1);
	fscanf(f, "%d", &f2);

	while(!feof(f)){

			i++;
			fscanf(f, "%d %d %d", &x,&y,&z);

			v[i].a = x;
			v[i].b = y;
			v[i].c = z;
		
		}

	f1=i;

	k = prim(a, Q, H, n, r);

	while(go != '0'){

		printf("\n ||--Minimum Spanning Trees--|| \n");

		printf("\n 1.Display Graph \n\n 2.Prim's MST \n\n 3.Kruskall's MST \n\n 0.Exit \n ");
		
		go = getch();					

		system("cls");

		switch(go){

		case '1':

			printf("\n Edges and Costs: \n");

			for(i = 1; i <= f1; i++){
				printf("[%d <-> %d] --- cost = %d \n", v[i].a, v[i].b, v[i].c);
			}

			break;

		case '2':

			printf("\n Prim: \n");

			displayMST(H, n);

			printf("\n MST cost = %d \n", k);

			break;

		case '3':

			printf("\n Kruskall: \n");

			krusk(n, m, L, u);

			break;

		case '0':

			break;

		default:

			printf("\n Wrong choice! \n");

			break;

		}

	}

	system("pause");

	fclose(f);

	return 0;
}
