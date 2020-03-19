#ifndef BST_h
#define BST_h
class BST {
	public:
		virtual void preorder()=0;
		virtual void add(int data)=0;
		virtual int search(int data)=0;
		virtual int min(int i=1) =0; // to find the minimum value in the BST.
		virtual void inorder(int i=1)=0;
		virtual void delete_node(int val)=0;
		
};
#endif
