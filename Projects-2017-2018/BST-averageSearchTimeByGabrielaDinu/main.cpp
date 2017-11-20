#include"prototypes.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()

{   int iterator1;
    time_t t;
    srand((unsigned) time(&t));
    Node *root=NULL;
    int operation,random_node,number_of_nodes,depth,average_height, min, max;
    printf("min = ");
    scanf("%d",&min);
    printf("max = ");
    scanf("%d",&max);
    for(iterator1=1;iterator1<=10000;iterator1++){
        random_node = min + rand() % (max - min+1);
        root= Add_Node(root,random_node);
        if(iterator1>=100){
            depth = maxDepth(root);
            number_of_nodes=count_nodes(root);
            average_height = number_of_nodes/depth+1;
            printf("The average heith is %d\n for %d nodes ", average_height,number_of_nodes);
        }
    }

    do{
        printf("\n1.Adauga un nod");
        printf("\n2.Inaltimea");
        printf("\n3.Inaltimea medie");
        printf("\n4.Numarul de noduri");
        printf("  Any other key");
        printf("\n\nOptiunea dumneavoastra: ");
        scanf("%d",&operation);
        switch(operation){
                    case 1:
                        random_node = min + rand() % (max - min+1);
                        root= Add_Node(root,random_node);
                        break;
                    case 2:
                        depth = maxDepth(root);
                        printf("The heith is %d\n", depth);
                        break;
                    case 3:
                        depth = maxDepth(root);
                        number_of_nodes=count_nodes(root);
                        average_height = number_of_nodes/depth+1;
                        printf("The average heith is %d\n", average_height);
                        break;
                    case 4:
                        number_of_nodes=count_nodes(root);
                        printf("Numarul de noduri este %d\n", number_of_nodes);
                        break;
                    default:
                        return 0;
                }




        }while(operation);
}
