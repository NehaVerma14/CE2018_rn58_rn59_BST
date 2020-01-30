
#ifndef BST_H
#define BST_H
class BST {
public:
    virtual void add(int data) = 0;
    virtual void preOrderTraversal() = 0;
    virtual void search(int data) = 0;
};

#endif
