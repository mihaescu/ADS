#include "Treap.h"

/*
 * Initializing node 
 */
void initialize()
{
    nullnode = new ctreenode;
    nullnode->left = nullnode->right = nullnode;
    root = nullnode;
}
 
/*
 * Left Rotation
 */
void rotLeft(ctree& k1)
{
    ctree k2;
    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1 = k2;
}
 
/*
 * Right Rotation
 */
void rotRight(ctree& k1)
{
    ctree k2;
    k2 = k1->left;
    k1->left = k2->right;
    k2->right = k1;
    k1 = k2;
}
/*
 * Insert Element into Treap
 */
void insert(ctree& t, int x)
{
    if (t == nullnode)
    {
        t = new ctreenode;
        t->left = t->right = nullnode;
        t->key = x;
        t->fix = rand();
    }
    else
    {
        if (t->key == x)
        {
            return;
	}
        else
        {
            if (x < t->key)
            {
                insert(t->left, x);
                if (t->left->fix > t->fix)
                    rotRight(t);
            }
            else
            {
                insert(t->right, x);
                if (t->right->fix > t->fix)
                rotLeft(t);
            }
        }   
    }
}
 
/*
 * Remove Element from Treap
 */
void remove(ctree& t, int x)
{
    if (t == nullnode)
        return;
    if (x > t->key)
        remove(t->right, x);
    else if (x < t->key)
        remove(t->left, x);
    else
    {
        if (t->left == nullnode && t->right == nullnode)
        {
            delete t;
            t = nullnode;
        }
        else if (t->left == nullnode)
        {
            ctree tmp = t;
            t = t->right;
            delete tmp;
        }
        else if (t->right == nullnode)
        {
            ctree tmp = t;
            t = t->left;
            delete tmp;
        }
        else
        {
            if (t->left->fix < t->right->fix)
            {
                rotLeft(t);
                remove(t->left, x);
            }
            else
            {
                rotRight(t);
                remove(t->right, x);
            }
        }
    }
}
/*
 * Search an element in Treap
 */
bool find(ctree t,int x)
{
    if (t == nullnode)
        return false;
    if (t->key == x)
        return true;
    else
    {
        if (x < t->key)
            return find(t->left, x);
        else
            return find(t->right, x);
    }
}
/*
 * Display elements of Treap
 */
void display(ctree ptr, int level)
{
    int i;
    if (ptr == nullnode)
        return;
    if (ptr != NULL)
    {
        display(ptr->right, level + 1);
        printf("\n");
        if (ptr == root)
       	    printf("Root->:  ");
        else
        {
            for (i = 0; i < level; i++)
                printf("         ");
        }
        printf("%d (%d)", ptr->key, ptr->fix);
        display(ptr->left, level + 1);
    }
}
/*
 * Inorder Travesal of Treap
 */
void inorder(ctree ptr)
{
    if (ptr == nullnode)
        return;
    if (ptr != NULL)
    {
        inorder(ptr->left);
        printf("%d  ", ptr->key);
        inorder(ptr->right);
    }
}
