#include"prototypes.h"

using namespace std;
bool is_search;
int main()

{
	Node *root = NULL;
	srand (time(NULL));
	int sum=0;
	int i, n,x;
	printf("\nInsert a number of nodes");
    cin>>n;
    for ( i=0; i<n ; i++){
            x = rand()%100000;
            is_search = Search(root,x);
            while (is_search==true){
                x = rand()%100000;
                is_search = Search(root,x);
            }
            root = Add_Node(root, x);

    }

    //Display(root, 0);

    printf("\n\n\n\n");
    for(i=0 ; i<n*n ; i++){
         x = rand()%100000;
         is_search = Search(root,x);
         while (is_search==false){
                x = rand()%100000;
                is_search = Search(root,x);
            }
         root = Delete(root, x);

         x = rand()%100000;
         is_search = Search(root,x);
         while (is_search==true){
            x = rand()%100000;
            is_search = Search(root,x);
            }
         root = Add_Node(root, x);

    }


			//Display(root, 0);
cout<<endl<<"Average path length of the tree is :"<<internalPathLength(root,sum)/n + 1;

return 0;
}
