#include <iostream>
#include "functions.h"
using namespace std;

int main()
{   int element;  //element to be inserted in the BST
    int ok11=1,ok12=1,ok21=1,ok22=1,ok31=1,ok32=1,ok41=1,ok42=1,ok51=1,ok52=1,ok61=1,ok62=1,ok71=1,ok72=1,ok81=1,ok82=1;//variables we use to check the correctness
                                                                                                                        //of the IPL function
    int minValue = 0; //minimum value that can be inserted in a BST
    int MaxValue = 1000000; // maximum value that can be inserted in a BST

//Roots of the BSTs
    Node *root1 = NULL;
    Node* root2 = NULL;
    Node *root3 = NULL;
    Node *root4 = NULL;
    Node *root5 = NULL;
    Node *root6 = NULL;
    Node *root7 = NULL;
    Node *root8 = NULL;

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



    cout<<"What do you want to do?"<<endl;
    int op;
    cout<<"1. Generate input"<<endl<<"2. Compute Apl"<<endl;
    cin>>op;
    if(op==1){
            //we open all the files in we will generate the input for the BST...
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
            //...and generate the input
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
//we open all the files from which we will read the previously randomly generated input and another file in which we will write the results
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
//we add all the read elements in BSTs
        while (outputFile1>>element)
        {
            Add_Node(root1,element);
        }
        while (outputFile2>>element)
            {
            Add_Node(root2,element);
            }
        while (outputFile3>>element)
            {
            Add_Node(root3,element);
            }
        while (outputFile4>>element)
            {
            Add_Node(root4,element);
            }
        while (outputFile5>>element)
            {
            Add_Node(root5,element);
            }
        while (outputFile6>>element)
            {
            Add_Node(root6,element);
            }
        while (outputFile7>>element)
            {
            Add_Node(root7,element);
            }
        while (outputFile8>>element)
            {
            Add_Node(root8,element);
            }
//compute the internal path length for each BST in two ways...
        ok11 = computeIPL(root1,0);
        ok12 = internalPathLength(root1, ok12);
        ok21 = computeIPL(root2,0);
        ok22 = internalPathLength(root2, ok22);
        ok31 = computeIPL(root3,0);
        ok32 = internalPathLength(root3, ok32);
        ok41 = computeIPL(root4,0);
        ok42 = internalPathLength(root4, ok42);
        ok51 = computeIPL(root5,0);
        ok52 = internalPathLength(root5, ok52);
        ok61 = computeIPL(root6,0);
        ok62 = internalPathLength(root6, ok62);
        ok71 = computeIPL(root7,0);
        ok72 = internalPathLength(root7, ok72);
        ok81 = computeIPL(root8,0);
        ok82 = internalPathLength(root8, ok82);
//...and check if both functions return the same result
        if(ok11==ok12)
            cout<<"the IPL is correct"<<endl;
        else cout<<"the IPL is not correct";
        if(ok21==ok22)
            cout<<"the IPL is correct"<<endl;
        else cout<<"the IPL is not correct";
        if(ok31==ok32)
            cout<<"the IPL is correct"<<endl;
        else cout<<"the IPL is not correct";
        if(ok41==ok42)
            cout<<"the IPL is correct"<<endl;
        else cout<<"the IPL is not correct";
        if(ok51==ok52)
            cout<<"the IPL is correct"<<endl;
        else cout<<"the IPL is not correct";
        if(ok61==ok62)
            cout<<"the IPL is correct"<<endl;
        else cout<<"the IPL is not correct";
        if(ok71==ok72)
            cout<<"the IPL is correct"<<endl;
        else cout<<"the IPL is not correct";
        if(ok81==ok82)
            cout<<"the IPL is correct"<<endl;
        else cout<<"the IPL is not correct";
//finally compute the average path length and write it in the results file
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
