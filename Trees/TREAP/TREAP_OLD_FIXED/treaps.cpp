#include "treaps.h"

typedef struct NodeTreap NodeTreap, *pNnodeTreap;

void rotate(NodeTreap *parent, NodeTreap *child)
{
	if (parent->left == child)//rot dreapta
	{
		child->parent = parent->parent;

		if (child->parent)
		{
			if (child->parent->left == parent)			
				child->parent->left = child;			
			else 			
				child->parent->right = child;			
		}

		parent->parent = child;
		parent->left = child->right;

		if (parent->left)		
			parent->left->parent = parent;		

		child->right = parent;
		
	}	
	else//rot stanga
	{
		child->parent = parent->parent;

		if (child->parent)		
			if (child->parent->left == parent)			
				child->parent->left = child;			
			else 			
				child->parent->right = child;	

		parent->parent = child;
		parent->right = child->left;

		if (parent->right)		
			parent->right->parent = parent;		

		child->left = parent;		
	}	

	return;
}

NodeTreap* insert(NodeTreap *current, int element, float priority)
{
    NodeTreap *Curent, *parent;
	int direction;

	if (current == NULL)
	{
		current = (NodeTreap*)malloc(sizeof(NodeTreap));
		current->left = current->right = current->parent = NULL;
		current->element = element;
		current->priority = priority;	

		return current;
	}

	Curent = current;
	parent = NULL;

	while (Curent != NULL)
	{
		if (element == Curent->element)		
			return current;		

		parent = Curent;

		if (element < Curent->element)
		{
			direction = LEFT;
			Curent = Curent->left;
		}
		else
		{
			direction = RIGHT;
			Curent = Curent->right;
		}
	}

	Curent = (NodeTreap*)malloc(sizeof(NodeTreap));
	Curent->element = element;
	Curent->left = Curent->right = NULL;
	Curent->parent = parent;
	
	if (direction == LEFT)	
		parent->left = Curent;	
	else	
		parent->right = Curent;
	

	Curent->priority = priority;

	while (1)
	{
		parent = Curent->parent;

		if (parent->priority < Curent->priority)		
			break;		
		
		rotate(parent,Curent);

		if (Curent->parent == NULL)
		{
			current = Curent;
			break;
		}
	}

	return current;
}

int member(NodeTreap *current, int el)
{
	pNnodeTreap p;

	p = current;

	while (p)
	{
		if (el == p->element)		
			return 1;	

		p = el < p->element ? p->left:p->right;
	}

	return 0;
}

NodeTreap* deleteTreap(NodeTreap *current, int el)
{
	pNnodeTreap p, x, y;

	p = current;

	while (p)
	{
		if (el == p->element)		
			break;		

		p = el < p->element ? p->left:p->right;
	}
	if (p)
	{
		x = p->left;
		y = p->right;

		while ((x != NULL) && (y != NULL))
		{
			if (x->priority > y->priority)			
				rotate(p,x);			
			else			
				rotate(p,y);			

			x = p->left;
			y = p->right;
		}

		

		if ((x == NULL) && (y != NULL))
		{
			y->parent = p->parent;

			if (p->parent)
			{
				if (p->parent->left == p)				
					p->parent->left = y;				
				else				
					p->parent->right = y;					
				
			}
			else			
				current = y;
			
		}
		else if ((y == NULL) && (x != NULL))
		{
			x->parent = p->parent;

			if (p->parent)
			{
				if (p->parent->left == p)				
					p->parent->left = x;				
				else				
					p->parent->right = x;	

				p = x;
				
			}
			else			
				current = x;			
		}
		else 
		{
			if (p->parent)
			{
				if (p->parent->left == p)
					p->parent->left = NULL;
				else
					p->parent->right = NULL;
			}
			else			
				current = NULL;
			
		}
	}
	return current;
}

void displayTreap(NodeTreap *parent, int k)
{
	int i;

	if (parent != NULL)
	{
		displayTreap(parent->right,k+5);

		for (i = 0; i < k; i++)		
			printf(" ");		

		printf("%d:%1.2f\n",parent->element,parent->priority);

		displayTreap(parent->left,k+5);
	}
}


void splitTreap(NodeTreap *current,int el)
{
	pNnodeTreap tLess,tLarge;
	insert(current,el,MINUS_INFINIT);
	tLess = current->left;
	tLarge = current->right;
}

void mergeTreaps(NodeTreap* current, NodeTreap* tLess, NodeTreap* tLarge)
{

	if(tLess->priority < tLarge->priority)
	{
		current = tLess;
		current->right = tLarge;	
		current->right->parent = current;
	}
	else
	{
		current = tLarge;
		current->left = tLess;
		current->left->parent = current;
	}

	current->parent = NULL;
}
