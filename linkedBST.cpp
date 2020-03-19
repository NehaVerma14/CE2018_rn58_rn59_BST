#include "linkedBST.h"
#include <iostream>
using namespace std;

int main()
{
    cout<<"***Binary Tree Linked List Implementation***"<<endl<<endl;
    LinkedBST tree;

    //adding data
    tree.add(50);
    tree.add(90);
    tree.add(41);
    tree.add(254);
    tree.add(15);
    tree.add(125);
    tree.add(47);

    cout<<"Pre-order traversal: "<<endl;
    tree.preOrder();
    cout<<endl;
    

    cout<<"In-order traversal: "<<endl;
    tree.inOrder();
    cout<<endl;

    cout<<"Adding 101: ";
    tree.add(101);
    cout<<endl;

    cout<<"Pre-order traversal: "<<endl;
    tree.preOrder();
    cout<<endl;

    cout<<"In-order traversal: "<<endl;
    tree.inOrder();
   cout<<endl;

    cout<<"Is 47 in data: "<<tree.search(47)<<endl;
    cout<<"Is 13 in data: "<<tree.search(13)<<endl;
    cout<<endl;

    cout<<"Min. value is: "<<tree.min()<<endl;
    cout<<"Max. value is: "<<tree.max()<<endl;

    cout<<endl;

    //deleting 11 and 101
    tree.deleteNode(47);
    tree.deleteNode(101);

    cout<<"Deleting node 11 and 101:"<<endl;
    cout<<"Is 47 in data: "<<tree.search(47)<<endl;
    cout<<endl;

    cout<<"In-order traversal: "<<endl;
    tree.inOrder();
   

    return 0;
}
