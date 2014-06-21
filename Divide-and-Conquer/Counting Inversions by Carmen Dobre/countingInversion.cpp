#include"countingInversion.h"
  
//sorteaza vectorul si returneaza numarul de inversiuni
int countInversions(int a[], int n)
{
    int *temp = (int *)malloc(sizeof(int)*n);
    return sortAndMerge(a, temp, 0,n - 1);
}
  
//functie auxiliara care sorteaza vectorul si returneaza numarul de inversiuni
int sortAndMerge(int a[], int temp[], int left, int right)
{
  int middle;
  int countInversion = 0;
 
  if (right > left)
  {
   //se imparte vectorul in 2 si se apeleaza sortAndMerge pentru fiecare parte
    middle = (right + left)/2;
  
   //countInversion este suma dintre inversiunile celor doua parti si a unirii lor
   countInversion  = sortAndMerge(a, temp, left, middle);
   countInversion += sortAndMerge(a, temp, middle+1, right);
  
   countInversion += merge(a, temp, left, middle+1, right);
  }
  return countInversion;
}
  
//uneste cei doi vectori sortati(stanga si dreapta) si determina numarul de inversiuni
int merge(int a[], int temp[], int left, int middle, int right)
{
  int i;
  int j;
  int k;
  int countInversion = 0;
  
  i = left; 
  j = middle;  
  k = left; 
  while ((i <= middle - 1) && (j <= right))
  {
    if (a[i] <= a[j])
    {
      temp[k++] = a[i++];
    }
    else
    {
      temp[k++] = a[j++];
  
    
      countInversion = countInversion + (middle - i);
    }
  }
  
  //se copiaza elementele din stanga in temp
  while (i <= middle - 1)
    temp[k++] = a[i++];
  
//se copiaza elementele din dreapta in temp
  while (j <= right)
    temp[k++] = a[j++];
  
  //se unesc elementele cei doi vectori in a
  for (i=left; i <= right; i++)
    a[i] = temp[i];
  
  return countInversion;
}

void loadData(FILE *f,int a[],int &n)
{

	if(f)
	{
		printf("\ndatele sunt citite din fisier\n");
 
	}
	else
	{ 
		printf("\neroare la deschidere de fisier!\n");
	}

     fscanf(f,"%d",&n);
     for(int i=0;i<n;i++)
	 {
			 fscanf(f,"%d ",&a[i]);
		
	 }
    fclose(f);


	printf("\nvectorul este:\n");
	for(int i=0;i<n;i++)
   {
			printf("%d ", a[i]);
			printf("\n");
   }
}

  

