#include "btree.h"
NodeB *Insert(NodeB *root, int x)
{
    int ind, urc, h;
    NodeB *pv, *adr = NULL, *purc = NULL;

    SplitPage(root, x, &ind, &urc, &h, &adr, &purc);

    if (h)
    {
        pv = (NodeB *) malloc(sizeof(NodeB));
        pv->pNodes[0] = root;
        pv->pNodes[1] = purc;
        pv->keys[1] = urc;
        pv->nr = 1;
        root = pv;
    }
    if (x == urc)
    {
        adr = root;
        ind = 1;
    }
    return root;
}
void SplitPage(NodeB *r, int x, int *ind, int *urc, int *h, NodeB **adr, NodeB **purc)
{
    int k, gasit;
    if (r == NULL)
    {
        *h = 1;
        *urc = x;
        *purc = NULL;
    }
    else
    {
        k = 1;
        gasit = 0;
        while (k <= r->nr && !gasit)
        {
            if (r->keys[k] >= x)
                gasit = 1;
            k++;
        }
        if (gasit)
            k--;
        if (k > r->nr)
            gasit = 0;
        else
        {
            if (r->keys[k] == x)
                gasit = 1;
            else
                gasit = 0;
        }
        if (gasit)
        {
            *adr = r;
            *ind = k;
            *h = 0;
            printf("Key is already in tree \n");
        }
        else
        {
            SplitPage(r->pNodes[k-1], x, ind, urc, h, adr, purc);
            if (*h)
                PlaceInPage(r, k, x, ind, urc, h, adr, purc);
        }
    }
}
void PlaceInPage(NodeB *r, int k, int x, int *ind, int *urc, int *h, NodeB **adr, NodeB **purc)
{
    NodeB *pv;
    int m_div_2, v;
    m_div_2 = r->nr/2;
    if (r->nr == m)
    {
        pv = (NodeB *) malloc(sizeof(NodeB));
        pv->nr = m_div_2;
        r->nr = m_div_2;
        if (k > m_div_2)
        {
            if (k == m_div_2+1)
            {
                CopyPage(pv, r, m_div_2 + 1, 1, m_div_2);
                pv->pNodes[0] = *purc;
            }
            else
            {
                k = k - m_div_2 - 1;
                CopyPage(pv, r, m_div_2 + 2, 1, k-1);
                pv->keys[k] = *urc;
                pv->pNodes[k] = *purc;
                CopyPage(pv, r, m_div_2 + k + 1, k+1, m_div_2 - k);
                pv->pNodes[0] = r->pNodes[m_div_2 + 1];
                *urc = r->keys[m_div_2 + 1];
            }
        }
        else
        {
            CopyPage(pv, r, m_div_2 + 1, 1 , m_div_2);
            pv->pNodes[0] = r->pNodes[m_div_2];
            v = r->keys[m_div_2];
            CopyPage(r, r, k, k+1, m_div_2 - k);
            r->pNodes[k] = *purc;
            r->keys[k] = *urc;
            *urc = v;
        }
        *purc = pv;
    }
    else
        InsertInNonFullLeaf(r, k, x, ind, urc, h, adr, purc);
}
void InsertInNonFullLeaf(NodeB *r, int k, int x, int *ind, int *urc, int *h, NodeB **adr, NodeB **purc)
{
    *h = 0;
    r->nr = r->nr + 1;
    CopyPage(r, r, k, k+1, r->nr-k);
    r->pNodes[k] = *purc;
    r->keys[k] = *urc;
    if (*urc == x)
    {
        *ind = k;
        *adr = r;
    }
}
void CopyPage(NodeB *destination, NodeB *source, int sourceIndex, int destIndex, int n)
{
    while (n > 0)
    {
        n--;
        destination->keys[destIndex + n] = source->keys[sourceIndex + n];
        destination->pNodes[destIndex + n] = source->pNodes[sourceIndex + n];
    }
}
void Search(NodeB *r, int x)
{
    int k, gasit;
    if (r == NULL)
        printf("The key is not in the tree");
    else
    {
        k = 1;
        gasit = 0;
        while ((k <= r->nr) && (!gasit))
        {
            gasit = (r->keys[k] == x);
            k++;
        }
        if (gasit)
        {
            k--;
            printf("The key is in the tree \n");
        }
        else
        {
            if (k > r->nr)
            {
                gasit = 0;
            }
            else
            {
                gasit = (r->keys[k] == x);
            }
            if (gasit)
            {
                printf("The key is in the tree \n");
            }
            else
            {
                Search(r->pNodes[k-1], x);
            }
        }
    }
}
void DisplayTree(NodeB *node, int nivel)
{
    int j;
    if (node != NULL)
    {
        for(j=1; j<=nivel; j++)
            printf(" ");
        for(j=1; j<=node->nr; j++)
            printf("%d ", node->keys[j]);
        printf("\n");
        for(j=0; j<=node->nr; j++)
            DisplayTree(node->pNodes[j], nivel + 1);
    }
}
int FindMinimum(NodeB *page)
{
    if (page->pNodes[0] == NULL)
        return page->keys[1];
    else
        return FindMinimum(page->pNodes[0]);
}
void DeleteKey(NodeB **nod, int key)
{
    NodeB *temp;
    int i = 1, j;
    int nr = (*nod)->nr;
    NodeB *copil = NULL;
    NodeB *creditor;
    if((*nod)->keys[nr] < key)
    {
        copil = (*nod)->pNodes[nr];
        i = nr;
        if (copil == NULL)
            return;
    }
    else
    {
        while (key > (*nod)->keys[i])
            i++;
        if (key == (*nod)->keys[i])
        {
            if ((*nod)->pNodes[i] == NULL)
            {
                for(; i<nr; i++)
                {
                    (*nod)->keys[i] = (*nod)->keys[i+1];
                }
                (*nod)->nr --;
                return;
            }
            key = FindMinimum((*nod)->pNodes[i]);
            (*nod)->keys[i] = key;
            copil = (*nod)->pNodes[i];
        }
        else
        {
            i--;
            copil = (*nod)->pNodes[i];
        }
    }
    DeleteKey(&copil, key);
    if (copil->nr < (m/2))
    {
        if (i>0)
        {
            creditor = (*nod)->pNodes[i-1];
            if (creditor->nr > (m/2))
            {
                for(j=copil->nr; j>0; j--)
                {
                    copil->keys[j+1] = copil->keys[j];
                    copil->pNodes[j+1]= copil->pNodes[j];
                }
                copil->pNodes[1] = copil->pNodes[0];
                copil->nr++;
                copil->keys[1] = (*nod)->keys[i];
                (*nod)->keys[i] = creditor->keys[creditor->nr];
                copil->pNodes[0] = creditor->pNodes[creditor->nr];
                creditor->nr--;
            }
            else
            {
                j = creditor->nr + 1;
                creditor->keys[j] = (*nod)->keys[i];
                creditor->pNodes[j] = copil->pNodes[0];
                for(; i<nr; i++)
                {
                    (*nod)->keys[i] = (*nod)->keys[i+1];
                    (*nod)->pNodes[i] = (*nod)->pNodes[i+1];
                }
                (*nod)->nr--;
                creditor->nr += 1 + copil->nr;
                while(copil->nr > 0)
                {
                    creditor->keys[j + copil->nr] = copil->keys[copil->nr];
                    creditor->pNodes[j + copil->nr] = copil->pNodes[copil->nr];
                    copil->nr--;
                }
                free (copil);
            }
        }
        else
        {
            creditor = (*nod)->pNodes[1];
            if(creditor->nr > (m/2))
            {
                copil->nr++;
                copil->pNodes[copil->nr] = creditor->pNodes[0];
                copil->keys[copil->nr] = (*nod)->keys[1];
                (*nod)->keys[1] = creditor->keys[1];
                creditor->pNodes[0] = creditor->pNodes[1];
                for(j=1; j<creditor->nr; j++)
                {
                    creditor->keys[j] = creditor->keys[j+1];
                    creditor->pNodes[j] = creditor->pNodes[j];
                }
                creditor->nr--;
            }
            else
            {
                j = copil->nr + 1;
                i = 1;
                copil->keys[j] = (*nod)->keys[i];
                copil->pNodes[j] = creditor->pNodes[0];
                for(; i<nr; i++)
                {
                    (*nod)->keys[i] = (*nod)->keys[i+1];
                    (*nod)->pNodes[i] = (*nod)->pNodes[i+1];
                }
                (*nod)->nr--;
                copil->nr += 1+ creditor->nr;
                while(creditor->nr > 0)
                {
                    copil->keys[j + creditor->nr] = creditor->keys[creditor->nr];
                    copil->pNodes[j + creditor->nr] = creditor->pNodes[creditor->nr];
                    creditor->nr--;
                }
                free (creditor);
            }
        }
    }
    if ((*nod)->nr == 0)
    {
        temp = *nod;
        *nod = (*nod)->pNodes[0];
        free (temp);
    }
}
