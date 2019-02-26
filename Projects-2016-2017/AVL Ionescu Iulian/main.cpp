//#include<stdio.h>
//#include<stdlib.h>
//#include<iostream>
//#include<time.h>

#include"AVL.h"
int main()
{
	int found;
	int key;
	NodeAVL *root = NULL;

    FILE *fp = fopen ( "input.txt", "r" );
	if (!fp)
	{
		perror ( "Unable to open file" );
		exit(0);
	}
	//secventa de apeluri
	while(fscanf(fp,"%d",&key) == 1)
    {
        root = insertAVLNode( root, key );
    }
    displayAVLTree(root, 10);
    printf("\nDelete value 8\n");
    root = deleteAVLNode(root , 8);
    displayAVLTree(root, 10);
    root = deleteAVLNode(root , 9);
    root = insertAVLNode( root, 10 );
    root = insertAVLNode( root, 11 );
    displayAVLTree(root, 10);
    search_node(root,11,&found);
    if (found == 1)
        printf("Value %d found\n",11);
    else
        printf("Value %d not found\n",11);
    search_node(root,20,&found);
    if (found == 1)
        printf("Value %d found\n",12);
    else
        printf("Value %d not found\n",12);


    //afisare meniu
    //print_menu(root);

    //testare functii
    /*buildInput(10,1,30,"date.txt");
    if(test_insertAVLNode("date.txt",0))
        {
            cout<<"Inserarea functioneaza!"<<endl;
            if(cout<<"Afisare arbore? Da-1 Nu-0 " && cin>>key && key)
                cout<<test_insertAVLNode("date.txt",1);
        }
    else
        cout<<"Inserarea NU functioneaza!";

    if(test_deleteAVLNode("date.txt",0))
        {
            cout<<endl<<"Stergerea functioneaza!"<<endl;
            if( cout<<"Afisare pasi stergere? Da-1 Nu-0 " && cin>>key && key)
                test_deleteAVLNode("date.txt",1);
        }
    else
        cout<<"Stergerea NU functioneaza!"<<endl;
    */


	return 0;
}
