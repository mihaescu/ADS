#include "AVL.h"

int max( int a, int b)
{
	return ( a>b ? a:b );
}

//calculates the longest path from a current node to a leaf
int maxPathLength (NodeAVL *node)
{
	if( node == NULL )
		return 0;
	return ( max( maxPathLength( node->right ), maxPathLength( node->left) ) +1 );
}

//calculates the balance indicator of each node of the tree
void computeBalanceFactor (NodeAVL *node)
{
	int maxLeft = 0, maxRight = 0;

	if( node->left!=NULL )
		maxLeft = maxPathLength ( node->left );
	else
		maxLeft = 0;

	if( node->right!=NULL )
		maxRight = maxPathLength ( node->right );
	else
		maxRight = 0;

	node->echi = maxRight - maxLeft;
}

//simple left rotation
NodeAVL* leftRotation (NodeAVL *node)	//p is critical node
{
	NodeAVL *heavyChild;

	heavyChild = node->right;
	node->right = heavyChild->left;
	heavyChild->left = node;

	computeBalanceFactor(node);
	computeBalanceFactor(heavyChild);

	node = heavyChild;
	return node;
}

//simple right rotation
NodeAVL* rightRotation (NodeAVL *node)
{
	NodeAVL *heavyChild;

	heavyChild = node->left;
	node->left = heavyChild->right;
	heavyChild->right = node;

	computeBalanceFactor(node);
	computeBalanceFactor(heavyChild);

	node = heavyChild;
	return node;
}

//double left rotation
NodeAVL* doubleLeftRotation (NodeAVL *node)
{
	node->right = rightRotation( node->right );
	node = leftRotation(node);
	return node;
}

//double right rotation
NodeAVL* doubleRightRotation (NodeAVL *node)
{
	node->left = leftRotation( node->left );
	node = rightRotation(node);
	return node;
}

//tree balancing function
NodeAVL* balance(NodeAVL *node)
{
	NodeAVL *heavyChild;

	computeBalanceFactor(node);

	if( node->echi == -2 )	// if p is a critical junction (LEFT hanging)
	{
		heavyChild = node->left;	// heavyChild - left child of p

		if ( heavyChild->echi == 1 )
			node = doubleRightRotation(node);
		else
			node = rightRotation(node);
	}
	else
		if( node->echi == 2)		// // if p is a critical junction (RIGHT hanging)
		{
			heavyChild = node->right;	// heavyChild - right child of p

			if ( heavyChild->echi == -1 )
				node = doubleLeftRotation(node);
			else
				node = leftRotation(node);
		}

	return node;
}

//function for inserting a node
NodeAVL* insertAVLNode( NodeAVL* node, int value)
{
	if( node == NULL )
	{
		node = new NodeAVL;
		node->key = value;
		node->echi = 0;
		node->left = NULL;
		node->right = NULL;
		return node;
	}
	else
		if ( value < node->key )
			node->left = insertAVLNode( node->left, value );
		else
			if ( value > node->key )
				node->right = insertAVLNode( node->right, value );
			else
				printf("The key %d already exists! \n", value);

	node = balance(node);

	return node;
}

//printing function
void displayAVLTree( NodeAVL *node, int level )
{
	if( node !=NULL )
	{
		displayAVLTree( node->right, level+7 );
		for( int i = 0; i < level; i++ )
			printf(" ");

		printf("%d(%d) \n", node->key, node->echi);
		displayAVLTree( node->left, level+7 );
	}
}



void search_node(NodeAVL *node, int value,int *found)
{

    if (node == NULL)
	{
		*found=0;
	}


    if ( value < node->key && node->left!=NULL)
        {
            search_node(node->left,value,found);
        }
	else
        if( value > node->key && node->right!=NULL)
            {
               search_node(node->right, value,found);
            }
        else
        {
            if(value==node->key)
                *found=1;
            else
                *found=0;
        }

}
//function for deleting a node
NodeAVL* deleteAVLNode( NodeAVL *node, int value)
{
	if (node == NULL)
	{
		printf("Can't delete key %d, it is not in AVL tree!\n", value);
		return node;
	}


	if ( value < node->key )
		node->left = deleteAVLNode(node->left, value);

	else if( value > node->key )
		node->right = deleteAVLNode(node->right, value);

	else
	{
        // node with only one child or no child
		if( (node->left == NULL) || (node->right == NULL) )
		{
		    NodeAVL *temp;

			if( node->left != NULL )
				temp = node->left;
			else
				temp = node->right;

            // No child case
			if(temp == NULL)
				{
				    node = NULL;
				}

			else // One child case
			{
				*node = *temp;
				free(temp);
			}

        }
		else
		{
            // node with two children: Get the inorder successor
            // (smallest in the right subtree)
			NodeAVL * temp = node->right;

			while (temp->left != NULL)
				temp = temp->left;

            // Copy the inorder successor's data to this node
			node->key = temp->key;

            // Delete the inorder successor
			node->right = deleteAVLNode(node->right, temp->key);
		}
	}

    // If the tree had only one node then return
    if (node != NULL)
        node = balance(node);

	return node;
}

void print_menu(NodeAVL *root)
{
    int i,n,x,found=0;
    do
    {
        printf("\n1.Add node");
        printf("\n2.Delete node");
        printf("\n3.Search node");
        printf("\n6.Display tree");
        printf("\n\nYour option:  ");
        scanf("%d",&i);
        switch(i)
        {
        case 1:
            scanf("%d",&n);
            root = insertAVLNode( root, n );
            break;
        case 2:
            printf("\nType the node key to delete");
            scanf("%d",&x);
            root = deleteAVLNode( root, x );
            break;
        case 3:
            printf("\nType the node key to search");
            scanf("%d",&x);
           search_node(root, x,&found);
            if(found == 1 )
                cout<<"found ! "<<endl;
            else
                cout<<"not found !"<<endl;

        case 6:
            displayAVLTree(root,10);
            break;
        }
    }while(i);
}
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
    else
    {
        printf("It is not AVL tree !\n");
        return 0;
    }

    fclose(fp);

    if(found)
	    {
            if(arborescenta)
                displayAVLTree(root,10);
            return 1;
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
    //insert all keys into an AVL tree
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

