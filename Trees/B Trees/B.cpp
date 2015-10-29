#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "B.h"
#define m 4

using namespace std;

NodeB *pUpKey,*root;


NodeB *insert(int key){              // insert key read in the B tree and will return the corresponding root pointer
      int ind,keyX,upKey,ok;
      NodeB *pv;
      NodeB *adr;
       keyX=key;
                                     //search starting with the root side of insertion of the keyX
       splitPage(root,keyX,upKey,ok);
       if(ok){
             pv=( NodeB*)malloc(100) ;
             pv->pNodes[0]=root;
             pv->pNodes[1]=pUpKey;
             pv->keys[1]=upKey;
             pv->nr=1;
             root=pv;
             }
       if(keyX==upKey){
                  adr=root;
                  ind=1;
                  }
       return root;
       }
 
void splitPage(NodeB *node,int keyX,int &upKey,int &ok){   // search keyX in the current page node and inserted in place of corresponding
      NodeB *adr; 
      int ind,found;
      int position,new1;
      if(node==NULL){                   //not found
                  ok=1;
                  new1=1;
                  upKey=keyX;
                  pUpKey=NULL;
                  }
      else{           //search in the current page
           position=1;
           found=0;
           while(position<=node->nr&&!found)
                                  {
                                  if(node->keys[position]>=keyX)
                                                   found=1;
                                  position++;
                                  }
           if(found)
           position--;  //not found
           if(position>node->nr)
           found=0;
           else{
                if(node->keys[position]==keyX)
                found=1;
                else 
                found=0;
                }
           if(found){
                     new1=0;
                     adr=node;
                     ind=position;
                     ok=0;
                     printf("The key is already in the tree \n");
                     }
           else{
                splitPage(node->pNodes[position-1],keyX,upKey,ok); //passing the search
                if(ok)
                    placeInPage(node,position,keyX,upKey,ok);  //keyX is inserted in the page node
                }
                
           }
           
      }
void placeInPage(NodeB *node,int position,int keyX,int &upKey,int &ok){   //actually insert the keyX in the page node in the position position of of keys vector
    NodeB *pv;
     int key;
     int halfm;
     halfm=node->nr/2;
     if(node->nr==m){  //be fissionable page
                  pv=( NodeB*)malloc(100) ;
                  pv->nr=halfm;
                  node->nr=halfm;
                  if(position>halfm){   //right halfpage
                                if(position==halfm+1){
                                                 copyPage(pv,node,halfm+1,1,halfm);
                                                 pv->pNodes[0]=pUpKey;
                                                 }
                                else{// climb item key[n+1]
                                     position=position-halfm-1;
                                     copyPage(pv,node,halfm+2,1,position-1);
                                     pv->keys[position]=upKey;
                                     pv->pNodes[position]=pUpKey;
                                     copyPage(pv,node,halfm+position+1,position+1,halfm-position);
                                     pv->pNodes[0]=node->pNodes[halfm+1];
                                     upKey=node->keys[halfm+1];
                                     }
                                }
                  else {    //left halfpage
                       copyPage(pv,node,halfm+1,1,halfm);
                       pv->pNodes[0]=node->pNodes[halfm];
                      key=node->keys[halfm];
                       copyPage(node,node,position,position+1,halfm-position);
                       node->pNodes[position]=pUpKey;
                       node->keys[position]=upKey;
                       upKey=key;
                       }
                  pUpKey=pv;
     }
     else
     insertInNonFullLeaf(node,position,keyX,upKey,ok);
    
     }
     
    void insertInNonFullLeaf(NodeB *node,int position,int keyX,int &upKey,int &ok){   //enter in the current node
          NodeB *adr;
          int ind;
          ok=0;
          node->nr=node->nr+1;
          copyPage(node,node,position,position+1,node->nr-position);
          node->pNodes[position]=pUpKey;
          node->keys[position]=upKey;
          if(upKey==keyX){
                     ind=position;
                     adr=node;
                     }
        
          }
          
     void copyPage(NodeB *destination,NodeB *source,int sourceIndex,int destIndex,int n){   //copy the information from the page node to the page dest starting with the index id
          while(n>0){
                     n--;
                     destination->keys[destIndex+n]=source->keys[sourceIndex+n];
                     destination->pNodes[destIndex+n]=source->pNodes[sourceIndex+n]; //descendants addresses
                     }
          }
                       
  void search(NodeB *nodex,int numtosearch){         //search a key in the tree                                   
       int position,found;
       if(nodex==NULL){  //not found
                   printf("The key is not in tree !");
                   }
       else{ //search in the current page
            position=1;
            found=0;
            while((position<=nodex->nr)&&(!found)){
                                        found=(nodex->keys[position]==numtosearch);
                                        position++;
                                        }
            if(found){
                      position--;
                      printf("The key is in the tree\n");  //found
                      }
            else{
                 if(position>nodex->nr){
                             found=0;
                             }
                 else{
                      found=(nodex->keys[position]==numtosearch);
                      }
                  if(found){
                            printf("The key is in the tree\n");
                            }
                  else{
                       search(nodex->pNodes[position-1],numtosearch);
                       }
                  }
            }
       }
       
  void displayTree(NodeB *node ,int level){   //display the tree
       int j;
       if(node!=NULL){
                      for(j=1;j<=level;j++)
                      printf(" ");
                      for(j=1;j<=node->nr;j++)
                      printf("%d ",node->keys[j]);  //write the keys
                      printf("\n");
                      for(j=0;j<=node->nr;j++)
                      displayTree(node->pNodes[j],level+1);
                      }
}

int findMinimum(NodeB *page){
    if(page->pNodes[0]==NULL)
    return page->keys[1];
    else
    return findMinimum(page->pNodes[0]);
}

NodeB * deleteKey(NodeB **nod,int key){      // delete a key 
     NodeB *temp;
     int i=1,j,nr=(*nod)->nr;
     NodeB *child=NULL;
     NodeB *creditor;
     if((*nod)->keys[nr]<key){ //key can only find the last child node
                              child=(*nod)->pNodes[nr];
                              i=nr;
                              if(child==NULL){ // search key is not found in tree
                                              return root;
                                              }
                              }
     else{ //key can be found in one node or in children
          while(key>(*nod)->keys[i])
          i++;
          if(key==(*nod)->keys[i]){   //found in this node
                                  if((*nod)->pNodes[i]==NULL){  //is leaf node
                                                              for(;i<nr;i++){   //move all keys removed from the right , turn left one position
                                                                             (*nod)->keys[i]=(*nod)->keys[i+1];
                                                                             }
                                                              (*nod)->nr--; //we do not have anyting to do at this level
                                                              return root;
                                                              }// search succesor of the delete key
                                  key=findMinimum((*nod)->pNodes[i]);
                                  (*nod)->keys[i]=key;
                                 child=(*nod)->pNodes[i]; //still delete key successor 
                                  }
          else{// key is smaller than key[i]
          //i will always be the key index to be delete
               i--;
               child=(*nod)->pNodes[i];
               }
          }
          //delete from child
          deleteKey(&child,key);  //search if we have number of keys in child and fix
          if(child->nr<(m/2)){
                              if(i>0){//the child is not the first node
                                      creditor=(*nod)->pNodes[i-1];
                                      if(creditor->nr>(m/2)){//make place for loan
                                                             for(j=child->nr;j>0;j--){
                                                                                      child->keys[j+1]=child->keys[j];
                                                                                      child->pNodes[j+1]=child->pNodes[j];
                                                                                      }//first node is not moved by cycle
                                                             child->pNodes[1]=child->pNodes[0];
                                                             child->nr++;  //borrow a key from the left neighbor,passing the paret 
                                                             child->keys[1]=(*nod)->keys[i];
                                                             (*nod)->keys[i]=creditor->keys[creditor->nr];
                                                             child->pNodes[0]=creditor->pNodes[creditor->nr];// now the left node is less with one key
                                                             creditor->nr--;
                                                             }
                                      else{//and the left node has too few keys,so merging nodes
                                           j=creditor->nr+1;//take keys from parent
                                           creditor->keys[j]=(*nod)->keys[i];
                                           creditor->pNodes[j]=child->pNodes[0];
                                           for(;i<nr;i++){//move all keys removed from the right,turn left with one position
                                                          (*nod)->keys[i]=(*nod)->keys[i+1];
                                                          (*nod)->pNodes[i]=(*nod)->pNodes[i+1];
                                                          }// father now has a child less
                                           (*nod)->nr--;//take all the right node keys ,you have total
                                           creditor->nr+=1+child->nr;
                                           while(child->nr>0){
                                                              creditor->keys[j+child->nr]=child->keys[child->nr];
                                                              child->nr--;
                                                              }
                                           free (child);
                                           }
                                      }
                              else{//child is the first node
                                   creditor=(*nod)->pNodes[1];
                                   if(creditor->nr>(m/2)){//we borrow
                                                          child->nr++;//borrow a key to the right node,by parent
                                                          child->pNodes[child->nr]=creditor->pNodes[0];
                                                          child->keys[child->nr]=(*nod)->keys[1];//move to left creditor key
                                                          (*nod)->keys[1]=creditor->keys[1];
                                                          creditor->pNodes[0]=creditor->pNodes[1];
                                                          for(j=1;j<creditor->nr;j++){
                                                                                      creditor->keys[j]=creditor->keys[j+1];
                                                                                      creditor->pNodes[j]=creditor->pNodes[j+1];
                                                                                      }// now right node has a key less
                                                          creditor->nr--;
                                                          }
                                   else{//and right node has too few keys, so merging nodes
                                        j=child->nr+1;//take on key from the parent ,first
                                        i=1;
                                        child->keys[j]=(*nod)->keys[i];
                                        child->pNodes[j]=creditor->pNodes[0];
                                        for(;i<nr;i++){//move all keys removed from the right ,turn left with one position
                                                       (*nod)->keys[i]=(*nod)->keys[i+1];
                                                       (*nod)->pNodes[i]=(*nod)->pNodes[i+1];
                                                       }//father now has a child less
                                        (*nod)->nr--;//after take all right node keys ,you have total
                                        child->nr+=1+creditor->nr;
                                        while(creditor->nr>0){
                                                               child->keys[j+creditor->nr]=creditor->keys[creditor->nr];
                                                               child->pNodes[j+creditor->nr]=creditor->pNodes[creditor->nr];
                                                               creditor->nr--;
                                                               }
                                        free (creditor);
                                        }
                                   }
                              }
          if((root)->nr==0){//we do not have any root key
                            temp=root;
                            root=(root)->pNodes[0];
                            free (temp);
                            }
          return root;                  
          }

                                                          
                                                                                                                   
                                                             
                                               
                                   
                     
                                     
                                   
                                  
                
           
