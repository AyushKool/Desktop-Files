#include <bits/stdc++.h>
using namespace std;
#define  null nullptr
#define NL cout << '\n';
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

void invert(Node* &n)
{
    if(!n) return;
    //Invert before and after doesn't matter

    // invert(n->l);
    // invert(n->r);
    #pragma region SwapLR
    Node* tmp = n->r;
    n->r = n->l;
    n->l = tmp;
    #pragma endregion
    invert(n->l);
    invert(n->r);
}

void printBT(Node* &n)
{
    if(!n) return;
    cout << n->val << " ";
    printBT(n->l);
    printBT(n->r);
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
    printBT(root);
    NL;
    invert(root);
    printBT(root);

    // cout << root->val << root->l->val << root->r->val;

}

/*
new Node(1, 
        new Node(2, 
            new Node(4), 
            new Node(5, 
                new Node(10))), 
        new Node(3, 
            new Node(6), 
            new Node(7))
    );
*/