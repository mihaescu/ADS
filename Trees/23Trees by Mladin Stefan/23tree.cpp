#include"23tree.h"

/*
 *___________________________2-3 SEARCH DECLARATIONS___________________________
 */
/*
 * Returns the next search descendant in the search tree. NULL if key is amongst t's keys( uncertain descendant).
 */
tree23* next(tree23 *t, int K)
{
	if (t->K2 == inf)
	{
		if (K == t->K1)
			return NULL;
		else
		{
			if (K < t->K1)
				return t->tl;
			else
				return t->tm;
		}
	}
	else
	{
		if ((K == t->K1) || (K == t->K2))
			return NULL;
		else
		{
			if (K < t->K1)
				return t->tl;
			if (K > t->K1)
			{
				if (K < t->K2)
					return t->tm;
				else
					return  t->tr;
			}
		}

	}
}
/*
 * Implements the search algorithm. Returns address of node where key is found otherwise returns NULL.
 */
tree23* SEARCH(tree23 *t, int K)
{
	if ((K == t->K1) || (K == t->K2))
	{
		return t;
	}
	else
	{
		if ((t->tl == NULL) && (t->tm == NULL) && (t->tr == NULL))
		{
			return NULL;
		}
		else
			return SEARCH(next(t, K), K);
	}
}

/*
 *___________________________2-3 TREE INSERTION DECLARATIONS___________________________
 */
/*
 * Structure for temporary 3 and 4 nodes. Not an actually 234 tree structure as the name would imply.
 */
struct tree234
{
	int K[3];
	tree23* t[4];
};
/*
 * Implements the pushSorted algorithm. Writes the result of pushing tK into t in loc.
 */
void pushSorted(tree23 *t, tree23* tK, tree234* loc)
{
	if (t->K2 == inf)
	{
		if (tK->K1 > t->K1)
		{
			loc->K[0] = t->K1;
			loc->K[1] = tK->K1;
			loc->K[2] = inf;

			loc->t[0] = t->tl;
			loc->t[1] = tK->tl;
			loc->t[2] = tK->tm;
			loc->t[3] = NULL;

			return;
		}
		if (t->K1 < t->K2)
		{
			loc->K[0] = tK->K1;
			loc->K[1] = t->K1;
			loc->K[2] = inf;

			loc->t[0] = tK->tl;
			loc->t[1] = tK->tm;
			loc->t[2] = t->tm;
			loc->t[3] = NULL;

			return;
		}
	}

	if (t->K2 != inf)
	{
		if (tK->K1 < t->K1)
		{
			loc->K[0] = tK->K1;
			loc->K[1] = t->K1;
			loc->K[2] = t->K2;

			loc->t[0] = tK->tl;
			loc->t[1] = tK->tm;
			loc->t[2] = t->tm;
			loc->t[3] = t->tr;

			return;
		}
		if ((tK->K1 > t->K1) && (tK->K1 < t->K2))
		{
			loc->K[0] = t->K1;
			loc->K[1] = tK->K1;
			loc->K[2] = t->K2;

			loc->t[0] = t->tl;
			loc->t[1] = tK->tl;
			loc->t[2] = tK->tm;
			loc->t[3] = t->tr;

			return;
		}
		if (tK->K1 > t->K1)
		{
			loc->K[0] = t->K1;
			loc->K[1] = t->K2;
			loc->K[2] = tK->K1;

			loc->t[0] = t->tl;
			loc->t[1] = t->tm;
			loc->t[2] = tK->tl;
			loc->t[3] = tK->tm;

			return;
		}
	}
}

/*
 * Implements the splitting algorithm. Writes the split excess from splitting t into loc.
 */
void split(tree234 *t, tree23* loc)
{
	loc->K1 = t->K[1];
	loc->K2 = inf;

	loc->tl->K1 = t->K[0];
	loc->tl->K2 = inf;
	loc->tl->tl = t->t[0];
	loc->tl->tm = t->t[1];
	loc->tl->tr = NULL;

	loc->tm->K1 = t->K[2];
	loc->tm->K2 = inf;
	loc->tm->tl = t->t[2];
	loc->tm->tm = t->t[3];
	loc->tm->tr = NULL;

	loc->tr = NULL;
	return;
}


/*
 * PRIVATE: Implementation of the INSERT algorithm( recursive part). 
 * @param t the node to insert K in.
 * @param K the key to be inserted.
 * @excessInsert pointer to memory location where the address of the location where the insertion excess of t and K will be written. It can write NULL on that address of excess node if there is no excess or set the excess node to contain the excess.
 */
tree23* insert_rec(tree23*t, int K, tree23** excessInsert)
{
	tree23* excessInsert_nexttK;

	if (t == NULL)
	{
		/*CASE: Empty Tree*/
		t = (tree23*)malloc(sizeof(tree23));

		t->K1 = K;
		t->K2 = inf;

		t->tl = NULL;
		t->tm = NULL;
		t->tr = NULL;

		return t;
	}


	if ((t->K1 == K) || (t->K2 == K))
	{
		/*CASE: Duplicate Key*/
		if (excessInsert == NULL)
		{
			return t;
		}
		else
		{
			free(*excessInsert);
			*excessInsert = NULL;

			return NULL;
		}
	}

	if ((t->tl == NULL) && (t->tm == NULL) && (t->tr == NULL))
	{
		/*LEAF PHASE*/
		tree234* temp = (tree234*)malloc(sizeof(tree234));
		temp->K[0] = inf;
		temp->K[1] = inf;
		temp->K[2] = inf;
		temp->t[0] = NULL;
		temp->t[1] = NULL;
		temp->t[2] = NULL;
		temp->t[3] = NULL;

		tree23* tK = (tree23*)malloc(sizeof(tree23));
		tK->K1 = K;
		tK->K2 = inf;
		tK->tl = NULL;
		tK->tm = NULL;
		tK->tr = NULL;

		pushSorted(t, tK, temp);

		if (temp->K[2] == inf)
		{
			/*CASE: No excess generating. 2 leaf*/
			t->K1 = temp->K[0];
			t->K2 = temp->K[1];
			t->tl = temp->t[0];
			t->tm = temp->t[1];
			t->tr = temp->t[2];

			if (excessInsert == NULL)
			{
				/*CASE:ROOT - No excess generating. 2 leaf*/
				free(temp);
				free(tK);

				return t;
			}
			else
			{
				/*CASE:Non-ROOT - No excess generating. 2 leaf*/
				free(temp);
				free(tK);

				free(*excessInsert);
				*excessInsert = NULL;

				return NULL;
			}
		}
		else
		{
			/*CASE:Excess generating. 3 leaf*/
			if (excessInsert == NULL)
			{
				/*CASE:ROOT - Excess generating. 3 leaf*/

				tree23* excessInsertROOT = (tree23*)malloc(sizeof(tree23));
				excessInsertROOT->K1 = inf;
				excessInsertROOT->K2 = inf;
				excessInsertROOT->tl = (tree23*)malloc(sizeof(tree23));
				excessInsertROOT->tm = (tree23*)malloc(sizeof(tree23));
				excessInsertROOT->tr = NULL; 
				
				split(temp, excessInsertROOT);

				free(temp);
				free(tK);

				return excessInsertROOT;
			}
			else
			{
				/*CASE:Non-ROOT - Excess generating. 3 leaf*/

				(*excessInsert)->K1 = inf;
				(*excessInsert)->K2 = inf;
				(*excessInsert)->tl = (tree23*)malloc(sizeof(tree23));
				(*excessInsert)->tm = (tree23*)malloc(sizeof(tree23));
				(*excessInsert)->tr = NULL;

				split(temp, *excessInsert);

				free(temp);
				free(tK);

				return NULL;
			}
		}
	}
	else
	{
		/*DOWNWARD PHASE*/
		excessInsert_nexttK = (tree23*)malloc(sizeof(tree23));
		
		tree23* nexttK = next(t, K);

		insert_rec(nexttK, K, &excessInsert_nexttK);


		/*UPWARD PHASE*/
		if (excessInsert_nexttK == NULL)
		{
			/*CASE:Internal Node: No excess receiving.*/
			if (excessInsert == NULL)
			{
				/*CASE:ROOT-Internal Node: No excess receiving.*/
				free(excessInsert_nexttK);

				return t;
			}
			else
			{
				/*CASE:Non-ROOT-Internal Node: No excess receiving.*/
				free(excessInsert_nexttK);
				free(*excessInsert);
				*excessInsert = NULL;
				
				return NULL;
			}
		}
		else
		{
			/*CASE:Internal Node: Excess receiving.*/
			tree234* temp = (tree234*)malloc(sizeof(tree234));
			temp->K[0] = inf;
			temp->K[1] = inf;
			temp->K[2] = inf;
			temp->t[0] = NULL;
			temp->t[1] = NULL;
			temp->t[2] = NULL;
			temp->t[3] = NULL;

			pushSorted(t, excessInsert_nexttK, temp);

			if (temp->K[2] == inf)
			{
				/*CASE:Internal Node: Excess receiving: Excess STOP*/
				t->K1 = temp->K[0];
				t->K2 = temp->K[1];
				t->tl = temp->t[0];
				t->tm = temp->t[1];
				t->tr = temp->t[2];

				if (excessInsert == NULL)
				{
					/*CASE:ROOT-Internal Node: Excess receiving: Excess STOP*/
					free(temp);
					free(excessInsert_nexttK);

					return t;
				}
				else
				{
					/*CASE:Non-ROOT-Internal Node: Excess receiving: Excess STOP*/
					free(temp);
					free(excessInsert_nexttK);
					free(*excessInsert);
					*excessInsert = NULL;

					return NULL;
				}
			}
			else
			{
				/*CASE:Internal Node: Excess receiving: Excess continuation.*/
				if (excessInsert == NULL)
				{
					/*CASE:ROOT-Internal Node: Excess receiving: Excess continuation.*/
					tree23* excessInsertROOT = (tree23*)malloc(sizeof(tree23));
					excessInsertROOT->K1 = inf;
					excessInsertROOT->K2 = inf;
					excessInsertROOT->tl = (tree23*)malloc(sizeof(tree23));
					excessInsertROOT->tm = (tree23*)malloc(sizeof(tree23));
					excessInsertROOT->tr = NULL;

					split(temp, excessInsertROOT);

					free(temp);
					free(excessInsert_nexttK);

					return excessInsertROOT;
				}
				else
				{
					/*CASE:Non-ROOT-Internal Node: Excess receiving: Excess continuation.*/
					(*excessInsert)->K1 = inf;
					(*excessInsert)->K2 = inf;
					(*excessInsert)->tl = (tree23*)malloc(sizeof(tree23));
					(*excessInsert)->tm = (tree23*)malloc(sizeof(tree23));
					(*excessInsert)->tr = NULL;

					split(temp, *excessInsert);

					free(temp);
					free(excessInsert_nexttK);

					return NULL;
				}
			}
		}
			

	}


}
/*
 * Insertion call function: calls the recursive procedure at the root with the key key and with NULL pointer to location for address of location of insert excess editing..
 */
tree23* INSERT(tree23 *ROOT, int key)
{
	return insert_rec(ROOT, key, NULL);
}



/*
*___________________________2-3 TREE DELETION DECLARATIONS___________________________
*/
int shift_keys[8];
tree23* shift_desc[9];
tree23* search;

void init_shift()
{
	for (int i = 0; i < 8; i++)
	{
		shift_keys[i] = inf;
		shift_desc[i] = NULL;
	}

	shift_desc[8] = NULL;

	return;
}
void set_shift(tree23* t)
{
	if (t->tl != NULL)
	{
		shift_keys[0] = t->tl->K1;
		shift_keys[1] = t->tl->K2;
	}
	shift_keys[2] = t->K1;
	if (t->tm != NULL)
	{
		shift_keys[3] = t->tm->K1;
		shift_keys[4] = t->tm->K1;
	}
	shift_keys[5] = t->K2;

	if (t->tr != NULL)
	{
		shift_keys[6] = t->tr->K1;
		shift_keys[7] = t->tr->K2;
	}


	if (t->tl != NULL)
	{
		shift_desc[0] = t->tl->tl;
		shift_desc[1] = t->tl->tm;
		shift_desc[2] = t->tl->tr;
	}
	if (t->tm != NULL)
	{
		shift_desc[3] = t->tm->tl;
		shift_desc[4] = t->tm->tm;
		shift_desc[5] = t->tm->tr;
	}
	if (t->tr != NULL)
	{
		shift_desc[6] = t->tr->tl;
		shift_desc[7] = t->tr->tm;
		shift_desc[8] = t->tr->tr;
	}

	return;
}
void get_shift(tree23* t)
{
	int d = 0;

	while (shift_keys[d] != inf)
	{
		d++;
	}

	if (d == 2)
	{
		t->tl->K1 = shift_keys[0];
		t->tl->K2 = shift_keys[1];
		t->tl->tl = shift_desc[0];
		t->tl->tm = shift_desc[1];
		t->tl->tr = shift_desc[2];

		t->tm->K1 = inf;
		t->tm->K2 = inf;
		t->tm->tl = NULL;
		t->tm->tm = NULL;
		t->tm->tr = NULL;

		t->tr->K1 = inf;
		t->tr->K2 = inf;
		t->tr->tl = NULL;
		t->tr->tm = NULL;
		t->tr->tr = NULL;

		t->K1 = inf;
		t->K2 = inf;
		if (t->tm != NULL)
			free(t->tm);
		t->tm = NULL;
		t->tr = NULL;

		return;
	}

	if (d == 3)
	{
		t->tl->K1 = shift_keys[0];
		t->tl->K2 = inf;
		t->tl->tl = shift_desc[0];
		t->tl->tm = shift_desc[1];
		t->tl->tr = NULL;

		t->tm->K1 = shift_keys[2];
		t->tm->K2 = inf;
		t->tm->tl = shift_desc[2];
		t->tm->tm = shift_desc[3];
		t->tm->tr = NULL;

		t->tr->K1 = inf;
		t->tr->K2 = inf;
		t->tr->tl = NULL;
		t->tr->tm = NULL;
		t->tr->tr = NULL;

		t->K1 = shift_keys[1];
		t->K2 = inf;
		t->tr = NULL;

		return;
	}

	if (d == 6)
	{
		t->tl->K1 = shift_keys[0];
		t->tl->K2 = shift_keys[1];
		t->tl->tl = shift_desc[0];
		t->tl->tm = shift_desc[1];
		t->tl->tr = shift_desc[2];

		t->tm->K1 = shift_keys[3];
		t->tm->K2 = inf;
		t->tm->tl = shift_desc[3];
		t->tm->tm = shift_desc[4];
		t->tm->tr = NULL;

		t->tr->K1 = shift_keys[5];
		t->tr->K2 = inf;
		t->tr->tl = shift_desc[5];
		t->tr->tm = shift_desc[6];
		t->tr->tr = NULL;

		t->K1 = shift_keys[2];
		t->K2 = shift_keys[4];

		return;
	}



	t->tl->K1 = shift_keys[0];
	t->tl->K2 = shift_keys[1];
	t->tl->tl = shift_desc[0];
	t->tl->tm = shift_desc[1];
	t->tl->tr = shift_desc[2];

	t->tm->K1 = shift_keys[3];
	t->tm->K2 = shift_keys[4];
	t->tm->tl = shift_desc[3];
	t->tm->tm = shift_desc[4];
	t->tm->tr = shift_desc[5];

	t->tr->K1 = shift_keys[6];
	t->tr->K2 = shift_keys[7];
	t->tr->tl = shift_desc[6];
	t->tr->tm = shift_desc[7];
	t->tr->tr = shift_desc[8];

	t->K1 = shift_keys[2];
	t->K2 = shift_keys[5];
	if (d >= 7)
	{
		t->tr = NULL;
	}

	return;
}
void shift()
{
	int i = 0;

	while (i < 8)
	{
		if (shift_keys[i] == inf)
		{
			int j = i;

			while (shift_keys[j] == inf)
			{
				if (j < 8)
					j++;
				else
					break;
			}
			shift_keys[i] = shift_keys[j];
			shift_keys[j] = inf;

			i++;
		}

	}

	i = 0;
	while (i < 9)
	{
		if (shift_desc[i] == NULL){
			int j = i;

			while (shift_desc[j] == NULL)
			{
				if (j < 9)
					j++;
				else
					break;
			}
			shift_desc[i] = shift_desc[j];
			shift_desc[j] = NULL;

			i++;
		}

	}
}

tree23* delete_rec(tree23 *t, int K, tree23 *P)
{
	if (t == NULL)
	{
		return NULL;
	}

	if ((t->tl == NULL) && (t->tm == NULL) && (t->tr == NULL))
	{
		if (t->K1 == K)
		{
			if (search == NULL)
				t->K1 = inf;
			else
			{
				if (search->K1 == K)
					search->K1 = t->K1;
				else
					search->K2 = t->K1;
			}

			t->K1 = inf;
		}
		else
		{
			if (search == NULL)
				t->K2 = inf;
			else
			{
				if (search->K1 == K)
					search->K1 = t->K2;
				else
					search->K2 = t->K2;
			}
			t->K2 = inf;
		}

		init_shift();
		set_shift(P);
		shift();
		get_shift(P);
	}
	else
	{
		if ((t->K1 == K) || (t->K2 == K))
		{
			search = t;
			delete_rec(t->tm, K, t);
		}
		else
		{
			delete_rec(next(t, K), K, t);
		}

		if (t->K1 == inf)
		{
			if (P == NULL)
			{
				return t->tl;
			}
			init_shift();
			set_shift(P);
			shift();
			get_shift(P);

		}
		else
		{
			return t;
		}
	}
}
tree23* DEL(tree23 *ROOT, int key)
{
	if (search != NULL)
	{
		free(search);
		search = NULL;
	}

	tree23* R = delete_rec(ROOT, key, NULL);

	if (R->K1 == inf)
		return R->tl;
	else
		return R;
}




/*
 *___________________________2-3 TREE INPUT AND OUTPUT DECLARATIONS___________________________
 */
/*
 * PRIVATE: 2-3 Tree console printing: recursive part.
 */
void printTree_rec(tree23* node, int level)
{
	if (node == NULL)
		return;

	printf("\n%d: ", level);
	printf("%d ", node->K1);
	if (node->K2 == inf)
		printf("inf ");
	else
		printf("%d ", node->K2);
	printf("\nDesc: %d %d %d", node->tl, node->tm, node->tr);

	printf("\n\n");

	printTree_rec(node->tl, level + 1);
	printTree_rec(node->tm, level + 1);
	printTree_rec(node->tr, level + 1);

}
/*
 * 2-3 Tree console printing: function which is called.
 */
void PRINTTREE(tree23 *ROOT)
{
	if (ROOT == NULL)
		return;

	int level = 1;
	printf("\n%d: ROOT: ", level);
	printf("%d ", ROOT->K1);
	if (ROOT->K2 == inf)
		printf("inf ");
	else
		printf("%d ", ROOT->K2);

	printf("\nDesc: %d %d %d", ROOT->tl, ROOT->tm, ROOT->tr);
	printf("\n\n");

	printTree_rec(ROOT->tl, level + 1);
	printTree_rec(ROOT->tm, level + 1);
	printTree_rec(ROOT->tr, level + 1);

	return;
}

/*
* 2-3 Tree load from file: function which is called.
*/
void LOADTREE(tree23* ROOT, FILE* input)
{
	int buff;

	while (!feof(input))
	{
		fscanf(input, "%d", &buff);
		INSERT(ROOT, buff);
	}
	
	return;
}
