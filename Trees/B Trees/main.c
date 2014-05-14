#include "btree.h"

int main()
{
    int opt, key, n, i;

    NodeB *root = NULL;

    while (1)
    {
        printf("\n 1. Create");
        printf("\n 2. Insert");
        printf("\n 3. Delete");
        printf("\n 4. Search");
        printf("\n 5. Display");
        printf("\n 6. Exit");
        printf("\n Your option: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            printf("Enter the number of keys: ");
            scanf("%d", &n);
            for (i=0; i<n; i++)
            {
                printf("Key: ");
                scanf("%d", &key);
                root = Insert(root, key);
            }
            break;
        case 2:
            printf("Key: ");
            scanf("%d", &key);
            root = Insert (root, key);
            break;
        case 3:
            printf("\n Enter key: ");
            scanf("%d", &key);
            DeleteKey(&root, key);
            break;
        case 4:
            printf("\n Enter key to search for: ");
            scanf("%d", &key);
            Search(root, key);
            break;
        case 5:
            printf("\n\n");
            DisplayTree(root, 4);
            break;
        case 6:
            return 0;
        }
    }
}

