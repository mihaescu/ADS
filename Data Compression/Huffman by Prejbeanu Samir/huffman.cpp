#include "huffman.h"

struct nod noduri[256];
int numarNoduri=0;
int queueEnd=1;
char *huffCode[128];
node queue[256];
char buff[1024];

/*Functia creeaza nodurile. Daca un caracter este prezent in fisier,se creeaza un nod in care se insereaza caracterul si frecventa aferenta acestuia.
Pentru doua noduri deja existnte se creeaza un nod parinte in care se insumeaza frecventele celor doua noduri copil.*/
node nodNou(int frecventa, char litera, node leftNode, node rightNode)
{
    node n=noduri + numarNoduri++;
	if (frecventa)
    {
        n->litera=litera;
        n->frecventa=frecventa;
    }
	else
	{
		n->left=leftNode, n->right=rightNode;
		n->frecventa=leftNode->frecventa + rightNode->frecventa;
	}
	return n;
}

/*Se insereaza nodurile intr-o "coada".Pentru fiecare nod existent se incrementeaza la inceputul functie dimensiunea acestei cozi pentru a-l insera.
La final se afiseaza informatiile existente in nodurile ce prezinta caractere din coada. Se va afisa caracterul prezent(caracter gasit in text) respectiv frecventa acestuia.*/
void queueInsert(node n)
{
	int i=queueEnd++;
	int j;
	while ((j=i/2))
	{
		if (queue[j]->frecventa <= n->frecventa)
            break;
		queue[i]=queue[j];
		i=j;
	}
	queue[i]=n;
	if(n->litera!=NULL)
        printf("\" %c \" occured %d time(s).\n",n->litera,n->frecventa);
}

//Pentru a elibera "coada".
node queueRemove()
{
	int i=1;
    int j;
	node n=queue[i];
	if (queueEnd<2)
        return 0;
	queueEnd--;
	while ((j=i*2) < queueEnd)
    {
		if (j+1 < queueEnd && queue[j+1]->frecventa < queue[j]->frecventa)
            j++;
		queue[i]=queue[j];
		i=j;
	}
	queue[i]=queue[queueEnd];
	return n;
}

//Functia construieste codul aferent fiecarui caracter din noduri in functie de pozitia in arbore. Drumurile catre stanga vor fi in totalitate notate cu 0 iar cele catre dreapta cu 1.
void codeBuild(node n, char *codBiti, int lungimeCod)
{
	static char *out = buff;
	if (n->litera)
	{
		codBiti[lungimeCod]=0;
		strcpy(out,codBiti);
		huffCode[n->litera]=out;
		out += lungimeCod + 1;
		return;
	}
	codBiti[lungimeCod] = '0';
	codeBuild(n->left,codBiti,lungimeCod+1);
	codBiti[lungimeCod] = '1';
	codeBuild(n->right,codBiti,lungimeCod + 1);
}

/*Se va initializa procesul de codare. Se parcurge textul primit ca parametru,se incrementeaza frecventa aferenta fiecarui caracter de cate ori acesta este intanlit.
Se va verifica daca posibilele caractere( 0->127 (ASCII)) ce pot exista in text prezinta frecventa.Daca frecventa > 1,se creeaza un nod nou.
Acesta este transmis ca parametru functie de inserare in coada.*/
void buildHuffman(const char *input)
{
	int frecvente[128]={0};
	char codHuffman[16];

	while (*input)
        frecvente[(int)*input++]++;

    for (int i=0;i<128;i++)
        if (frecvente[i])
            queueInsert(nodNou(frecvente[i],i,0,0));

	while (queueEnd>2)
		queueInsert(nodNou(0,0,queueRemove(),queueRemove()));

	codeBuild(queue[1],codHuffman, 0);
}

//Se parcurge textul primit ca parametru.De cate ori se intanleste un caracter(acestea vor fi fost deja codate in procesul de codare) se transmite codul acestuia in vectorul de iesire.
void codare(const char *input, char *output)
{
	while (*input)
    {
		strcpy(output,huffCode[*input]);
		output+=strlen(huffCode[*input++]);
	}
}

//Se parcurge textul deja codat.In functie de codurile din acesta se parcurge arborele pentru a gasi caracterele reprezentate de aceste coduri,iar caracterele gasite la nodurile aflate pe pozitiile inidcate de catre coduri vor fi afisate.
void decodare(const char *codHuffman, node huffNode)
{
	node n=huffNode;
	while (*codHuffman)
    {
		if (*codHuffman++=='0')
            n=n->left;
		else
            n=n->right;
		if (n->litera)
		{
            printf("%c",n->litera);
            n=huffNode;
		}
	}
	if (huffNode!=n)
        printf("Err!\n");
}
