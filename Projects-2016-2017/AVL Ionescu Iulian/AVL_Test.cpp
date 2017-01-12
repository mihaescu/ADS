#include "AVL_Test.h"
#include "AVL.h"
//Function used to test if insertion function works
int test_insertAVLNode(char *file,int arborescenta)
{
    int key;
    int found = 1;
    int is_avl = 1;
    NodeAVL *root = NULL;
	//open an input file passed as parameter
	FILE *f = fopen(file,"r");
	//call insert all keys into an AVL tree
    while(fscanf(f,"%d",&key) == 1 && is_avl == 1 )
        {
            root= insertAVLNode(root,key);
            is_avl = isAVLTree(root);
        }

    fclose(f);
	//search all keys from the file into AVL tree
    FILE *fp = fopen(file,"r");

	if(is_avl)
        while(fscanf(fp,"%d",&key) == 1 && found == 1)
            {
                search_node( root, key, &found );
            }

    fclose(fp);
    //verify if it is an AVL tree
    if(found)
	    {
	        if(is_avl)
                {
                    if(arborescenta)
                        displayAVLTree(root,10);
                    return 1;
                }
            else
                {
                    printf("It is not AVL tree !\n");
                    return 0;
                }
	    }
    else
    {
        printf("Some keys were not insert");
        return 0;
    }
}

//FUNTION TO VERIFY IF IT'S AVL TREE
int isAVLTree(NodeAVL *root)
{
   int lh; /* for height of left subtree */
   int rh; /* for height of right subtree */

   /* If tree is empty then return true */
   if(root == NULL)
    return 1;

   /* Get the height of left and right sub trees */
   lh = maxPathLength(root->left);
   rh = maxPathLength(root->right);

   if( abs(lh-rh) <= 1 &&
       isAVLTree(root->left) &&
       isAVLTree(root->right))
     return 1;

   /* If we reach here then tree is not height-balanced */
   return 0;
}
//Function used to generate a input of [size] numbers, all values are different
void buildInput (int size, int min, int max, char file[]){
    FILE *g = fopen(file,"w");
    srand(time(NULL));
    int *vizitat,i,nr;
    vizitat = new int [size];
    for(i=0; i<size; i++ )
        vizitat[i]=0;
    while(size!=0)
        {
            nr=rand()% max + min;
            if(vizitat[nr-min]==0)
                {
                    fprintf(g,"%d\n",nr);
                    vizitat[nr-min]=1;
                    size--;
                }
        }
    fclose(g);
}
//Function used to test if delete function works
int test_deleteAVLNode(char *file,int arborescenta)
{
    int key;
    int found = 0;
    int is_avl = 1;
    NodeAVL *root = NULL;
    //open an input file passed as parameter
    FILE *f = fopen(file,"r");
    //call insert all keys into an AVL tree//while(f>>key)
    while(fscanf(f,"%d",&key) == 1)
        {
            root= insertAVLNode(root,key);
        }
    fclose(f);
    //We will delete a node and then search it in tree
    //If it is not found and tree is AVL, the delete function works
    FILE *fp = fopen(file,"r");
    while(fscanf(fp,"%d",&key) == 1 && is_avl==1 && found==0)
    {
        if(arborescenta)
            {

                displayAVLTree(root,10);
                printf("vom sterge nodul %d\n",key);
            }
        root = deleteAVLNode(root , key);
        if(root!=NULL)
        {
            is_avl = isAVLTree(root);
            search_node(root, key, &found);

        }
    }
    fclose(fp);
    if(found == 0 )
    {
        if(is_avl == 1)
        {
            return 1;
        }
        else
        {
            printf("It is not AVL tree !\n");
            return 0;
        }
    }
    else
    {
        printf("Some keys were not delete!\n");
        return 0;
    }

}
