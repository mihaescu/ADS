#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>

//#include "AVL_test.h"
#include"AVL.h"

int main()
{
	int key;
	char option;

	NodeAVL *root = NULL;
    printf("meniu(m) sau input(i)?\n");
    scanf("%c",&option);
    if(option=='m')
      afisare_meniu(root);
    else
        if(option=='i')
            {
                FILE *fp = fopen ( "input.txt", "r" );

                if (!fp)
                {
                    perror ( "Unable to open file" );
                    exit(0);
                }

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
                    else if( option == 'C')
                    {
                        int found=0;
                        fscanf(fp, "%d", &key);

                        cauta_nod( root, key, &found);
                        if(found == 1 )
                            cout<<"found ! "<<endl;
                        else
                            cout<<"not found !"<<endl;
                    }

                }

                fclose(fp);

                displayAVLTree(root,10);

                //system("PAUSE");
            }
    buildInput(20,1,68,"date.txt");
    if(test_insertAVLNode("date.txt"))
        cout<<"merge inserarea"<<endl;
    else
        cout<<"nu merge inserarea";

    if(test_deleteAVLNode("date.txt"))
        cout<<"merge stergerea"<<endl;
    else
        cout<<"nu merge stergerea"<<endl;
	return 0;
}
