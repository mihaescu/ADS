#include "prototypes.h"


void Display( Node *root, int nivel )
{
    int i;

    if( root != 0 ) {
        Display( root->right, nivel + 1 );

        for( i = 0; i <= nivel; i++ ) {
            printf( "      " );
        }

        printf( "%d\n", root->data );
        Display( root->left, nivel + 1 );
    }
}


void preorder( Node *root )
{

    if( root != NULL ) {

        printf( "\n%d", root->data );

        preorder( root->left );
        preorder( root->right );
    }
}


void inorder( Node *root )
{

    if( root != NULL ) {
        inorder( root->left );
        printf( "\n%d", root->data );
        inorder( root->right );
    }
}


void postorder( Node *root )
{
    if( root != NULL ) {
        postorder( root->left );
        postorder( root->right );
        printf( "\n%d", root->data );
    }
}


Node *FindMin( Node *root )
{
    while( root->left != NULL ) {
        root = root->left;
    }

    return root;
}


Node *Delete( Node *root, int data )
{
    if( root == NULL ) {
        return root;
    } else if( data < root->data ) {
        root->left = Delete( root->left, data );
    }

    else if( data > root->data ) {
        root->right = Delete( root->right, data );
    }

    else {

        if( root->left == NULL && root->right == NULL ) {
            free( root );
            root = NULL;
        }

        else if( root->left == NULL ) {
            Node *temp = root;
            root = root->right;
            free( temp );
        } else if( root->right == NULL ) {
            Node *temp = root;
            root = root->left;
            free( temp );
        }

        else {
            Node *temp = FindMin( root->right );
            root->data = temp->data;
            root->right = Delete( root->right, temp->data );
        }
    }

    return root;
}


Node *Add_Node( Node *root, int data )
{


    if( root == NULL ) {
        root = ( Node * ) malloc( sizeof( Node ) );
        root->data = data;
        root->left = root->right = NULL;
    } else if( data <= root->data ) {
        root->left = Add_Node( root->left, data );
    } else {
        root->right = Add_Node( root->right, data );
    }

    return root;
}


int getMin( Node *node )
{
    Node *node_iterator = node;

    while( node_iterator->left != NULL ) {
        node_iterator = node_iterator->left;
    }

    return ( node_iterator->data );
}


int getMax( Node *node )
{
    Node *node_iterator = node;

    while( node_iterator->right != NULL ) {
        node_iterator = node_iterator->right;
    }

    return ( node_iterator->data );
}


int randomNumberGenerator()
{
    return rand() % G_plaja_valori;
}


bool checkValues( Node *node, int minimum, int maximum )
{
    int global_minimum = getMin(node);
    int global_maximum = getMax(node);

        if( global_minimum <= minimum && global_maximum <= maximum ) {
        if( node->data < global_maximum && node->data > global_minimum ) {
            return checkValues( node->left, minimum, maximum );
            return checkValues( node->right, minimum, maximum );
        }

        return true;
    } else {
        return false;
    }
}
