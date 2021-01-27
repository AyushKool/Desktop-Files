/*
Binary Search tree is a node-based binary tree data structure which has the following properties:
- The left subtree of a node contains only nodes with keys lesser than the node's key
- The right subtree of a node contains only nodes with keys greater than the node's key
- The left and right subtree each must also be a binary search tree. There must be no duplicate nodes

Searching a Key:
To search a given key in Binary Search Tree, we first compare it with root, if the key is present at root, we return root.
If key is greater than root's key, we recur for right subtree of root node. Otherwise, we recur for the left subtree.

Insertion of a Key:
A new key is always inserted at leaf. We start searching a key from root till we hit a leaf node. Once a leaf node is found, 
the new node is added as a child of the leaf node.
*/
#include <iostream>
#include <cstdlib>
using namespace std;


struct node
{
	int key;
	struct node *left, *right;
};

struct node *newNode(int item)
{
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	
	return temp;
}

void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d\n", root->key);
		inorder(root->right);
	}
}

struct node* insert (struct node *node, int key)
{
	if (node == NULL)
		return newNode(key);
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	
	return node;
}

struct node* search(struct node *root, int key)
{
	if (root == NULL || root->key == key)
		return root;
	
	if (root->key < key)
		return search(root->right, key);
	
	return search(root->left, key);
}

int main()
{
	struct node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
	insert(root, 90);
	
	inorder(root);
}

/*
Time Complexity:
The worst case time complexity of search and insert operations is O(h) where h is height of Binary Search Tree.
In worst case, we may have to travel from root to the deepest leaf node. The height of a skewed tree may become 
n and the time complexity of search and insert operation may become O(n).
*/