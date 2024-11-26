#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insert(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);

    return root;
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

Node *findMin(Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node *deleteNode(Node *root, int val)
{
    if (root == NULL)
        return root;

    if (val < root->val)
        root->left = deleteNode(root->left, val);
    else if (val > root->val)
        root->right = deleteNode(root->right, val);
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        Node *temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }

    return root;
}

int main()
{
    Node *root = NULL;
    char op;
    int val;

    while (true)
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert an element into the BST\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Delete an element from the BST\n";
        cout << "0. Exit\n";
        cout << "Enter your option: ";
        cin >> op;

        switch (op)
        {
        case '1':
            cout << "Enter the value to insert: ";
            cin >> val;
            root = insert(root, val);
            cout << "Value " << val << " inserted into the BST.\n";
            break;

        case '2':
            cout << "Preorder Traversal: ";
            preorder(root);
            cout << endl;
            break;

        case '3':
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;

        case '4':
            cout << "Postorder Traversal: ";
            postorder(root);
            cout << endl;
            break;

        case '5':
            cout << "Enter the value to delete: ";
            cin >> val;
            root = deleteNode(root, val);
            cout << "Value " << val << " deleted from the BST (if present).\n";
            break;

        case '0':
            cout << "Exiting the program.\n";
            return 0;

        default:
            cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
