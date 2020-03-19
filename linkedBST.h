#ifndef LINKEDBST_H
#define LINKEDBST_H

#include "BST.h"
#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;
};


class LinkedBST:public BST{
    public:
    Node* root;
    LinkedBST();
    ~LinkedBST();
    void preOrder();
    void add(int data);
    void add(Node* &root,int data);
    bool search(int data);
    int min();
    int max();
    void inOrder();
    void deleteNode(int val);

    private:
    bool searchFromTree(Node* &root,int targetKey);
    void insert(Node* &subtree, Node* newNode);
    void traversePreOrder(Node* root);
    void traverseInOrder(Node *root);
    void deleteFromTree(Node *root,int val);
};

LinkedBST::LinkedBST()
{
    root=NULL;
}

LinkedBST::~LinkedBST(){}

void LinkedBST::add(int data)
{
    add(root,data);
}

void LinkedBST::add(Node* &root,int data)
{
    Node* newNode=new Node();
    newNode->data=data;
    if(root==NULL){
        root=new Node();
        this->root=newNode;
    }
    else{
        insert(root,newNode);
    }
}



void LinkedBST::insert(Node* &subtree, Node* newNode)
{
    if(subtree->data>newNode->data){
        if(subtree->left!=NULL){
            insert(subtree->left,newNode);
        }
        else{
            subtree->left=newNode;
        }
    }
    else{
        if(subtree->right!=NULL){
            insert(subtree->right,newNode);
        }
        else{
            subtree->right=newNode;
        }
    }
}


bool LinkedBST::search(int data)
{
    return searchFromTree(root,data);
}

bool LinkedBST::searchFromTree(Node* &root,int targetKey)
{
    if(root==NULL){
        cout<<"It is a Null tree"<<endl;
    }
    else{
        Node* p=new Node();
        p=root;
        while(p!=NULL){
            if(targetKey>p->data){
                p=p->right;
            }
            else if(targetKey<p->data){
                p=p->left;
            }
            else if(targetKey==p->data){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}


void LinkedBST::preOrder()
{
    traversePreOrder(root);
}

void LinkedBST::inOrder()
{
    traverseInOrder(root);
}

void LinkedBST::traversePreOrder(Node* root)
{
    if (root == NULL)
    return;
    cout << root->data << " ";
    traversePreOrder(root->left);
    traversePreOrder(root->right);
}

void LinkedBST::traverseInOrder(Node* root)
{
    if (root == NULL)
    return;
    traverseInOrder(root->left);
    cout << root->data << " ";
    traverseInOrder(root->right);
}

int LinkedBST::min()
{
    if (root==NULL)
    {
        cout<<"No value"<<endl;
        return -1;
    }
    else
    {
        Node* temp=root;
        while(temp->left!=NULL)
        {
            temp=temp->left;
        }
        return temp->data;
    }
}

int LinkedBST::max()
{
    if (root==NULL)
    {
        cout<<"No value"<<endl;
        return -1;
    }
    else
    {
        Node* temp=root;
        while(temp->right!=NULL)
        {
            temp=temp->right;
        }
        return temp->data;
    }
}

void LinkedBST::deleteNode(int val)
{
    deleteFromTree(root,val);
}

void LinkedBST::deleteFromTree(Node *root,int val)
{
    int dat;
    if(root==NULL){
        cout<<"tree is empty"<<endl;
        return;
    }
    if(val<root->data){
        Node* temp=new Node();
        temp=root->left;
        if(root->left->data==val && root->left->left==NULL && root->left->right==NULL){
            root->left=NULL;
        }
        deleteFromTree(temp,val);
        return;
    }
    else if(val>root->data){
        Node* temp=new Node();
        temp=root->right;
        if(root->right->data==val && root->right->left==NULL && root->right->right==NULL){
            root->right=NULL;
        }
        deleteFromTree(temp,val);
        return;
    }
    else{
        if(root->left==NULL && root->right==NULL){
            delete root;
            root=NULL;
            return;
        }
        else if(root->left==NULL){
            Node* temp=new Node();
            temp=root->right;
            root->data=root->right->data;
            root->right=root->right->right;
            delete temp;
            return;
        }
        else if(root->right==NULL){
            Node* temp=new Node();
            temp=root->left;
            root->data=root->left->data;
            root->left=root->left->left;
            delete temp;
            return;
        }
        else{
            Node* nodetoDelete=new Node();
            nodetoDelete=root;
            Node* newNode=new Node();
            newNode=root->left;
            while(newNode->right!=NULL){
                newNode=newNode->right;
            }
            dat=newNode->data;
            deleteFromTree(nodetoDelete,newNode->data);
            root->data=dat;
            return;
        }
    }
}
#endif
