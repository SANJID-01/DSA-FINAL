#include <bits/stdc++.h>
using namespace std;

// Node class for the BST
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

// Function to take input and construct a tree level by level
Node *input_tree()
{
    int val;
    cin >> val;

    Node *root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);

    queue<Node *> q;
    if (root)
        q.push(root);

    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        Node *myLeft = (l == -1) ? NULL : new Node(l);
        Node *myRight = (r == -1) ? NULL : new Node(r);

        p->left = myLeft;
        p->right = myRight;

        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}

// Level-order traversal function
void level_order(Node *root)
{
    if (root == NULL)
    {
        cout << "Tree nai" << endl;
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();

        cout << f->val << " ";

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
    cout << endl;
}

// Insert a value into the BST
void insert(Node *&root, int x)
{
    if (root == NULL)
    {
        root = new Node(x);
        return;
    }
    if (x < root->val)
    {
        if (root->left == NULL)
        {
            root->left = new Node(x);
        }
        else
        {
            insert(root->left, x);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = new Node(x);
        }
        else
        {
            insert(root->right, x);
        }
    }
}

// Pre-order traversal function
void pre_order(Node *root)
{
    if (root == NULL)
        return;

    cout << root->val << " ";
    pre_order(root->left);
    pre_order(root->right);
}

// In-order traversal function
void in_order(Node *root)
{
    if (root == NULL)
        return;

    in_order(root->left);
    cout << root->val << " ";
    in_order(root->right);
}

// Post-order traversal function
void post_order(Node *root)
{
    if (root == NULL)
        return;

    post_order(root->left);
    post_order(root->right);
    cout << root->val << " ";
}

// Find the minimum value node in a BST
Node *find_min(Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete a value from the BST
Node *delete_node(Node *root, int x)
{
    if (root == NULL)
        return NULL;

    if (x < root->val)
    {
        root->left = delete_node(root->left, x);
    }
    else if (x > root->val)
    {
        root->right = delete_node(root->right, x);
    }
    else
    {
        // Node with only one child or no child
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

        // Node with two children: Get the inorder successor
        Node *temp = find_min(root->right);
        root->val = temp->val;
        root->right = delete_node(root->right, temp->val);
    }
    return root;
}

// Main function
int main()
{
    Node *root = input_tree();

    int choice;
    while (true)
    {
        cout << "\n1. Level-order Traverse\n";
        cout << "2. Pre-order Traverse\n";
        cout << "3. In-order Traverse\n";
        cout << "4. Post-order Traverse\n";
        cout << "5. Insert a Node\n";
        cout << "6. Delete a Node\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0)
        {
            break;
        }

        switch (choice)
        {
        case 1:
            level_order(root);
            break;
        case 2:
            pre_order(root);
            cout << endl;
            break;
        case 3:
            in_order(root);
            cout << endl;
            break;
        case 4:
            post_order(root);
            cout << endl;
            break;
        case 5:
        {
            int val;
            cout << "Enter value to insert: ";
            cin >> val;
            insert(root, val);
            break;
        }
        case 6:
        {
            int val;
            cout << "Enter value to delete: ";
            cin >> val;
            root = delete_node(root, val);
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
