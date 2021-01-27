/*
TYPES OF BINARY TREES:
- Full Binary Tree(proper binary tree or 2-tree): 
A Binary Tree is full if every node has 0 or 2 children.
We can also say a full binary tree is a binary tree in which all nodes except leaves have two children.

- Complete Binary Tree: 
A Binary Tree is Complete Binary Tree if all levels are completely filled except
possibly the last level and the last level has all keys as left as possible.

- Perfect Binary Tree:
A Binary Tree is Perfect Binary Tree in which all internal nodes have two children and all leaves are at the 
same level.
A Perfect Binary tree of height h (where height is the number of nodes on the path from the root to leaf) has 2^h - 1 node

- Balanced Binary Tree:
A Binary Tree is balanced if the height of the tree is O(log n) where n is the number of nodes. For Example, AVL tree maintains
O(log n) height by making sure that the difference between heights of left and right subtrees is 1. Red-Black trees maintain O(log n)
height by making sure that the number of Black nodes on every root to leaf paths are same and there are no adjacent red nodes. Balanced
Binary Search Trees are performance wise good as they  provide O(log n) time for search, insert and delete.

- Degenerate (or Pathological) Tree:
A Tree where every internal node has node has one child. Such trees are performance wise same as linked List.
*/