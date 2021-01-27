#include <bits/stdc++.h>
using namespace std;
#define  null nullptr

struct Node {
public:
    int val;
    Node *l, *r;
    Node(int val, Node* left = null, Node* right = null)
    {
        this->val = val;
        l = left, r = right;
    }
};
using Node = struct Node;

void branchSum(Node* &n, int sum = 0)
{
    if(!(n->l || n->r)) cout << (n->val + sum) << " ";
    else{
        if(n->l) branchSum(n->l, sum + n->val);
        if(n->r) branchSum(n->r, sum + n->val);
    }
}

int main()
{
    Node *root = 
    new Node(1, 
        new Node(2, 
            new Node(4), 
            new Node(5, 
                new Node(10))), 
        new Node(3, 
            new Node(6), 
            new Node(7))
    );
    branchSum(root);
    // cout << root->val << root->l->val << root->r->val;
}