#include"prototypes.h"

using namespace std;
bool is_search;
int main()

{
	Node *root = NULL;
	srand (time(NULL));
	int sum=0;
	int i, n, x, choice;
	fstream f;
	f.open("numbers.txt");
	fstream g;
	g.open("original.txt");
    cout<< "1.new random tree"<<endl<<"2.use last tree"<<endl<<"3.exit"<<endl;
    cin >> choice;
    if(choice == 1)
        {
        printf("\nInsert the number of nodes");
        cin>>n;
        g<<n;

        for ( i=0; i<n ; i++){
        //loop used to insert random unique values in the tree
                x = rand()%100000;
                is_search = Search(root,x);
                while (is_search==true){
                    x = rand()%100000;
                    is_search = Search(root,x);
                }
                root = Add_Node(root, x);
                g<<endl;
                g<<x;

        }

        //Display(root, 0); //uncomment to display the tree
        //printf("\n\n\n\n");

        for(i=0 ; i<n*n ; i++){
        //loop used to delete then insert random unique values in the tree

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

        f<<n<<endl;
        insert_in_file(f, root);

        //Display(root, 0);//uncomment to display the tree
    cout<<endl<<"Average path length of the tree is :"<<internalPathLength(root,sum)/n + 1;


    }else{
        g>>n;
        int ok=0;
        while (!g.eof()){
            if (ok == n) break;
            g>>x;
            root = Add_Node(root,x);
            ok++;
        }

        for(i=0 ; i<n*n ; i++){
        //loop used to delete then insert random unique values in the tree

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
                is_search = Search(root,x);
                }
             root = Add_Node(root, x);

        }
        cout<<"do you want to rewrite the content in the file that holds the final version of the tree"<<endl;
        cout<<"or save the current tree in a different file to compare them"<<endl<<"1.rewrite"<<endl<<"2.different file"<<endl;
        cin>>choice;
        if(choice == 1){
            f<<n<<" ";
            insert_in_file(f, root);
        }else{
            fstream h;
            h.open("tempfile.txt");
            h<<n<<endl;
            insert_in_file(h, root);
            h.close();
        }
        cout<<endl<<"Average path length of the tree is :"<<internalPathLength(root,sum)/n + 1;

    }

    f.close();
    g.close();
    return 0;
}
