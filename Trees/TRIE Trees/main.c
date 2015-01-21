#include "trie.h"
#include "error.h"
#include "ctype.h"

int main()
{
	int error;
	Trie *t;
	Leaf l,l1;
	char aux[20];
	char c;
	t = new_trie();
	while (1) {
		printf("MENIU:\n 1. Insert\n 2. Search\n 3. Delete\n 4. Display\n 5. Load data from file\n X. Exit\n");
		scanf("%c", &c);
		switch (tolower(c)) {
		case '1': {
					  scanf("%s", aux);
					  l = (Leaf)malloc(sizeof(char)*(strlen(aux) + 1));
					  strcpy(l, aux);
					  if ((l1=insert(t, l, 0, &error)) != NO_LEAF)
					  {
						  free(l1);
					  }
					  else {
						  error_handling(error);
					  }
					  break;
		}
		case '2': {
					  scanf("%s", aux);
					  l=search(t, aux);
					  if (l!=NO_LEAF) {
						  printf("The word %s exist in Trie!\n",aux);
					  }
					  else {
						  printf("The word %s doesn't exist in Trie!\n",aux);
					  }
					  break;
		}
		case '3': {
					  scanf("%s", aux);
					  delete(t, aux);
					  break;
		}
		case '4': {
					  display(t);
					  break;
		}
		case '5': {
					  file(t, "trie.in", &error);
					  error_handling(error);
					  break;
		}
		case ('x'): {
					  exit(0);
		}
		default: {
					 break;
		}
		}
		fflush(stdin);
	}
	return 0;
}