#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void Find(Node* root, int item, Node** loc, Node** par) {
    Node* ptr = nullptr;
    Node* save = nullptr;

    if (root == nullptr) {
        *loc = nullptr;
        *par = nullptr;
        return;
    }

    if (item == root->val) {
        *loc = root;
        *par = nullptr;
        return;
    }

    if (item < root->val) {
        ptr = root->left;
        save = root;
    } else {
        ptr = root->right;
        save = root;
    }

    while (ptr != nullptr) {
        if (item == ptr->val) {
            *loc = ptr;
            *par = save;
            return;
        }
        save = ptr;
        if (item < ptr->val) {
            ptr = ptr->left;
        } else {
            ptr = ptr->right;
        }
    }

    *loc = nullptr;
    *par = save;
}

Node* InsBST(Node* root, int item) {
    Node *loc, *par;
    Find(root, item, &loc, &par);

    if (loc != nullptr) return root;

    Node* newNode = new Node(item);

    if (par == nullptr) {
        root = newNode;
    } else if (item < par->val) {
        par->left = newNode;
    } else {
        par->right = newNode;
    }

    return root;
}

void PreOrder(Node* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(Node* root) {
    if (root == nullptr) return;
    InOrder(root->left);
    cout << root->val << " ";
    InOrder(root->right);
}

void PostOrder(Node* root) {
    if (root == nullptr) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->val << " ";
}

Node* CaseA(Node* root, Node* loc, Node* par) {
    Node* child = (loc->left == nullptr) ? loc->right : loc->left;

    if (par != nullptr) {
        if (loc == par->left) {
            par->left = child;
        } else {
            par->right = child;
        }
    } else {
        root = child;
    }

    return root;
}

Node* CaseB(Node* root, Node* loc, Node* par) {
    Node *ptr = loc->right, *save = loc;
    while (ptr->left != nullptr) {
        save = ptr;
        ptr = ptr->left;
    }

    Node* suc = ptr;
    Node* parSuc = save;

    root = CaseA(root, suc, parSuc);

    if (par != nullptr) {
        if (loc == par->left) {
            par->left = suc;
        } else {
            par->right = suc;
        }
    } else {
        root = suc;
    }

    suc->left = loc->left;
    suc->right = loc->right;

    return root;
}

Node* DelBST(Node* root, int item) {
    Node *loc, *par;
    Find(root, item, &loc, &par);

    if (loc == nullptr) {
        cout << "Item not found in the tree.\n";
        return root;
    }

    if (loc->left != nullptr && loc->right != nullptr) {
        root = CaseB(root, loc, par);
    } else {
        root = CaseA(root, loc, par);
    }

    delete loc;
    return root;
}

int main() {
    Node* root = nullptr;
    char op;
    int n, item;

    srand(time(nullptr));

    while (true) {
        cout << "\n1. Create a Binary Search Tree \n";
        cout << "2. Pre-order Traverse\n";
        cout << "3. In-order Traverse\n";
        cout << "4. Post-order Traverse\n";
        cout << "5. Delete an item from BST\n";
        cout << "0. Exit\nEnter your option: ";
        cin >> op;

        switch (op) {
        case '1':
            root = nullptr;
            cout << "How many numbers: ";
            cin >> n;
            cout << "Generated Numbers: ";
            while (n--) {
                item = rand() % 50 + 1;
                cout << item << " ";
                root = InsBST(root, item);
            }
            cout << endl;
            break;
        case '2':
            cout << "Pre-order Traversal: ";
            PreOrder(root);
            cout << endl;
            break;
        case '3':
            cout << "In-order Traversal: ";
            InOrder(root);
            cout << endl;
            break;
        case '4':
            cout << "Post-order Traversal: ";
            PostOrder(root);
            cout << endl;
            break;
        case '5':
            cout << "Enter an item to delete: ";
            cin >> item;
            root = DelBST(root, item);
            break;
        case '0':
            return 0;
        default:
            cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}