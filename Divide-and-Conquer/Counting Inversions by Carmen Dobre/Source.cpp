#include"header.h"
  
//sorteaza vectorul si returneaza numarul de inversiuni
int MergeSort(int a[], int n)
{
    int *temp = (int *)malloc(sizeof(int)*n);
    return MergeAuxSort(a, temp, 0,n - 1);
}
  
//functie auxiliara care sorteaza vectorul si returneaza numarul de inversiuni
int MergeAuxSort(int a[], int temp[], int left, int right)
{
  int middle;
  int count_inversion = 0;
 
  if (right > left)
  {
   //se imparte vectorul in 2 si se apeleaza MergeAuxSort pentru fiecare parte
    middle = (right + left)/2;
  
   //count_inversion este suma dintre inversiunile celor doua part si a unirii lor
   count_inversion  = MergeAuxSort(a, temp, left, middle);
   count_inversion += MergeAuxSort(a, temp, middle+1, right);
  
   count_inversion += Merge(a, temp, left, middle+1, right);
  }
  return count_inversion;
}
  
//uneste cei doi vectori sortati(stanga si dreapta) si determina numarul de inversiuni
int Merge(int a[], int temp[], int left, int middle, int right)
{
  int i;
  int j;
  int k;
  int count_inversion = 0;
  
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
  
    
      count_inversion = count_inversion + (middle - i);
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
  
  return count_inversion;
}

void LoadArray(int A[50],int &n)
{

  FILE *f=fopen("vector.txt","r");

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
			 fscanf(f,"%d ",&A[i]);
		
	 }
    fclose(f);


	printf("\nvectorul este:\n");
	for(int i=0;i<n;i++)
   {
			printf("%d  ", A[i]);
			printf("\n");
   }
}

  

