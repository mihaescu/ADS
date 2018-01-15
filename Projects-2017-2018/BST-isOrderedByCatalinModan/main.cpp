
#include "bst.h"

//Set the root of the BST to NULL (Empty tree)
Node *root = NULL;


int main() {
    //Define iterators and such
    int choice, new_value, del_value, minimum, maximum, g_minimum, g_maximum;

    //Keep the program open and select its tasks
    do {
        //CORE FUNCTIONS
        printf("\n--->Core BST functions:");
        printf("\n1.Insert value:");
        printf("\n2.Delete value:");
        printf("\n3.Search for a value:\n");

        //TRAVERSALS AND DISPLAYING
        printf("\n--->Traversals and displaying:");
        printf("\n4.Preorder:");
        printf("\n5.Inorder:");
        printf("\n6.Postorder:");
        printf("\n7.Print BST:\n");

        //PROJECT RELATED
        printf("\n--->Project-Related:");
        printf("\n8.Minimum and Maximum:");
        printf("\n9.Check boundedness:\n");

        //UTILITIES
        printf("\n--->Utility functions:");
        printf("\n10.Delete the entire BST:");
        printf("\n11.Check if the BST is empty:");
        printf("\n12.Insert n random values: \n");

        //TESTING
        printf("\n--->Testing functions:");
        printf("\n13.Read tasks from file:");
        printf("\n14.Build file and test:");
        printf("\n15.Exit:\n");

        printf("\nYour choice: ");
        scanf("%d", &choice);

        //The switch statement determines which task will be fulfilled
        switch (choice) {
            //Add a node
            case 1: {
                printf("\nNew value: ");
                //Read the node's value
                scanf("%d", &new_value);

                //Checking if the values already exits in the tree, no duplicates allowed
                if (!search(root, new_value)) {
                    //Insert the new value into the BST
                    root = Add_Node(root, new_value);
                } else {
                    printf("%d already exists in the tree ! \n", new_value);
                }

                //Finish the task
                break;
            }//end case 1

                //Delete a node
            case 2: {
                //Checking if the BST is empty
                if (isEmpty(root)) {
                    break;
                } else {
                    //Else begin the deletion procedure
                    printf("\nValue to be deleted:");
                    //Read the value
                    scanf("%d", &del_value);

                    //Checking if the value exists in the BST, if so we can delete it
                    if (search(root, del_value)) {
                        //Delete the node
                        root = Delete(root, del_value);
                    } else {
                        printf("%d does not exist in the BST! \n", del_value);
                    }

                    //Finish the task
                    break;
                }
            }//end case 2

                //Search for a value
            case 3: {
                //Checking if the BST is empty
                if (isEmpty(root)) {
                    //If true, exit
                    break;
                } else {
                    //Else ask the user for  a value
                    int target = 0;
                    printf("\nTarget value: ");
                    scanf("%d", &target);

                    //Search for it
                    if (search(root, target)) {
                        printf("Found %d ! \n", target);
                    } else {
                        printf("%d does not exist in the BST! \n", target);
                    }
                }

                //Finish
                break;
            }//end case 3

                //Pre-order printing
            case 4: {
                //Checking if the BST is empty
                if (isEmpty(root)) {
                    //If true, exit from the procedure
                    break;
                } else {
                    //Else print it
                    preorder(root);
                    printf("\n");
                    break;
                }
            }//end case 4


                //In-order printing
            case 5: {
                //Checking if the BST is empty
                if (isEmpty(root)) {
                    //If true, exit from the procedure
                    break;
                } else {
                    inorder(root);
                    printf("\n");
                    break;
                }
            }//end case 5


                //Post-order printing
            case 6: {
                //Checking if the BST is empty
                if (isEmpty(root)) {
                    //If true, exit from the procedure
                    break;
                } else {
                    //Else print it
                    postorder(root);
                    printf("\n");
                    break;
                }
            }//end case 6


                //Printing the BST tree-like
            case 7: {
                if (isEmpty(root)) {
                    //If true, exit from the procedure
                    break;
                } else {
                    //Else print it
                    Display(root, 0);
                    break;
                }
            }//end case 7


                //Determine and print the minimum and maximum of the BST
            case 8: {
                //Check if the tree is empty (the call is made upon the root)
                if (!isEmpty(root)) {
                    //If not, retrieve the maximum and minimum
                    g_minimum = getMin(root);
                    g_maximum = getMax(root);
                    //Print them
                    printf("\nMinimum: %d \nMaximum %d\n", g_minimum, g_maximum);

                }

                break;
            }//end case 8


                //Check if the BST's values are bounded
            case 9: {
                //Check if the tree is empty
                if (!isEmpty(root)) {
                    printf("\nBoundedness values:");
                    //Read the desired boundedness values
                    scanf("%d %d", &minimum, &maximum);


                    //Check if all the values are bounded
                    bool status = checkValues(root, minimum, maximum);

                    printf("Result: ");

                    //IF the function returns true, then all the values are bounded, false otherwise
                    if (status) {
                        printf("PASSED!\n");
                    } else {
                        printf("FAILED!\n");
                    }

                } else {
                    printf("\nAborting...Empty tree!\n");
                }

                break;
            }//end case 9

                //Delete the entire BST
            case 10: {
                //Check if the BSt is empty
                if (isEmpty(root)) {
                    //IF true, exit
                    break;
                } else {
                    //Else delete it
                    deleteBST(&root);
                }
            }//end case 10


                //Checking if the BST is empty
            case 11: {
                if (isEmpty(root)) {
                    break;
                } else {
                    printf("The BST is not empty! \n");
                }
            }//end case 11


                //Randomly insert a number of values in the BST
            case 12: {
                //Define an iterator and a number of values and temporary item
                int iterator1 = 0, no_values = 0;
                printf("\nHow many values would you like to insert? Value: ");
                //Read the number of values
                scanf("%d", &no_values);
                //Setting a random seed for the rand function
                srand((unsigned) time(NULL));

                //Insert a number of values
                for (iterator1 = 0; iterator1 < no_values; iterator1++) {

                    //Generating the new value
                    new_value = randomNumberGenerator();

                    //CHecking if the value already exists in the BST
                    if (!search(root, new_value)) {
                        //Insert the new value into the BST
                        root = Add_Node(root, new_value);
                    } else {
                        printf("%d already exists in the tree ! \n", new_value);
                    }
                }

                break;
            }//end case 12


                //Testing file
            case 13: {
                //Open the input file
                printf("\nAttempting to open file...\n");
                FILE *fp = fopen("../input.txt", "r");

                if (!fp) {
                    perror("error");
                    system("pause");
                }

                readFile(fp, root);
                fclose(fp);
                break;


            }//end case 14

            case 14: {
                printf("\nAttempting to build file....\n");
                FILE *f = fopen("../output.txt", "r+");

                srand((unsigned) time(NULL));
                buildFile(f, 1000);
                fclose(f);

                FILE *p = fopen("../output.txt", "r");

                readFile(p, root);

                fclose(p);


                break;
            }

                //Exit
            case 15: {
                printf("\nExiting....");
                exit(0);
            }//end case 16

            default: {
                printf("\n Invalid option....Try again!\n");
            }//end default case

        }//end switch


    } while (choice);

    system("pause");
    return 0;

}//end main
