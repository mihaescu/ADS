#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>

#include"AVL.h"
#include "AVL_Test.h"
int main()
{
	int aux;
	int key;
	char option;

	NodeAVL *root = NULL;
    printf("meniu(m) , input(i) , testare(t)?\n");
    scanf("%c",&option);
    FILE *fp = fopen ( "input.txt", "r" );

	if (!fp)
	{
		perror ( "Unable to open file" );
		exit(0);
	}
    if(option=='m')
      print_menu(root);
    else
        if(option=='i')
            {
                while(!feof(fp))
                {
                fscanf(fp, "%c", &option);

                    if( option == 'I' )
                    {
                        fscanf(fp, "%d", &key);
                        root = insertAVLNode( root, key );
                    }
                    else if( option == 'D' )
                    {
                        fscanf(fp, "%d", &key);
                        root = deleteAVLNode( root, key );
                    }
                }
                    fclose(fp);

                    displayAVLTree(root,10);

            }
                else if(option == 't')
                {
                    buildInput(10,1,30,"date.txt");
                        if(test_insertAVLNode("date.txt",0))
                            {
                                cout<<"Inserarea functioneaza!"<<endl;
                                if(cout<<"Afisare arbore? Da-1 Nu-0 " && cin>>aux && aux)
                                    cout<<test_insertAVLNode("date.txt",aux);
                            }
                        else
                            cout<<"Inserarea NU functioneaza!";

                        if(test_deleteAVLNode("date.txt",0))
                            {
                                cout<<endl<<"Stergerea functioneaza!"<<endl;
                                if( cout<<"Afisare pasi stergere? Da-1 Nu-0 " && cin>>aux && aux)
                                    test_deleteAVLNode("date.txt",1);
                            }
                        else
                            cout<<"Stergerea NU functioneaza!"<<endl;
                }

	return 0;
}
