#include "trie.h"
#include "error.h"
#include "ctype.h"

int main()
{
	int error;
	Trie *t;
	Leaf l;
	char aux[20];
	char c;
	t = new_trie();
	while (1) {
		printf("MENIU:\n 1. Insert\n 2. Search\n 3. Delete\n 4. Display\n 5. Load data from file\n X. Exit\n");
		scanf("%c", &c);
		switch (tolower(c)) {
		case '1': {
					  l = (Leaf)malloc(sizeof(Leaf));
					  scanf("%s", l);
					  insert(t, l, 0,&error);
					  error_handling(error);
					  break;
		}
		case '2': {
					  scanf("%s", aux);
					  l=search(t, aux);
					  if (l!=NO_LEAF) {
						  printf("Exista!\n");
					  }
					  else {
						  printf("Nu exista!\n");
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

	system("pause");
	return 0;
}