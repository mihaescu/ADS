#include "prototypes.h"

Node *root = NULL;


int main()

{

    int i, n, x, minimum, maximum,g_minimum, g_maximum;

    do {
        printf( "\n1.Adauga un nod" );
        printf( "\n2.Sterge un nod" );
        printf( "\n3.Preorder" );
        printf( "\n4.Inorder" );
        printf( "\n5.Postorder" );
        printf( "\n6.Arborescenta" );
        printf( "\n7.Minim si Maxim" );
        printf( "\n8.Inserare aleatorie" );
        printf( "\n9.Verificare valori" );
        printf( "\n10.Fisier de testare:" );
        printf( "\n11.Iesire" );
        printf( "\n\nOptiunea dumneavoastra: " );
        scanf( "%d", &i );

        switch( i ) {
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

                    if( root != NULL ) {
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

                    for( iterator1 = 0; iterator1 < numar_valori; iterator1++ ) {
                        root = Add_Node( root, randomNumberGenerator() );
                    }

                    break;
                }

            case 9: {
                    if( root != NULL ) {
                        printf( "\n Introduceti valori pentru minim si maxim:" );
                        scanf( "%d %d", &minimum, &maximum );

                        g_maximum = getMax( root );
                        g_minimum = getMin( root );

                        bool status = checkValues( root, minimum, maximum );


                        if( true == status ) {
                            printf( "\nOK!\n" );
                        } else {
                            printf( "\nNU!\n" );
                        }

                        break;
                    } else {
                        printf( "\nEmpty tree!\n" );
                        break;
                    }


                }

            case 10: {
                    int key;
                    char option;
                    FILE *fp = fopen( "input.txt", "r" );

                    if( !fp ) {
                        perror( "Unable to open file" );
                        exit( 0 );
                    } else {
                        while( !feof( fp ) ) {
                            fscanf( fp, "%c", &option );

                            if( option == 'I' ) {
                                fscanf( fp, "%d", &key );
                                root = Add_Node( root, key );
                            } else if( option == 'D' ) {
                                fscanf( fp, "%d", &key );
                                root = Delete( root, key );
                            } else if( option == 'M' ) {
                                g_maximum = getMax( root );
                                g_minimum = getMin( root );
                                printf( "\n The GLOBAL minimum and maximum are :%d %d", g_minimum, g_maximum );
                            } else if( option == 'V' ) {
                                if( root != NULL ) {
                                    printf( "\n Introduceti valori pentru minim si maxim:" );
                                    scanf( "%d %d", &minimum, &maximum );
                                    g_maximum = getMax( root );
                                    g_minimum = getMin( root );
                                    bool status = checkValues( root, minimum, maximum );

                                    if( true == status ) {
                                        printf( "\nOK!\n" );
                                    } else {
                                        printf( "\nNU!\n" );
                                    }

                                    break;

                                } else {
                                    printf( "\nEmpty tree!\n" );
                                    break;
                                }
                            }
                        }

                        fclose( fp );

                    }//end else




                    break;

                }

            case 11:
                exit( 0 );
        }



    } while( i );
}


