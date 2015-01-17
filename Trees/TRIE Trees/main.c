#include "trie.h"
#include "error.h"

int main()
{
	int error;
	Trie *t;
	Leaf l;
	char aux[20];
	char c;
	t = new_trie();
	while (1) {
		printf("MENIU:\n 1. Inserare\n 2. Cautare\n 3. Stergere\n 4. Afisare\n 5. Incarcare din fisier\n X. Iesire\n");
		scanf("%c", &c);
		switch (c) {
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
		case 'x': {
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