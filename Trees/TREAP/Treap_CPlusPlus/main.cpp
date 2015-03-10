#include "Treap.h"

ctree nullnode, root;

/*
 * Main Contains Menu
 */
int main()
{
	srand ((unsigned int)time (NULL));
    CTree ct;
    int choice, num;
    bool flag = false;
    ct.initialize();
    while (1)
    {
        cout<<endl<<"----------------------------"<<endl;
        cout<<endl<<"Operations on Treap"<<endl;
        cout<<endl<<"----------------------------"<<endl;
        cout<<"1.Insert Element "<<endl;
        cout<<"2.Delete Element "<<endl;
        cout<<"3.Inorder Traversal"<<endl;
        cout<<"4.Display in Order"<<endl;
        cout<<"5.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter the number to be inserted : ";
            cin>>num;
            ct.insert(root, num);
            break;
        case 2:
            if (root == nullnode)
            {
                cout<<"Tree is empty, nothing to delete"<<endl;
                continue;
	    }
            cout<<"Enter the number to be deleted : ";
            cin>>num;
            if (ct.find(root, num))
                flag = true;
            else
                cout<<"Element not found"<<endl;
            ct.remove(root, num);
            if (!ct.find(root, num) && flag)
                cout<<"Element Deleted"<<endl;
            break;
        case 3:
            if (root == nullnode)
            {
                cout<<"Tree is empty, insert element first"<<endl;
                continue;
            }
            cout<<"Inorder Traversal:"<<endl;
            ct.inorder(root);
            cout<<endl;
            break;  
        case 4:
            if (root == nullnode)
            {
                cout<<"Tree is empty"<<endl;
                continue;
            }
            cout<<"Display Treap:"<<endl;
            ct.display(root, 1);
            cout<<endl; 
            break;
        case 5:
            exit(1);
            break;
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
}
