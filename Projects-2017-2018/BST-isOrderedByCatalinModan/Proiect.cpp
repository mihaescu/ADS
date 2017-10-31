#include "prototypes.h"
int global_maximum, global_minimum;
Node *root = NULL;

void Display( Node *root, int nivel )
{
        int i;
        if ( root != 0 ) {
                Display( root->right, nivel + 1 );
                for ( i = 0; i <= nivel; i++ ) {
                        printf( "      " );
                }
                printf( "%d\n", root->data );
                Display( root->left, nivel + 1 );
        }
}



void preorder( Node *root )
{

        if ( root != NULL ) {

                printf( "\n%d", root->data );

                preorder( root->left );
                preorder( root->right );
        }
}
void inorder( Node *root )
{

        if ( root != NULL ) {
                inorder( root->left );
                printf( "\n%d", root->data );
                inorder( root->right );
        }
}
void postorder( Node *root )
{
        if ( root != NULL ) {
                postorder( root->left );
                postorder( root->right );
                printf( "\n%d", root->data );
        }
}

Node *FindMin( Node *root )
{
        while ( root->left != NULL ) {
                root = root->left;
        }
        return root;
}


Node *Delete( Node *root, int data )
{
        if ( root == NULL ) {
                return root;
        } else if ( data < root->data ) {
                root->left = Delete( root->left, data );
        }

        else if ( data > root->data ) {
                root->right = Delete( root->right, data );
        }

        else {

                if ( root->left == NULL && root->right == NULL ) {
                        free( root );
                        root = NULL;
                }

                else if ( root->left == NULL ) {
                        Node *temp = root;
                        root = root->right;
                        free( temp );
                } else if ( root->right == NULL ) {
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


        if ( root == NULL ) {
                root = ( Node * ) malloc( sizeof( Node ) );
                root->data = data;
                root->left = root->right = NULL;
        } else if ( data <= root->data ) {
                root->left = Add_Node( root->left, data );
        } else {
                root->right = Add_Node( root->right, data );
        }
        return root;
}


int getMin( Node *node )
{
        Node *iterator = node;

        while ( iterator->left != NULL ) {
                iterator = iterator->left;
        }

        return ( iterator->data );
}

int getMax( Node *node )
{
        Node *iterator = node;

        while ( iterator->right != NULL ) {
                iterator = iterator->right;
        }

        return ( iterator->data );
}

int randomNumberGenerator()
{
        return rand() % G_plaja_valori;
}


bool checkValues( Node *node, int minimum, int maximum )
{

    if ( global_minimum <= minimum && global_maximum <= maximum ) {
        if ( node->data < global_maximum && node->data > global_minimum ) {


            return checkValues( node->left, minimum, maximum );
            return checkValues( node->right, minimum, maximum );

        }

        return true;
    } else {
        return false;
    }


}



int main()

{

        int i, n, x, minimum, maximum;
        do {
                printf( "\n1.Adauga un nod" );
                printf( "\n2.Sterge un nod" );
                printf( "\n3.Preorder" );
                printf( "\n4.Inorder" );
                printf( "\n5.Postorder" );
                printf( "\n6.Arborescenta" );
                printf( "\n7.Minim si Maxim" );
                printf( "\n8.Inserare aleatorie" );
                printf( "\n9 Verificare valori" );
                printf( "\n10.Iesire" );
                printf( "\n\nOptiunea dumneavoastra: " );
                scanf( "%d", &i );

                switch ( i ) {
                        case 1:
                                scanf( "%d", &n );
                                root = Add_Node( root, n );
                                break;
                        case 2:
                                printf( "\nAlegeti nodul pe care doriti sa-l stergeti" );
                                scanf( "%d", &x );
                                root = Delete( root, x );
                                break;
                        case 3:
                                preorder( root );
                                break;
                        case 4:
                                inorder( root );
                                break;
                        case 5:
                                postorder( root );
                                break;
                        case 6:
                                Display( root, 0 );
                                break;

                        case 7: {

                                        if ( root != NULL ) {
                                                minimum = getMin( root );
                                                maximum = getMax( root );
                                                printf( "\nMinimum: %d \nMaximum %d\n", minimum, maximum );
                                                break;
                                        } else {
                                                printf( "\nEmpty Tree!\n" );
                                                break;
                                        }

                                }

                        case 8: {
                                        int iterator1 = 0, numar_valori = 0;
                                        printf( "\nCate valori doriti sa adaugati?\n" );
                                        scanf( "%d", &numar_valori );

                                        for ( iterator1 = 0; iterator1 < numar_valori; iterator1++ ) {
                                                root = Add_Node( root, randomNumberGenerator() );
                                        }
                                        break;
                                }

                        case 9: {
                                        if ( root != NULL ) {
                                                printf( "\n Introduceti valori pentru minim si maxim:" );
                                                scanf( "%d %d", &minimum, &maximum );

                                                global_maximum = getMax( root );
                                                global_minimum = getMin( root );

                                                bool status = checkValues( root, minimum, maximum );


                                                if ( true == status ) {
                                                        printf( "\n OK!\n" );
                                                } else {
                                                        printf( "\nNU!\n" );
                                                }
                                                break;
                                        }else{
                                            printf("\nEmpty tree!\n");
                                            break;
                                        }


                                }

                        case 10:
                                exit( 0 );
                }



        } while ( i );
}


