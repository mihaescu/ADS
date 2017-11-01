#include "prototypes.h"


//The function prints the BST like a tree
void Display( Node *root, int nivel )
{
    //Setting up an iterator
    int i;

    //Checking if the node is NULL
    if( root != 0 ) {
        //If not, go right and print next level
        Display( root->right, nivel + 1 );

        //Print as many spaces as the level (the root has no spaces)
        for( i = 0; i <= nivel; i++ ) {
            printf( "      " );
        }

        //Print the values of the nodes
        printf( "%d\n", root->data );

        //Go left and print the next level
        Display( root->left, nivel + 1 );
    }
}


//The function prints all the values in the BST likewise: root, left, right
void preorder( Node *root )
{
    //Check if the node is NULL
    if( root != NULL ) {

        //If not, print its value
        printf( "\n%d", root->data );

        //Recur left
        preorder( root->left );
        //Recur right
        preorder( root->right );
    }
}


//The function prints all the values in the BST likewise: left, root, right
void inorder( Node *root )
{
    ////Check if the node is NULL
    if( root != NULL ) {
        //If not recur left
        inorder( root->left );
        //Print its value
        printf( "\n%d", root->data );
        //Recur right
        inorder( root->right );
    }
}


//The function prints all the values in the BST likewise: right, left root
void postorder( Node *root )
{
    //Check if the node is NULL
    if( root != NULL ) {
        //Recur left
        postorder( root->left );
        //Recur right
        postorder( root->right );
        //Print its data
        printf( "\n%d", root->data );
    }
}


//The function is used later to determine the successor value of a node
Node *FindMin( Node *root )
{
    //Go to the last value of the left sub-tree
    while( root->left != NULL ) {
        root = root->left;
    }

    //Return the last found node
    return root;
}


//This function is used to delete a node from the BST
Node *Delete( Node *root, int data )
{
    //Find the position of the node to be deleted
    //Check if the node is NULL
    if( root == NULL ) {
        //If true return it
        return root;
    } else if( data < root->data ) {
        //Else recur left (the value is smaller than the current node's)
        root->left = Delete( root->left, data );
    }

    else if( data > root->data ) {
        //Else recur right (the value is greater than the current node's)
        root->right = Delete( root->right, data );
    }

    else {
        //If both children are NULL, the node is a leaf. Deallocate its memory and set it to NULL
        if( root->left == NULL && root->right == NULL ) {
            //Deallocating memory
            free( root );
            //Setting it to NULL
            root = NULL;
        //If the node has a child on the right (no child on the left).
        } else if( root->left == NULL ) {
            //Create a temporary node and initialize it to the current working node
            Node *temp = root;
            //Set it to point to its right child
            root = root->right;
            //Deallocate memory
            free( temp );
        //If the node has a child on the left (no child on the right)
        } else if( root->right == NULL ) {
            //Create a temporary node and initialize it to the current working node
            Node *temp = root;
            //Set it to point to its left child
            root = root->left;
            //Deallocate memory
            free( temp );
        }
        //If it has two children (both right and left are non-NULL)
        else {
            //Create a temporary node and initialize it to the successor of the node. (the smallest value from the right sub-tree)
            Node *temp = FindMin( root->right );
            //Node's data is replaced by the successor's data
            root->data = temp->data;
            //Delete the successor node from the BST.
            root->right = Delete( root->right, temp->data );
        }
    }

    //Return the node
    return root;
}


//Insert a new value in the BST
Node *Add_Node( Node *root, int data )
{
    //Check if the current node is a NULL
    if( root == NULL ) {
        //If yes, then allocate memory to the size of a node
        root = ( Node * ) malloc( sizeof( Node ) );
        //Set its data to whatever value you want to insert
        root->data = data;
        //Set both of its children to NULL (every node is inserted as a LEAF!)
        root->left = root->right = NULL;
    //Else recur left (the value we want to insert is smaller than the current node's)
    } else if( data <= root->data ) {
        //Recur left
        root->left = Add_Node( root->left, data );
    //Else recur right (the value we want to insert is greater than the current node's)
    } else {
        //Recur right
        root->right = Add_Node( root->right, data );
    }

    //Return the node
    return root;
}


//The function determines the smallest value in the BST
int getMin( Node *node )
{
    //Create a temporary node and initialize it to root. (that's how me make the function call)
    Node *node_iterator = node;

    //Go the last left node
    while( node_iterator->left != NULL ) {
        node_iterator = node_iterator->left;
    }

    //Return the smallest value
    return ( node_iterator->data );
}


//The function determines the greatest value in the BST
int getMax( Node *node )
{
    //Create a temporary node and initialize it to root. (that's how me make the function call)
    Node *node_iterator = node;

    //Go to the last right node
    while( node_iterator->right != NULL ) {
        node_iterator = node_iterator->right;
    }

    //Return the greatest value
    return ( node_iterator->data );
}


//A function which returns a random value
int randomNumberGenerator()
{
    //Using the built-in rand function
    return rand() % G_plaja_valori;
}


//The function determines if all the BST's values are bounded by 2 values
bool checkValues( Node *node, int minimum, int maximum )
{
    //Get the global minimum and maximum of the BST
    int global_minimum = getMin( node );
    int global_maximum = getMax( node );

    //Check if the BST minimum and maximum are bounded by the 2 values
    if( global_minimum <= minimum && global_maximum <= maximum ) {
        //If true, proceed to check all the node's values are bounded by those 2 values
        //Check if the current node's data is bounded and recur left and right
        if( node->data < global_maximum && node->data > global_minimum ) {
            //Check the left child's data
            return checkValues( node->left, minimum, maximum );
            //Check the right child's data
            return checkValues( node->right, minimum, maximum );
        }
        //Return true if all the values are bounded
        return true;
    } else {
        //Return false otherwise
        return false;
    }
}
