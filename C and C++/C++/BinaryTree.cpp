/*
Trees: Unlike Arrays, Linked Lists, Stack and Queues, which are linear data structures, trees are hierarchical
data structures.

Tree Vocabulary: The topmost Node is called root of the tree. The elements that are directly under an element
are called its children. The element directly above something is called its parent. For example, 'a' is a child
of 'f' and 'f' is a parent of 'a'. Finally, elements with no children are called leaves.

	TREE
   ------
	 j   <---ROOT
    / \
   f   k
  / \   \
 a   h   z   <---LEAVES
 
*/
#include <iostream>
#include <cstdlib>
using namespace std;

//TRAVERSALS
/*
Unlike linear data structures (Array, Linked List, Queues, Stacks, etc) which have only one logical way to traverse
them, trees can be traversed in different ways. Following are the generally used ways for traversing trees:

					TREE
				   ------
					 1
					/ \
				   2   3
				  / \   
				 4   5   


Depth First Traversal:
1) Inorder (Left, Root Right): 4 2 5 1 3
2) Preorder (Root, Left, Right): 1 2 4 5 3
3) Postorder (Left, Right, Root): 4 5 2 3 1

Breath First or Level Order Traversal: 1 2 3 4 5
*/
struct Node
{
	int data;
	struct Node *left, *right;
	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

void postorder(struct Node *node)
{
	
	if (node != NULL)
	{
		postorder(node->left);
		postorder(node->right);
		cout << node->data << endl;
	}
}

void inorder(struct Node *node)
{
	
	if (node != NULL)
	{
		inorder(node->left);
		cout << node->data << endl;
		inorder(node->right);
	}
}

void preorder(struct Node *node)
{
	
	if (node != NULL)
	{
		cout << node->data << endl;
		preorder(node->left);
		preorder(node->right);
	}
}


int main()
{
	struct Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->left->right->left = new Node(6);
	
	cout << "INORDER: " << endl;
	inorder(root);
	
	cout << "POSTORDER: " << endl;
	postorder(root);
	
	cout << "PREORDER: " << endl;
	preorder(root);
}