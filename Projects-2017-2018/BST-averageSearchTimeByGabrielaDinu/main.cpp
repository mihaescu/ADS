#include <iostream>
#include "functions.h"
using namespace std;

int main()
{   int x,aux;
    int minValue = 0;
    int MaxValue = 1000000;
    Node *root1=NULL;
    Node *root2=NULL;
    Node *root3=NULL;
    Node *root4=NULL;
    Node *root5=NULL;
    Node *root6=NULL;
    Node *root7=NULL;
    Node *root8=NULL;
    cout<<"Ce doriti sa faceti?";
    int op;
    cout<<"1. generati input"<<endl<<"2. Aflati Apl"<<endl;
    cin>>op;
    if(op==1){
    ofstream outputFile1;
    outputFile1.open("output1.txt");
    ofstream outputFile2;
    outputFile2.open("output2.txt");
    ofstream outputFile3;
    outputFile3.open("output3.txt");
    ofstream outputFile4;
    outputFile4.open("output4.txt");
    ofstream outputFile5;
    outputFile5.open("output5.txt");
    ofstream outputFile6;
    outputFile6.open("output6.txt");
    ofstream outputFile7;
    outputFile7.open("output7.txt");
    ofstream outputFile8;
    outputFile8.open("output8.txt");

    buildInput(outputFile1, minValue, MaxValue, 100);
    buildInput(outputFile2, minValue, MaxValue, 200);
    buildInput(outputFile3, minValue, MaxValue, 400);
    buildInput(outputFile4, minValue, MaxValue, 800);
    buildInput(outputFile5, minValue, MaxValue, 1600);
    buildInput(outputFile6, minValue, MaxValue, 3200);
    buildInput(outputFile7, minValue, MaxValue, 6400);
    buildInput(outputFile8, minValue, MaxValue, 12800);
    }
    else{
    ifstream outputFile1;
    outputFile1.open("output1.txt");
    ofstream outputFileResults;
    outputFileResults.open("output_results.txt");
    ifstream outputFile2;
    outputFile2.open("output2.txt");
    ifstream outputFile3;
    outputFile3.open("output3.txt");
    ifstream outputFile4;
    outputFile4.open("output4.txt");
    ifstream outputFile5;
    outputFile5.open("output5.txt");
    ifstream outputFile6;
    outputFile6.open("output6.txt");
    ifstream outputFile7;
    outputFile7.open("output7.txt");
    ifstream outputFile8;
    outputFile8.open("output8.txt");

root1=(Node *)malloc(sizeof(Node));
root1->data=1;
root1->left=root1->right=NULL;
root2=(Node *)malloc(sizeof(Node));
root2->data=2;
root2->left=root2->right=NULL;
root3=(Node *)malloc(sizeof(Node));
root3->data=3;
root3->left=root3->right=NULL;
root4=(Node *)malloc(sizeof(Node));
root4->data=4;
root4->left=root4->right=NULL;
root5=(Node *)malloc(sizeof(Node));
root5->data=5;
root5->left=root5->right=NULL;
root6=(Node *)malloc(sizeof(Node));
root6->data=6;
root6->left=root6->right=NULL;
root7=(Node *)malloc(sizeof(Node));
root7->data=7;
root7->left=root7->right=NULL;
root8=(Node *)malloc(sizeof(Node));
root8->data=8;
root8->left=root8->right=NULL;


    while (outputFile1>>x)
        {aux=x;
        Add_Node(root1,aux);
        }
    while (outputFile2>>x)
        {aux=x;
        Add_Node(root2,aux);
        }

    while (outputFile3>>x)
        {aux=x;
        Add_Node(root3,aux);
        }

    while (outputFile4>>x)
        {aux=x;
        Add_Node(root4,aux);
        }
    while (outputFile5>>x)
        {aux=x;
        Add_Node(root5,aux);
        }
    while (outputFile6>>x)
        {aux=x;
        Add_Node(root6,aux);
        }
    while (outputFile7>>x)
        {aux=x;
        Add_Node(root7,aux);
        }
    while (outputFile8>>x)
        {aux=x;
        Add_Node(root8,aux);
        }



    outputFileResults <<" average path length for bst with 100 nodes is "<<computeAveragePathLength(root1)<<endl;
    outputFileResults <<" average path length for bst with 200 nodes is "<<computeAveragePathLength(root2)<<endl;
    outputFileResults <<" average path length for bst with 400 nodes is "<<computeAveragePathLength(root3)<<endl;
    outputFileResults <<" average path length for bst with 800 nodes is "<<computeAveragePathLength(root4)<<endl;
    outputFileResults <<" average path length for bst with 1600 nodes is "<<computeAveragePathLength(root5)<<endl;
    outputFileResults <<" average path length for bst with 3200 nodes is "<<computeAveragePathLength(root6)<<endl;
    outputFileResults <<" average path length for bst with 6400 nodes is "<<computeAveragePathLength(root7)<<endl;
    outputFileResults <<" average path length for bst with 12800 nodes is "<<computeAveragePathLength(root8)<<endl;

    }
    return 0;
}
