#include<stdio.h>
#include<conio.h>

#include "B.h"

#define m 4
using namespace std;

int main(){
    int c;
    int ch;
    int keyx,key;
    NodeB *roo;
    roo=NULL;
    while(true){
                printf("\n 1.Add");
                printf("\n 2.Delete");
                printf("\n 3.Search");
                printf("\n 4.Write");
                printf("\n 5.Exit");
                printf("\n\n");
                
                scanf("%d",&ch);
                
                 switch(ch){
                            case 1:
                                 do{
                                     printf("\n create node? <0/1>");
                                     scanf("%d",&c);
                                     printf("\n");
                                     if(c==1){
                                              printf("\n Enter key: ");
                                              scanf("%d",&key);
                                              roo=insert(key);
                                              }
                                     }while(c!=0);
                                     break;
                             
                             case  2:
                                   printf("\n Enter Key: ");
                                   scanf("%d",&key);
                                   roo=deleteKey(&roo,key);
                                   break;
                             
                             case 3:
                                  printf("Enter key to search \n");
                                  scanf("%d",&keyx);
                                  search(roo,keyx);
                                  break;
                                  
                             case 4:
                                  printf("\n\n");
                                  displayTree(roo,4);
                                  break;
                                  
                             case 5:
                                  return(0);
                            }
                 }
}
