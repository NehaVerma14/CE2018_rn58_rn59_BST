#define ArrarBST_h
#include"BST.h"
#define MAX_SIZE 16
class ArrayBST:public BST{
	public:
		int element[MAX_SIZE];
		ArrayBST();
		~ArrayBST();
		void preorder();
		void add(int data);
		int search(int data);	
		int min(int i=1);   // minimum value in BST
		int max(int i=1);
		int left_child(int i);
		int right_child( int i);
		void inorder(int i=1);
		void delete_node(int data);
};

