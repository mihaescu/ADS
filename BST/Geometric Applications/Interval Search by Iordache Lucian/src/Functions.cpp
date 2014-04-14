#include"Header.h"

/*This function insert a newNode into the binary search tree.
 @param:
 BSTNode *position-indicates the position where node is inserted
 Node *newNode-represents the new node that is inserted
 Functions return a pointer to tree's root
 */
struct BSTNode *insert(struct BSTNode *position,Interval *newNode)
{
	BSTNode *node,*temp,*parent;

	node=(struct BSTNode*)malloc(sizeof(BSTNode));
	node->nodeInfo.lo=newNode->lo;
	node->nodeInfo.hi=newNode->hi;
	node->left=NULL;
	node->right=NULL;
	node->maxRight=newNode->hi;
	if(position==NULL){
		position=node;
		position->maxRight=position->nodeInfo.hi;

	}
	else{
		temp=position;
		while(temp != NULL){
			if(newNode->lo < temp->nodeInfo.lo){
				parent=temp;
				temp=temp->left;
				if(parent->maxRight < node->maxRight)
					parent->maxRight=node->maxRight; 
			}
			else{
				parent=temp;
				temp=temp->right;
				if(parent->maxRight < node->maxRight)
					parent->maxRight=node->maxRight;
			}
		}
		if(newNode->lo < parent->nodeInfo.lo)
			parent->left=node;
		else
			parent->right=node;
	}

	return position;
}

/*Function search if a point belongs to a node from tree.
@param:
BSTNode *node-node in which point is beeing searched
int point-point that is beeig searched
FILE *fo-the file in which information from node is beeing displayed
*/

void searchPoint(struct BSTNode *node,int point,FILE *fo)
{
	if(node){
		if ( node -> nodeInfo.lo <= point && node->nodeInfo.hi >= point)
			fprintf(fo,"[%d %d] ",node->nodeInfo.lo,node->nodeInfo.hi);
		if(node->maxRight >= point){
				searchPoint(node->left,point,fo);
				searchPoint(node->right,point,fo);
			}
	}
}

/*Function checks if an intervarl belong to a node from tree.
@param:
BSTNode *node-node in which interval is beeing searched
Interval *interval the interval that is beeing searched
Returns 1 if interval intersect node,otherwise return 0.
*/
int checkIntersection(struct BSTNode *node,struct Interval *interval)
{
	int ok=0;
	if((interval->lo>=node->nodeInfo.lo && interval->lo<=node->nodeInfo.hi) || (interval->hi>=node->nodeInfo.lo && interval->hi <= node->nodeInfo.hi))
		ok=1;
	else
		if((node->nodeInfo.hi <= interval->hi && node->nodeInfo.hi >= interval->lo) || (node->nodeInfo.lo <= interval->hi && node->nodeInfo.lo >= interval->lo))
			ok=1;
		else
			if(node->nodeInfo.lo >= interval->lo && node->nodeInfo.hi <= interval->hi)
				ok=1;
	return ok;
}
/*Function displays into FILE *fo node's information that intersect with given interval*/
void segmentIntersect(struct BSTNode *node,struct Interval *interval,FILE *fo)
{

	if(node){
		if(checkIntersection(node,interval)){
			fprintf(fo,"[%d,%d] ",node->nodeInfo.lo,node->nodeInfo.hi);
		}
		if((node->maxRight >= interval->lo))
			segmentIntersect(node->left,interval,fo);
		if((node->maxRight >= interval->lo) && (node->nodeInfo.lo <= interval->hi)){
			segmentIntersect(node->right,interval,fo);
		}
	}
}



/*Function display Binary search tree*/
void displayTree(BSTNode *node, int level,FILE *fo)
{
	int i;
	if(node != 0){
		displayTree(node->right, level+8,fo);
		for(i = 0; i <= level; i++)
			fprintf(fo," ");
		fprintf(fo,"[%d %d](%d)\n\n", node->nodeInfo.lo,node->nodeInfo.hi,node->maxRight);
		displayTree(node->left, level + 8,fo);

	}
}
/*Functions create a new node,reading information from input file.
Return a pointer to the created node*/
Interval *createNewInterval(Interval *newInterval,FILE *f)
{
	newInterval=(struct Interval*)malloc(sizeof(Interval));
	fscanf(f,"%d %d",&newInterval->lo,&newInterval->hi);
	if(newInterval->lo > newInterval->hi)
	{
		int tmp=newInterval->lo;
		newInterval->lo=newInterval->hi;
		newInterval->hi=tmp;
	}
	return newInterval;
}
