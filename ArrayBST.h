#include "BST.h"
#define MAX_SIZE 1000

class ArrayBST: public BST
{
public:
    void add(int data);
    int preOrderTraverlsal();
    void search(int data);
private:
    int data[MAX_SIZE];
}
