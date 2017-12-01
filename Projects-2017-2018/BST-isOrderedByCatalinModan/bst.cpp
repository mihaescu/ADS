#include "bst.h"

//The function prints the BST like a tree
void Display( Node *node, int level )
{
    //Setting up an iterator
    int i;

    //Checking if the node is NULL
    if ( node != 0 ) {
        //If not, go right and print next level
        Display( node->right, level + 1 );

        //Print as many spaces as the level (the node has no spaces)
        for ( i = 0; i <= level; i++ ) {
            printf( "      " );
        }

        //Print the values of the nodes
        printf( "%d\n", node->data );

        //Go left and print the next level
        Display( node->left, level + 1 );
    }
}

//The function prints all the values in the BST likewise: node, left, right
void preorder( Node *node )
{
    //Check if the node is NULL
    if ( node != NULL ) {

        //If not, print its value
        printf( "\n%d", node->data );

        //Recur left
        preorder( node->left );
        //Recur right
        preorder( node->right );
    }
}

//The function prints all the values in the BST likewise: left, node, right
void inorder( Node *node )
{
    ////Check if the node is NULL
    if ( node != NULL ) {
        //If not recur left
        inorder( node->left );
        //Print its value
        printf( "\n%d", node->data );
        //Recur right
        inorder( node->right );
    }
}

//The function prints all the values in the BST likewise: right, left, node
void postorder( Node *node )
{
    //Check if the node is NULL
    if ( node != NULL ) {
        //Recur left
        postorder( node->left );
        //Recur right
        postorder( node->right );
        //Print its data
        printf( "\n%d", node->data );
    }
}

//The function is used later to determine the successor value of a node
Node *FindMin( Node *node )
{
    //Go to the last value of the left sub-tree
    while ( node->left != NULL ) {
        node = node->left;
    }

    //Return the last found node
    return node;
}

//This function is used to delete a node from the BST
Node *Delete( Node *node, int data )
{
    //Find the position of the node to be deleted
    //Check if the node is NULL
    if ( node == NULL ) {
        //If true return it
        return node;
    } else if ( data < node->data ) {
        //Else recur left (the value is smaller than the current node's)
        node->left = Delete( node->left, data );
    }

    else if ( data > node->data ) {
        //Else recur right (the value is greater than the current node's)
        node->right = Delete( node->right, data );
    }

    else {
        //If both children are NULL, the node is a leaf. Deallocate its memory and set it to NULL
        if ( node->left == NULL && node->right == NULL ) {
            //Deallocating memory
            free( node );
            //Setting it to NULL
            node = NULL;
            //If the node has a child on the right (no child on the left).
        } else if ( node->left == NULL ) {
            //Create a temporary node and initialize it to the current working node
            Node *temp = node;
            //Set it to point to its right child
            node = node->right;
            //Deallocate memory
            free( temp );
            //If the node has a child on the left (no child on the right)
        } else if ( node->right == NULL ) {
            //Create a temporary node and initialize it to the current working node
            Node *temp = node;
            //Set it to point to its left child
            node = node->left;
            //Deallocate memory
            free( temp );
        }
        //If it has two children (both right and left are non-NULL)
        else {
            //Create a temporary node and initialize it to the successor of the node. (the smallest value from the right sub-tree)
            Node *temp = FindMin( node->right );
            //Node's data is replaced by the successor's data
            node->data = temp->data;
            //Delete the successor node from the BST.
            node->right = Delete( node->right, temp->data );
        }
    }

    //Return the node
    return node;
}

//Insert a new value in the BST
Node *Add_Node( Node *node, int data )
{
    //Check if the current node is a NULL
    if ( node == NULL ) {
        //If yes, then allocate memory to the size of a node
        node = ( Node * )malloc( sizeof( Node ) );
        //Set its data to whatever value you want to insert
        node->data = data;
        //Set both of its children to NULL (every node is inserted as a LEAF!)
        node->left = node->right = NULL;
        //Else recur left (the value we want to insert is smaller than the current node's)
    } else if ( data <= node->data ) {
        //Recur left
        node->left = Add_Node( node->left, data );
        //Else recur right (the value we want to insert is greater than the current node's)
    } else {
        //Recur right
        node->right = Add_Node( node->right, data );
    }

    //Return the node
    return node;
}

//The function determines the smallest value in the BST
int getMin( Node *node )
{
    //Create a temporary node and initialize it to root. (that's how me make the function call)
    Node *node_iterator = node;

    //Go the last left node
    while ( node_iterator->left != NULL ) {
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
    while ( node_iterator->right != NULL ) {
        node_iterator = node_iterator->right;
    }

    //Return the greatest value
    return ( node_iterator->data );
}

//A function which returns a random value
int randomNumberGenerator()
{


    //Using the built-in rand function
    return rand() % G_values_limit;
}

//The function determines if all the BST's values are bounded by 2 values
bool checkValues( Node *node, int minimum, int maximum )
{
    //Get the global minimum and maximum of the BST
    int global_minimum = getMin( node );
    int global_maximum = getMax( node );

    //Check if the BST minimum and maximum are bounded by the 2 values
    if ( global_minimum >= minimum && global_maximum <= maximum ) {
        //If true, proceed to check all the node's values are bounded by those 2 values
        //Check if the current node's data is bounded and recur left and right
        if ( node->data < global_maximum && node->data > global_minimum ) {
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

//The function will delete the entire BST
//The call will be made upon the root's address
void deleteBST(Node **node)
{
    //Checking if the current node is NULL
    if(*node == NULL){
        //If true exit
        return;
    }

    //Else delete the node's children
    deleteBST(&(*node)->left);
    deleteBST(&(*node)->right);

    //Check if both children are different from NULL
    if(!(*node)->left && !(*node)->right){
        //Delete the parent
        delete *node;
        //Set the parent to NULL
        *node = NULL;
    }

}


//A function which checks if the BST is empty.
//It will return true if the BST is empty
//The call will be made upon the root
bool isEmpty( Node *node )
{
    //Checking if the node (root) is empty
    if ( node == NULL ) {
        //IF true return true
         printf( "\nEmpty tree!\n" );
        return true;
    }
    //If not return false
    return false;
}


//A function used to test the program "numberOfTests" times
void makeTests(Node *node, int numberOfTests)
{
    //Setting up some local variables
    int bound = 0;
    int global_minimum = 0;
    int global_maximum = 0;
    int minimum = 0;
    int maximum = 0;
    bool status = false;

    //Iterating "numberOfTests" times
    for(int iterator1 = 0; iterator1 <numberOfTests ; iterator1++){
        //Setting the bound for inserting a random number of values
        bound = rand()%(G_values_limit+iterator1);

        //Inserting "bound" number of values
        for (int iterator2 = 0; iterator2 < bound ; iterator2++){
            node = Add_Node(node,randomNumberGenerator());
        }

	
        //Setting up the BST's minimum and maximum;
        global_minimum = getMin(node);
        global_maximum = getMax(node);

        //Setting up the boundedness values
        minimum = rand()%(numberOfTests/100);
        maximum = rand()%((numberOfTests*5));

        //Printing them
        printf("\nBST's minimum and maximum are: %d %d ",global_minimum,global_maximum);
        printf("\nBoundedness values set to %d %d",minimum, maximum);

        //Setting up the status
        status = checkValues(node,minimum,maximum);

        //Printing the result
        if(status==true){
            printf("\nResult -> PASSED! <-------------------------------------------------------------\n");
        }else{
            printf("\nResult -> FAILED\n");
        }

        deleteBST(&node);

    }
}


//A function used to check if a value already exists in the BST
bool search(Node *node, int target)
{
	//Checking if the BST is empty
	if (node == NULL) {
		//If so return false
		return false;
	//Else see if we can find the value 
	} else {
		//If the current node stores the value, return true
		if (node->data == target) {
			return true;
		//Else recur on the right subtree
		} else {
			//IF the value is smaller than the node's, recur to the left
			if (target < node->data) {
				return search(node->left, target);

			//Else recur to the right
			} else {
				return search(node->right, target);
			}
		}
	}
	//If the above code executed, it means the value does not exists i the BST, return false
	return false;
}



