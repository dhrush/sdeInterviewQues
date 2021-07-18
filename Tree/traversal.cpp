#include <iostream>
using namespace std;

class Node
{
private:
    int data;

public:
    Node *left = NULL;
    Node *right = NULL;

    Node(int d) { this->data = d; }
    int getData() { return this->data; }
};

void printInorder(Node *root)
{
    if (root == NULL)
        return;
    printInorder(root->left);

    cout << root->getData() << " ";

    printInorder(root->right);
}

void printPreOrder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->getData() << " ";

    printPreOrder(root->left);

    printPreOrder(root->right);
}

void printPostOrder(Node *root)
{
    if (root == NULL)
        return;

    printPostOrder(root->left);

    printPostOrder(root->right);

    cout << root->getData() << " ";
}

int main()
{
    Node *a = new Node(30);
    Node *b = new Node(20);
    Node *c = new Node(40);
    Node *d = new Node(15);
    Node *e = new Node(25);
    Node *f = new Node(35);
    Node *g = new Node(45);

    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->left = f;
    c->right = g;

    //printInorder(a);
    //printPreOrder(a);
    printPostOrder(a);
    return 0;
}
